//
//  ByteOrder.hpp
//  Sockets
//
//  Created by games on 10/28/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef ByteOrder_hpp
#define ByteOrder_hpp

#include <stdio.h>

class ByteOrder
{
    public:
    static bool getIsBigEndian();
    
    private:
    static bool isBigEndian;
};

#endif /* ByteOrder_hpp */
