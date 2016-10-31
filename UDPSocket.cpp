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
#include <unistd.h>

//TODO: check and convert for byte order
//TODO: add windows and winsock support

UDPSocket::UDPSocket(char * bindIp, short bindSocket, int networkFamily)
{
    socketResult = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if(socketResult == -1)
    {
        perror("Exception: Cannot create socket\n");
        return;
    }
    
    printf("Created socket: socketresult=%d\n", socketResult);
    
    sockaddr_in * Sockaddr = (sockaddr_in *) getNewSockaddr_in(bindIp, bindSocket, networkFamily);
    
    if(!Sockaddr)
    {
        perror("Exception: Failed to create new sockaddr_in\n");
        return;
    }
    
    int bindResult = bind(socketResult, (struct sockaddr *) Sockaddr, sizeof(* Sockaddr));
    
    if(bindResult == -1)
    {
        printf("Exception: Cannot bind address: bindIp=%s bindSocket=%hd\n", bindIp, bindSocket);
        return;
    }
    
    printf("Binded address: bindResult=%i bindIp=%s bindSocket=%hd\n", bindResult, bindIp, bindSocket);
    
    UDPSocket::Sockaddr = Sockaddr;
    
    UDPSocket::hasNoFailures = true;
}

UDPSocket::~UDPSocket()
{
    delete (sockaddr_in *)Sockaddr;
    
    close(socketResult);
}

long UDPSocket::receive(void * receivedData, int receivedDataBytes)
{
    if(UDPSocket::hasNoFailures)
    {
        socklen_t sockaddrSize = sizeof(* ((sockaddr_in *) Sockaddr));
    
        //return how many bytes it has received
        long bytesReceived = recvfrom(socketResult, receivedData, receivedDataBytes, 0, (struct sockaddr *) Sockaddr, & sockaddrSize);
        
        return bytesReceived;
    }
    else
    {
        perror("Exception: Cannot receive from a socket that has failed to intialize properly!\n");
    }
    
    return -1;
}

void UDPSocket::send(void * dataToSend, int dataToSendBytes, char * receiverIp, short receiverSocket, int networkFamily)
{
    if(UDPSocket::hasNoFailures)
    {
        sockaddr_in * receiverAddress = (sockaddr_in *) getNewSockaddr_in(receiverIp, receiverSocket, networkFamily);
        
        if(!receiverAddress)
        {
            perror("Exception: Failed to create new sockaddr_in\n");
            return;
        }
    
        long sendResult = sendto(socketResult, dataToSend, dataToSendBytes, 0, (sockaddr *)receiverAddress ,  sizeof(* receiverAddress));
    
        if(sendResult == (long)-1)
        {
            printf("Exception: Cannot send to address: receiverIp=%s receiverSocket=%hd\n", receiverIp, receiverSocket);
        }
        
        delete receiverAddress;
    }
    else
    {
        perror("Exception: Cannot send from a socket that has failed to intialize properly!\n");
    }

}

//Sockaddr must be deleted
//Can return nullptr if it failed to create a valid sockaddr_in
void * UDPSocket::getNewSockaddr_in(char * bindIp, short bindSocket, int networkFamily)
{
    //Sets endianness each time a new UDPSocket is instantiated.
    //Doesn't need  to be like that but its the easiest way
    UDPSocket::isBigEndian = getIsBigEndian();
    
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

void UDPSocket::convertFromNetworkToHostByteOrder(void * ptr, int numberOfBytes)
{
    if(!UDPSocket::isBigEndian)
    {
        char bytes[numberOfBytes];
        
        
    }
}

void UDPSocket::convertFromHostToNetworkByteOrder(void * ptr, int numberOfBytes)
{
    
}

