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

Socket::Socket(char * bindIp, short bindSocket, int networkFamily, int networkType, int networkProtocal) : hasNoFailures(false)
{
    socketFileDesc = socket(networkFamily, networkType, networkProtocal);
    
    if(socketFileDesc == -1)
    {
        perror("Exception: Cannot create socket\n");
        return;
    }
    
    printf("Created socket: socketFileDesc=%d\n", socketFileDesc);
    
    sockaddr_in * bindAddress = Socket::getNewSockaddr_in(bindIp, bindSocket, networkFamily);
    
    //Checks if socketAddress is null
    if(!bindAddress)
    {
        perror("Exception: Failed to create new sockaddr_in\n");
        return;
    }
    
    int bindResult = bind(socketFileDesc, (sockaddr *) bindAddress, sizeof(* bindAddress));
    
    if(bindResult == -1)
    {
        printf("Exception: Cannot bind address: bindIp=%s bindSocket=%hd\n", bindIp, bindSocket);
        perror(nullptr);
        return;
    }
    
    printf("Binded address: bindResult=%i bindIp=%s bindSocket=%hd\n", bindResult, bindIp, bindSocket);
    
    Socket::bindAddress = bindAddress;
    
    Socket::hasNoFailures = true;
}

Socket::~Socket()
{
    delete (sockaddr_in *)bindAddress;
    
    close(socketFileDesc);
}

bool Socket::getHasNoFailures()
{
    return hasNoFailures;
}

void Socket::setAsFailed()
{
    hasNoFailures = false;
}

int Socket::getSocketFileDescriptor()
{
    return socketFileDesc;
}

const sockaddr_in * Socket::getBindAddress()
{
    return bindAddress;
}

//Sockaddr must be deallocated
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