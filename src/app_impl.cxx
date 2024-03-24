/* Copyright (C) 2016-2024 NSEIT Limited, Mumbai, India. All rights
 * reserved.
 *
 * This program and the accompanying materials are made available
 * under the terms described in the LICENSE file which accompanies
 * this distribution. If the LICENSE file was not attached to this
 * distribution or for further clarifications, please contact
 * legal@nseit.com. */

#include <iostream>

#include "app_impl.h"

void AppImpl::start(void) {
  std::cout << "in app start\n";
  build();

  m_mq_controller->start();
  // std::cout << m.file_name;
  // std::cout << m.data;
}

bool AppImpl::build(void) {
  std::cout << "Building\n";

  m_mq_controller = std::make_unique<MessageQueueController>();

  return true;
}

/*
  Local Variables:
  mode: c++
  End:
*/
