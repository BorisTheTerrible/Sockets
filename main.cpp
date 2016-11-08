#include "UDPSocket.hpp"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <bitset>
#include <arpa/inet.h>

struct packet_message
{
    short command;
    char message[16];
};

using namespace std;

int main(int argumentCount, const char * arguments[])
{
    char type;
    
    cout << "Please enter  c  for client or a  s  for server" << endl;
    cin >> type;
    
    if(type != 'c' && type != 's')
    {
        cout << "Not recognized" << endl;
        return 1;
    }
    
    if(type == 'c')
    {
        packet_message packetMessage;
        packetMessage.command = 0;
        strncpy(packetMessage.message, "Ayyy Lmao", sizeof(packetMessage.message));
        
        UDPSocket senderSocket((char *)"127.0.0.1", 30001, AF_INET);
        
        printf("MSG: command=%i\n", packetMessage.command);
        senderSocket.send(& packetMessage, sizeof(packetMessage), (char *)"127.0.0.1", 30000, AF_INET);
    }
    else
    {
        UDPSocket receiverSocket((char *)"127.0.0.1", 30000, AF_INET);
        sockaddr_in * receivedAddress = new sockaddr_in;
        
        char buffer[256];
        
        for(int i = 0; i < 256; i++)
        {
            buffer[i] = 'a';
        }
        
        packet_message * packet;
        
        do
        {
            long length = receiverSocket.receive(buffer, 256, receivedAddress);
            char str[INET_ADDRSTRLEN];
            
            packet = (packet_message *)buffer;
            
            cout << "Command: " << packet->command << " Message: " << packet->message << endl;
            cout << "SenderIp: " << inet_ntop(AF_INET, & receivedAddress->sin_addr, str, INET_ADDRSTRLEN)
            << " SenderPort: " << ntohs(receivedAddress->sin_port) << endl;
        }
        while(packet->command != -1);
        
        delete receivedAddress;
    }
    
    return 0;
}

