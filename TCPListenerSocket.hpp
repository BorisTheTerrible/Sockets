//
//  TCPListenerSocket.hpp
//  Sockets
//
//  Created by games on 12/14/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef TCPListenerSocket_hpp
#define TCPListenerSocket_hpp

#include <stdio.h>
#include "TCPSocket.hpp"

class TCPListenerSocket
:
public TCPSocket
{
public:
    void listen();
    //This method is blocking
    //This returns the file descriptor for the new connection
    //That then is used to instantiate a new TCPConnection
    int waitAndAcceptNewConnection();
};

#endif /* TCPListenerSocket_hpp */
