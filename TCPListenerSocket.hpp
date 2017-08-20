//
//  TCPListenerSocket.hpp
//  Sockets
//
//  Created by games on 6/8/17.
//  Copyright © 2017 games. All rights reserved.
//

#ifndef TCPListenerSocket_hpp
#define TCPListenerSocket_hpp

#include <stdio.h>

#include "Socket.hpp"

class TCPConnection;

class TCPListenerSocket : public Socket
{
public:
    TCPListenerSocket(char * bindIp, short bindSocket, int networkFamily, int backlog);
    TCPConnection * waitAndAccept();
    ~TCPListenerSocket();
};

#endif /* TCPListenerSocket_hpp */