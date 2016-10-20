//
//  UDPSocket.cpp
//  Sockets
//
//  Description:
//
//  How To Use or protocal: Order of calls.... i.e., (c Create), init, create, send ...
//
//  Created by games on 6/2/16.
//  Copyright © 2016 games. All rights reserved.
//

#include "UDPSocket.hpp"

#include <string>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

//Sockaddr must be deleted
void * UDPSocket::getNewSockaddr_in(char bindIp[], char bindSocket[])
{
    sockaddr_in * Sockaddr = new sockaddr_in();
    
    Sockaddr->sin_family = AF_INET;//Sets the type of connection?
    Sockaddr->sin_port = atoi(bindSocket);//Sets the socket address
    inet_aton(bindIp, & Sockaddr->sin_addr);//Sets the ip address
    
    std::cout << Sockaddr->sin_port;
    std::cout << Sockaddr->sin_addr.s_addr;
    
    return Sockaddr;
}

UDPSocket::UDPSocket(char bindIp[], char bindSocket[])
{
    socketResult = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if(socketResult == -1)
    {
        perror("Exception: Cannot create socket\n");
        return;
    }
    
    printf("Created socket: socketresult=%d\n", socketResult);
    
    sockaddr_in * Sockaddr = (sockaddr_in *) getNewSockaddr_in(bindIp, bindSocket);
    
    int bindResult = bind(socketResult, (struct sockaddr *) Sockaddr, sizeof(* Sockaddr));
    
    if(bindResult == -1)
    {
        printf("Exception: Cannot bind address: bindIp=%s bindSocket=%s\n", bindIp, bindSocket);
        return;
    }
    
    printf("Binded address: bindResult=%i bindIp=%s bindSocket=%s\n", bindResult, bindIp, bindSocket);
    
    UDPSocket::Sockaddr = Sockaddr;
    
    UDPSocket::hasNoFailures = true;
}

UDPSocket::~UDPSocket()
{
    delete (sockaddr_in *)Sockaddr;
}

void UDPSocket::receive(void * receivedData, int receivedDataBytes)
{
    if(UDPSocket::hasNoFailures)
    {
        socklen_t sockaddrSize = sizeof(* ((sockaddr_in *) Sockaddr)
                                        );
    
        recvfrom(socketResult, & receivedData, receivedDataBytes, 0, (struct sockaddr *) Sockaddr, & sockaddrSize);
    }
    else
    {
        perror("Exception: Cannot receive from a socket that has failed to intialize properly!");
    }
}

void UDPSocket::send(void * dataToSend, int sentDataBytes, char receiverIp[], char receiverSocket[])
{
    if(UDPSocket::hasNoFailures)
    {
        sockaddr_in * receiverAddress = (sockaddr_in *) getNewSockaddr_in(receiverIp, receiverSocket);
    
        long sendResult = sendto(socketResult, dataToSend, sentDataBytes, 0, (sockaddr *)receiverAddress ,  sizeof(* receiverAddress));
    
        if(sendResult == -1)
        {
            printf("Exception: Cannot send to address: receiverIp=%s receiverSocket=%s\n", receiverIp, receiverSocket);
        }
    }
    else
    {
        perror("Exception: Cannot send from a socket that has failed to intialize properly!");
    }

}


