//
//  TCPListenerSocket.cpp
//  Sockets
//
//  Created by games on 6/8/17.
//  Copyright © 2017 games. All rights reserved.
//

#include "TCPListenerSocket.hpp"

#include "TCPConnection.hpp"

#include <string>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

TCPListenerSocket::TCPListenerSocket(char * bindIp, short bindSocket, int networkFamily, int backlog)
:
Socket(bindIp, bindSocket, networkFamily, SOCK_STREAM, IPPROTO_TCP)
{
    int result = listen(getSocketFileDescriptor(), backlog);
    
    if(result == -1)
    {
        perror("Exception: cannot listen!");
    }
}

TCPListenerSocket::~TCPListenerSocket()
{
    
}

TCPConnection * TCPListenerSocket::waitAndAccept()
{
    sockaddr_in * clientAddress = new sockaddr_in;
    socklen_t size = sizeof(* clientAddress);

    int newFileDesc = accept(getSocketFileDescriptor(), (sockaddr *) clientAddress, & size);
    
    return new TCPConnection(newFileDesc, clientAddress);
}

