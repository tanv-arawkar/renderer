/* Copyright (C) 2016-2024 NSEIT Limited, Mumbai, India. All rights
 * reserved.
 *
 * This program and the accompanying materials are made available
 * under the terms described in the LICENSE file which accompanies
 * this distribution. If the LICENSE file was not attached to this
 * distribution or for further clarifications, please contact
 * legal@nseit.com. */

#ifndef NSEIT_AVIAL__d963b76e_e74c_11ee_9752_6110ec75ad20
#define NSEIT_AVIAL__d963b76e_e74c_11ee_9752_6110ec75ad20

#include <QCoreApplication>
#include <QDebug>

#include "qamqpclient.h"
#include "qamqpqueue.h"

#include "data.pb.h"

class MessageQueueController : public QObject {
  Q_OBJECT
public:
  MessageQueueController(QObject *parent = 0) : QObject(parent), m_queue(0) {}
  ~MessageQueueController() {}

public Q_SLOTS:
  void start(void) {
    connect(&m_client, SIGNAL(connected()), this, SLOT(client_connected()));
    m_client.connectToHost("amqp://guest:guest@localhost:5672/");
  }

private Q_SLOTS:
  void client_connected(void) {
    m_queue = m_client.createQueue("workqueue");
    connect(m_queue, SIGNAL(declared()), this, SLOT(queue_declared()));
    m_queue->declare(true);
    std::cout << " [*] Waiting for messages. To exit press CTRL+C\n";
  }

  void queue_declared(void) {
    m_queue->consume();
    connect(m_queue, SIGNAL(messageReceived()), this,
            SLOT(fetch_data_from_mq()));
  }

  void fetch_data_from_mq(void) {
    auto current_message = m_queue->dequeue();

    QByteArray qdata = current_message.payload().data();
    html::Data d;

    auto bret = d.ParseFromArray(qdata.data(), qdata.size());
    if (bret == false) {
      // TODO parsing failed.
      return;
    }
    // TODO call got_data
    return;
  }

private:
  QAmqpClient m_client;
  QAmqpQueue *m_queue;
};

#endif // NSEIT_AVIAL__d963b76e_e74c_11ee_9752_6110ec75ad20

/*
  Local Variables:
  mode: c++
  End:
*/
