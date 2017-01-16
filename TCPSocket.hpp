//
//  TCPSocket.hpp
//  Sockets
//
//  Created by games on 11/12/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef TCPSocket_hpp
#define TCPSocket_hpp

#include <stdio.h>
#include "Socket.hpp"

class TCPSocket : public Socket
{
    protected:
        TCPSocket(char * bindIp, short bindSocket, int networkFamily);
        //This makes sure that either accept or connect has been succesfully been called
        bool hasConnected;
    public:
        long receiveData(void * receivedData, int receivedDataBytes);
        void sendData(void * dataToSend, int dataByteLength);
        bool getHasConnected();
};

#endif /* TCPSocket_hpp */
