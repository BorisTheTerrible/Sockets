//
//  NetworkHelper.hpp
//  Sockets
//
//  Created by games on 10/31/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef NetworkHelper_hpp
#define NetworkHelper_hpp

#include <stdio.h>

class NetworkHelper
{
    public:
        static bool getIsBigEndian();
        static void * getNewSockaddr_in(char * bindIp, short bindSocket, int networkFamily);
        static void convertFromNetworkToHostByteOrder(void * ptr, int numberOfBytes);
        static void convertFromHostToNetworkByteOrder(void * ptr, int numberOfBytes);
    
    private:
        static bool isBigEndian;
};

#endif /* NetworkHelper_hpp */
