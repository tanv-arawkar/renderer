# Copyright (C) 2016-2024 NSEIT Limited, Mumbai, India. All rights
# reserved.
#
# This program and the accompanying materials are made available under
# the terms described in the LICENSE file which accompanies this
# distribution. If the LICENSE file was not attached to this
# distribution or for further clarifications, please contact
# legal@nseit.com.


add_library (qamqp STATIC 
	qamqpauthenticator.cpp  
	qamqpchannel.h        
	qamqpchannel_p.h  
	qamqpclient_p.h    
	qamqpexchange_p.h  
	qamqpglobal.h     
	qamqpmessage_p.h  
	qamqpqueue_p.h
	qamqpauthenticator.h    
	qamqpchannelhash.cpp  
	qamqpclient.cpp   
	qamqpexchange.cpp  
	qamqpframe.cpp     
	qamqpmessage.cpp  
	qamqpqueue.cpp    
	qamqptable.cpp 
	qamqpchannel.cpp        
	qamqpchannelhash_p.h  
	qamqpclient.h     
	qamqpexchange.h    
	qamqpframe_p.h     
	qamqpmessage.h    
	qamqpqueue.h      
	qamqptable.h
)


target_link_libraries(qamqp
	Qt6::Network
	Qt6::Core
)

