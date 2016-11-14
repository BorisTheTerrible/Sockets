#include "UDPSocket.hpp"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <bitset>
#include <arpa/inet.h>

//Compiling on Unix(Mac and Linux included), so Pthread should be defined
#if defined(__APPLE__) || defined(__linux__) || defined(unix)

//Compiling on Window, so use windows specific threads
#elif defined(_WIN32)

//Compiling on unknown platform
#else
    #warning "Compiling on unknown platform."
#endif

struct packet_message
{
    //short command;
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

        //packetMessage.command = 0;
        strncpy(packetMessage.message, "Ayyy Lmao", sizeof(packetMessage.message));
        
        UDPSocket senderSocket((char *)"127.0.0.1", 30001, AF_INET);
        
        //printf("MSG: command=%i\n", packetMessage.command);
        senderSocket.send(& packetMessage, sizeof(packetMessage), (char *)"127.0.0.1", 30000, AF_INET);
    }
    else
    {
        UDPSocket receiverSocket((char *)"127.0.0.1", 30000, AF_INET);
        sockaddr_in * receivedAddress = new sockaddr_in;
        
        char buffer[256];
        
        for(int i = 0; i < 256; i++)
        {
            buffer[i] = 'z';
        }
        
        packet_message * packet;
        
        do
        {
            long length = receiverSocket.receive(buffer, 256, receivedAddress);
            char str[INET_ADDRSTRLEN];
            
            packet = (packet_message *)buffer;
            
            // << packet->command
            cout << "Command: " << " Message: " << packet->message << endl;
            cout << "SenderIp: " << inet_ntop(AF_INET, & receivedAddress->sin_addr, str, INET_ADDRSTRLEN)
            << " SenderPort: " << ntohs(receivedAddress->sin_port) << endl;
        }
        while(true);//packet->command != -1
        
        delete receivedAddress;
    }
    
    return 0;
}

