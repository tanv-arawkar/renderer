# Copyright (C) 2016-2022 NSEIT Limited, Mumbai, India. All rights
# reserved.
#
# This program and the accompanying materials are made available under
# the terms described in the LICENSE file which accompanies this
# distribution. If the LICENSE file was not attached to this
# distribution or for further clarifications, please contact
# legal@nseit.com.

cmake_minimum_required (VERSION 3.0)
project (hallticket_generator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets WebEngineWidgets Pdf Network Core)
#find_package(Qt5 REQUIRED COMPONENTS )

set (Boost_USE_STATIC_LIBS ON)
find_package (Boost REQUIRED COMPONENTS
  log log_setup thread date_time system filesystem program_options random)

#find_package(Qt5
#	REQUIRED COMPONENTS
#	Core Gui Network Widgets Multimedia MultimediaWidgets)

find_package (Protobuf REQUIRED)

add_subdirectory (qamqp)
add_subdirectory (src)
