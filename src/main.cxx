/* Copyright (C) 2016-2022 NSEIT Limited, Mumbai, India. All rights
 * reserved.
 *
 * This program and the accompanying materials are made available
 * under the terms described in the LICENSE file which accompanies
 * this distribution. If the LICENSE file was not attached to this
 * distribution or for further clarifications, please contact
 * legal@nseit.com. */

#include <iostream>
#include <memory>

#include "app_impl.h"

int main(int argc, char **argv) {

  std::cout << "I am in main";
  QCoreApplication q_app(argc, argv);

  auto app = std::make_unique<AppImpl>();
  app->start();

  return q_app.exec();
}

/*
  Local Variables:
  mode: c++
  End:
*/
