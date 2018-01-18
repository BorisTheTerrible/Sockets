//
//  TCPConnection.hpp
//  Sockets
//
//  Created by games on 6/8/17.
//  Copyright © 2017 games. All rights reserved.
//

#ifndef TCPConnection_hpp
#define TCPConnection_hpp

#include <stdio.h>

struct sockaddr_in;

class TCPConnection
{
public:
    TCPConnection(int socketFileDesc, sockaddr_in * clientAddress);
    
    ~TCPConnection();
    
    /*
     0 is returned in the case that the socket is closed while blocking
     */
    long receiveData(void * receivedData, int receivedDataBytes);
    
    void sendData(void * dataToSend, int dataByteLength);
    
private:
    const int socketFileDesc;
    
    const sockaddr_in * clientAddress;
};

#endif /* TCPConnection_hpp */
