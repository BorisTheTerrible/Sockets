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
:
Socket(bindIp, bindSocket, networkFamily, SOCK_DGRAM)
{
    
}

long UDPSocket::receiveData(void * receivedData, int receivedDataBytes, sockaddr_in * senderAddress)
{
    if(getHasNoFailures())
    {
        socklen_t sockaddrSize = sizeof(* senderAddress);
    
        //The Sockaddr used in this is set to the address of the sender!
        //return how many bytes it has received
        long bytesReceived = recvfrom(getSocketResult(), receivedData, receivedDataBytes, 0, (struct sockaddr *) senderAddress, & sockaddrSize);
        
        return bytesReceived;
    }
    else
    {
        perror("Exception: Cannot receive from a socket that has failed to intialize properly!\n");
    }
    
    return -1;
}

void UDPSocket::sendData(void * dataToSend, int dataToSendBytes, char * receiverIp, short receiverSocket, int networkFamily)
{
    if(getHasNoFailures())
    {
        sockaddr_in * receiverAddress = getNewSockaddr_in(receiverIp, receiverSocket, networkFamily);
        
        if(!receiverAddress)
        {
            perror("Exception: Failed to create new sockaddr_in\n");
            return;
        }
    
        long sendResult = sendto(getSocketResult(), dataToSend, dataToSendBytes, 0, (sockaddr *)receiverAddress ,  sizeof(* receiverAddress));
    
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

