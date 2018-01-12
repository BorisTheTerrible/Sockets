#include "UDPSocket.hpp"
#include "TCPListenerSocket.hpp"
#include "TCPConnection.hpp"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <bitset>
#include <arpa/inet.h>

#include <boost/filesystem.hpp>
#include <boost/asio.hpp>

void networkStuff();

int main(int argumentCount, const char * arguments[])
{
    //networkStuff();
    
    return 0;
}


struct packet_message
{
    int command;
    char message[16];
};

using namespace std;

void networkStuff()
{
    
}


