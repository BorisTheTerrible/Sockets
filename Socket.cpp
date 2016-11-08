//
//  Socket.cpp
//  Sockets
//
//  Created by games on 10/31/16.
//  Copyright © 2016 games. All rights reserved.
//

#include "Socket.hpp"

#include <string>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

Socket::Socket(char * bindIp, short bindSocket, int networkFamily) : hasNoFailures(false)
{
    socketResult = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if(socketResult == -1)
    {
        perror("Exception: Cannot create socket\n");
        return;
    }
    
    printf("Created socket: socketresult=%d\n", socketResult);
    
    sockaddr_in * socketAddress = Socket::getNewSockaddr_in(bindIp, bindSocket, networkFamily);
    
    if(!socketAddress)
    {
        perror("Exception: Failed to create new sockaddr_in\n");
        return;
    }
    
    int bindResult = bind(socketResult, (sockaddr *) socketAddress, sizeof(* socketAddress));
    
    if(bindResult == -1)
    {
        printf("Exception: Cannot bind address: bindIp=%s bindSocket=%hd\n", bindIp, bindSocket);
        return;
    }
    
    printf("Binded address: bindResult=%i bindIp=%s bindSocket=%hd\n", bindResult, bindIp, bindSocket);
    
    Socket::socketAddress = socketAddress;
    
    Socket::hasNoFailures = true;
}

Socket::~Socket()
{
    delete (sockaddr_in *)socketAddress;
    
    close(socketResult);
}

bool Socket::getHasNoFailures()
{
    return hasNoFailures;
}

void Socket::setAsFailed()
{
    hasNoFailures = false;
}

int Socket::getSocketResult()
{
    return socketResult;
}

int Socket::getNetworkFamily()
{
    return networkFamily;
}

const sockaddr_in * Socket::getSocketAddress()
{
    return socketAddress;
}

//Sockaddr must be deleted
//Can return nullptr if it failed to create a valid sockaddr_in
sockaddr_in * Socket::getNewSockaddr_in(char * bindIp, short bindSocket, int networkFamily)
{
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