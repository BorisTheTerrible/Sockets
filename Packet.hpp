//
//  Packet.hpp
//  Sockets
//
//  Created by games on 11/12/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef Packet_hpp
#define Packet_hpp

#include <string>

static_assert(sizeof(bool) == 1, "bool is not one byte!");
static_assert(sizeof(char) == 1, "char is not one byte!");
static_assert(sizeof(short) == 2,  "short is not two bytes!");
static_assert(sizeof(int) == 4, "int is not four bytes!");
static_assert(sizeof(long) == 8, "long is not eight bytes!");
static_assert(sizeof(float) == 4, "float is not four bytes!");
static_assert(sizeof(double) == 8, "double is not eight bytes!");

/*
    All packets must have:
        Constructor that accepts byteBuffer and size.
        Constructor that accepts the contents of that packet.
        method getByteArray() that returns the contents of that packet in a byteBuffer.
 */
struct Packet
{
public:
    /*
        Must return a byte buffer with the packetID and size as the first four bytes,
        and have the packet contents written to the rest of the buffer.
     */
    virtual char * getByteArray();
    
    /*
        Returns a pointer to the newly intialized packet based off of the packetID.
     */
    static Packet * getPacket(char * buffer, int size);
//public
};

struct HandshakePacket : public Packet
{
public:
    HandshakePacket(char * byteArray, int size);
    
    HandshakePacket(short uniqueID, bool isBigEndian);
    
    char * getByteArray();
//public
    
private:
    short uniqueID;
    
    /*
        Used when receiving this packet.
     */
    char username[24];
    
    /*
        Used when sending out this packet.
     */
    bool isBigEndian;
//private
};

#endif /* Packet_hpp */
