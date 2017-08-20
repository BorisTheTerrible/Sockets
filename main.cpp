#include "UDPSocket.hpp"
#include "LinkedList.hpp"
#include "TCPListenerSocket.hpp"
#include "TCPConnection.hpp"
#include "Logger.hpp"

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
    int command;
    char message[16];
};

using namespace std;

void networkStuff();

int main(int argumentCount, const char * arguments[])
{
    Logger::intialize(FINE);
    
    return 0;
}

void networkStuff()
{
    ///*
    if (htonl(47) == 47)
    {
        cout << "Big endian" << endl;
    }
    else
    {
        cout << "Little Endian" << endl;
    }
    
    
    char type;
    
    cout << "Please enter  c  for client or a  s  for server" << endl;
    cin >> type;
    
    if(type != 'c' && type != 's' && type != 'x')
    {
        cout << "Not recognized" << endl;
    }
    
    if(type == 'c') //Client - sender
    {
        packet_message packetMessage;
        
        packetMessage.command = 0;
        strncpy(packetMessage.message, "Ayyy Lmao", sizeof(packetMessage.message));
        
        UDPSocket senderSocket((char *)"127.0.0.1", 30001, AF_INET);
        
        printf("MSG: command=%i\n", packetMessage.command);
        senderSocket.sendData(& packetMessage, sizeof(packetMessage), (char *)"127.0.0.1", 30000, AF_INET);
    }
    else if(type == 's') //Server - receiver
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
            long length = receiverSocket.receiveData(buffer, 256, receivedAddress);
            char str[INET_ADDRSTRLEN];
            
            packet = (packet_message *)buffer;
            
            bitset<32> bits(packet->command);
            cout << bits << endl;
            
            cout << "Command: " << packet->command << " Message: " << packet->message << endl;
            cout << "SenderIp: " << inet_ntop(AF_INET, & receivedAddress->sin_addr, str, INET_ADDRSTRLEN)
            << " SenderPort: " << ntohs(receivedAddress->sin_port) << endl;
        }
        while(packet->command != -1);
        
        delete receivedAddress;
    }
    else if(type == 'x')
    {
        TCPListenerSocket tcpSocket((char *)"127.0.0.1", 30000, AF_INET, 10);
        
        TCPConnection * tcpConnection = tcpSocket.waitAndAccept();
        
        char buffer[256];
        
        for(int i = 0; i < 256; i++)
        {
            buffer[i] = 'z';
        }
        
        long length = tcpConnection->receiveData(buffer, 256);
        
        packet_message * packet;
        
        char str[INET_ADDRSTRLEN];
        
        packet = (packet_message *)buffer;
        
        cout << "Command: " << packet->command << " Message: " << packet->message << endl;
        
        delete tcpConnection;
    }
    //*/
}


