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
        UDPSocket(char * bindIp, short bindSocket, int networkFamily);
        ~UDPSocket();
        long receive(void * receivedData, int receivedDataBytes);
        void send(void * dataToSend, int sentDataBytes, char * receiverIp, short receiverSocket, int networkFamily);
    
    private:
        void * getNewSockaddr_in(char * bindIp, short bindSocket, int networkFamily);
        void convertFromNetworkToHostByteOrder(void * ptr, int numberOfBytes);
        void convertFromHostToNetworkByteOrder(void * ptr, int numberOfBytes);
        bool getIsBigEndian();
    
        bool hasNoFailures = false;
        int socketResult;
        int networkFamily;
        void * Sockaddr;
        static bool isBigEndian;
};

#endif /* UDPSocket_hpp */
