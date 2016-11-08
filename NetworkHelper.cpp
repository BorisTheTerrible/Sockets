//
//  NetworkHelper.cpp
//  Sockets
//
//  Created by games on 10/31/16.
//  Copyright © 2016 games. All rights reserved.
//

#include "NetworkHelper.hpp"

#include <string>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool NetworkHelper::getIsBigEndian()
{
    union
    {
        unsigned int number;
        char characters[4];
    }
    unionCheck = {0x01020304};
    
    // Big Endian : 0000 0001 0000 0010 0000 0011 0000 0100
    // If first byte = 1, then it is big endian
    return unionCheck.characters[0] == 1;
}

//Sockaddr must be deleted
//Can return nullptr if it failed to create a valid sockaddr_in
void * NetworkHelper::getNewSockaddr_in(char * bindIp, short bindSocket, int networkFamily)
{
    //Sets endianness each time a new UDPSocket is instantiated.
    //Doesn't need  to be like that but its the easiest way
    NetworkHelper::isBigEndian = getIsBigEndian();
    
    sockaddr_in * Sockaddr = new sockaddr_in();
    
    if(networkFamily != AF_INET && networkFamily != AF_INET6)
    {
        printf("Exception: %i is an invalid network family\n", networkFamily);
        return NULL;
    }
    
    //Sets the type of connection
    Sockaddr->sin_family = networkFamily;
    //Converts socket from host to network order, Sets the socket
    Sockaddr->sin_port = htons(bindSocket);
    
    //Sets the ip address, Requires a null terminated string
    int conversionResult = inet_pton(AF_INET, bindIp, & Sockaddr->sin_addr);
    
    if(conversionResult == 0)
    {
        printf("Exception: Failed to convert %s into an integer\n", bindIp);
        return NULL;
    }
    
    //printf("loopy %i\n", htonl(INADDR_LOOPBACK));
    //std::cout << Sockaddr->sin_port << std::endl;
    //std::cout << Sockaddr->sin_addr.s_addr << std::endl;
    
    return Sockaddr;
}

void NetworkHelper::convertFromNetworkToHostByteOrder(void * ptr, int numberOfBytes)
{
    if(!NetworkHelper::isBigEndian)
    {
        char bytes[numberOfBytes];
        
        
    }
}

void NetworkHelper::convertFromHostToNetworkByteOrder(void * ptr, int numberOfBytes)
{
    
}