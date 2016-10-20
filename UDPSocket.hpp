//
//  UDPSocket.hpp
//  Sockets
//
//  Created by games on 6/2/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef UDPSocket_hpp
#define UDPSocket_hpp

class UDPSocket
{
    public:
        UDPSocket(char bindIp[], char bindSocket[]);
        ~UDPSocket();
        void receive(void * receivedData, int receivedDataBytes);
        void send(void * dataToSend, int sentDataBytes, char receiverIp[], char receiverSocket[]);
    
    private:
        void * getNewSockaddr_in(char bindIp[], char bindSocket[]);
        int socketResult;
        void * Sockaddr;
        bool hasNoFailures = false;
};

#endif /* UDPSocket_hpp */
