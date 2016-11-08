//
//  UDPSocket.hpp
//  Sockets
//
//  Created by games on 6/2/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef UDPSocket_hpp
#define UDPSocket_hpp

#include "Socket.hpp"

class UDPSocket : public Socket
{
    public:
        UDPSocket(char * bindIp, short bindSocket, int networkFamily);
        long receive(void * receivedData, int receivedDataBytes, sockaddr_in * senderAddress);
        void send(void * dataToSend, int sentDataBytes, char * receiverIp, short receiverSocket, int networkFamily);
};

#endif /* UDPSocket_hpp */
