//
//  TCPSocket.cpp
//  Sockets
//
//  Created by games on 11/12/16.
//  Copyright © 2016 games. All rights reserved.
//

#include "TCPSocket.hpp"

TCPSocket::TCPSocket(char * bindIp, short bindSocket, int networkFamily)
:
Socket(bindIp, bindSocket, networkFamily, SOCK_STREAM, IPPROTO_TCP)
{
    //This makes sure that either accept or connect has been succesfully been called
    hasConnected = false;
}

long TCPSocket::receiveData(void * receivedData, int receivedDataBytes)
{
    if(hasConnected)
    {
        //Last value is integer used for flags
        long dataByteLength = recv(getSocketResult(), receivedData, receivedDataBytes, 0);
        return dataByteLength;
    }
    else
    {
        perror("TCPSocket cannot receiveData because hasConnected = false!");
        return -1;
    }
}

void TCPSocket::sendData(void * dataToSend, int dataByteLength)
{
    if(hasConnected)
    {
        //Last value is integer used for flags
        send(getSocketResult(), dataToSend, dataByteLength, 0);
    }
    else
    {
        perror("TCPSocket cannot sendData because hasConnected = false!");
    }
}