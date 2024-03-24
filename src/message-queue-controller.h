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
#include "message-data.h"

class MessageQueueController : public QObject {
  Q_OBJECT
public:
  MessageQueueController(QObject *parent = 0) : QObject(parent), m_queue(0) {}
  ~MessageQueueController() {}

public Q_SLOTS:
  void start(void) {
    std::cout << "start called\n";
    connect(&m_client, SIGNAL(connected()), this, SLOT(client_connected()));
    m_client.connectToHost("amqp://guest:guest@localhost:5672/");
  }

private Q_SLOTS:
  void client_connected(void) {
    m_queue = m_client.createQueue("workqueue");
    connect(m_queue, SIGNAL(declared()), this, SLOT(queue_declared()));
    m_queue->declare();
    std::cout << " [*] Waiting for messages. To exit press CTRL+C\n";
  }

  void queue_declared(void) {
    std::cout << "\n\nnqueue declare called\n";
    m_queue->consume();
    connect(m_queue, SIGNAL(messageReceived()), this,
            SLOT(fetch_data_from_mq()));
  }

  struct message_data_s fetch_data_from_mq(void) {
    std::cout << "fetch data from mq called\n";
    m_current_message = m_queue->dequeue();

    std::cout << "Got message\n\n\n" << m_current_message.payload().data();

    //  QByteArray qdata;
    html::Data d;

    auto b = d.ParseFromArray(m_current_message.payload().data(),
                              m_current_message.payload().size());

    std::cout << d.filename() << "\n\n\n" << d.filedata() << "\n\n\n";
    return (message_data_s{d.filename(), d.filedata()});
  }

private:
  QAmqpClient m_client;
  QAmqpQueue *m_queue;
  QAmqpMessage m_current_message;
};

#endif // NSEIT_AVIAL__d963b76e_e74c_11ee_9752_6110ec75ad20

/*
  Local Variables:
  mode: c++
  End:
*/
