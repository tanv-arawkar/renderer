# Copyright (C) 2016-2024 NSEIT Limited, Mumbai, India. All rights
# reserved.
#
# This program and the accompanying materials are made available under
# the terms described in the LICENSE file which accompanies this
# distribution. If the LICENSE file was not attached to this
# distribution or for further clarifications, please contact
# legal@nseit.com.

include_directories (
	${PROTOBUF_INCLUDE_DIR}
)

include_directories ( ${PROJECT_BINARY_DIR}/src
	${PROJECT_SOURCE_DIR}/qamqp
)

PROTOBUF_GENERATE_CPP(
      PROTO_SRC
      PROTO_HEADER
      proto/data.proto
)

add_library (proto
	${PROTO_HEADER}
	${PROTO_SRC}
)

add_library (app
	app_impl.cxx

	renderer.h
	renderer_impl.h
	renderer_impl.cxx	

	message-queue-controller.h
)

target_link_libraries(app
  qamqp
  proto	  
  ${PROTOBUF_LIBRARIES}
  ${CMAKE_DL_LIBS}
  )
# target_compile_options(app
#   PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter)

add_executable (hallticket-renderer
  main.cxx
  )

target_link_libraries(hallticket-renderer
	app Qt6::Widgets Qt6::WebEngineWidgets Qt6::Pdf Qt6::Core
  )
# target_compile_options(sps-master
#   PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter)

install (TARGETS hallticket-renderer DESTINATION bin)
