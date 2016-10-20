#include "UDPSocket.hpp"
#include <stdio.h>
#include <string.h>
#include <iostream>

struct packet_message
{
    short command;
    char message[16];
};

using namespace std;

int main()
{
    /*
    unsigned int i = 1;
    char *c = (char*)&i;
    
    if (*c)
        printf("Little endian");
    else
        printf("Big endian");
    
    return 0;
    */
    
    /*
    packet_message packetMessage;
    packetMessage.command = 0;
    strncpy(packetMessage.message, "Ayyy Lmao", sizeof(packetMessage.message));
    
    UDPSocket senderSocket(0,0);
    
    printf("MSG: command=%i\n", packetMessage.command);
    senderSocket.send(&packetMessage, 2130706433, 30000);
    */
    
    return 0;
}

