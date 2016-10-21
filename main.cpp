#include "UDPSocket.hpp"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>

struct packet_message
{
    short command;
    char message[16];
};

using namespace std;

int main()
{
    packet_message packetMessage;
    packetMessage.command = 69;
    strncpy(packetMessage.message, "Ayyy Lmao", sizeof(packetMessage.message));
    
    UDPSocket senderSocket((char *)"127.0.0.1", 30001, AF_INET);
    
    printf("MSG: command=%i\n", packetMessage.command);
    senderSocket.send(& packetMessage, sizeof(packetMessage), (char *)"127.0.0.1", 30000, AF_INET);
    
    return 0;
}

