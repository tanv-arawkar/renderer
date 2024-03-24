/* Copyright (C) 2016-2024 NSEIT Limited, Mumbai, India. All rights
 * reserved.
 *
 * This program and the accompanying materials are made available
 * under the terms described in the LICENSE file which accompanies
 * this distribution. If the LICENSE file was not attached to this
 * distribution or for further clarifications, please contact
 * legal@nseit.com. */

#ifndef NSEIT_SPS_MASTER__6bc0a420_e746_11ee_9752_6110ec75ad20
#define NSEIT_SPS_MASTER__6bc0a420_e746_11ee_9752_6110ec75ad20

#include <memory>

#include "app.h"
#include "message-queue-controller.h"

class AppImpl : public App {
public:
  AppImpl() {}

  ~AppImpl() {}

  void start(void);

private:
  bool build(void);

private:
  std::unique_ptr<MessageQueueController> m_mq_controller;
};
#endif // NSEIT_SPS_MASTER__6bc0a420_e746_11ee_9752_6110ec75ad20

/*
  Local Variables:
  mode: c++
  End:
*/
