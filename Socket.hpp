//
//  Socket.hpp
//  Sockets
//
//  Created by games on 10/31/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef Socket_hpp
#define Socket_hpp

#include <stdio.h>

#include <arpa/inet.h>

class Socket
{
    protected:
        Socket(char * bindIp, short bindSocket, int networkFamily, int networkType, int networkProtocal);
        ~Socket();
        sockaddr_in * getNewSockaddr_in(char * bindIp, short bindSocket, int networkFamily);
        bool getHasNoFailures();
        void setAsFailed();
        int getSocketResult();
        int getNetworkFamily();
        const sockaddr_in * getSocketAddress();
    
    private:
        int socketResult;
        int networkFamily;
        sockaddr_in * socketAddress;
        bool hasNoFailures;
};

#endif /* Socket_hpp */
