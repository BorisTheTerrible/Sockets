//
//  ByteOrder.cpp
//  Sockets
//
//  Created by games on 10/28/16.
//  Copyright © 2016 games. All rights reserved.
//

#include "ByteOrder.hpp"

bool ByteOrder::getIsBigEndian()
{
    union
    {
        unsigned int number;
        char characters[4];
    }
    unionCheck = {0x01020304};
    
    // Big Endian : 0000 0001 0000 0010 0000 0011 0000 0100
    // If first byte = 1, then it is big endian
    return unionCheck.characters[0] == 1;
}