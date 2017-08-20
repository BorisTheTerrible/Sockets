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
#include <netinet/in.h>

//struct sockaddr_in;

class Socket
{
    protected:
        Socket(char * bindIp, short bindSocket, int networkFamily, int networkType, int networkProtocal);
        ~Socket();
        sockaddr_in * getNewSockaddr_in(char * bindIp, short bindSocket, int networkFamily);
        bool getHasNoFailures();
        void setAsFailed();
        int getSocketFileDescriptor();
        int getNetworkFamily();
        const sockaddr_in * getBindAddress();
    
    private:
        int socketFileDesc;
        sockaddr_in * bindAddress;
        bool hasNoFailures;
};

#endif /* Socket_hpp */
