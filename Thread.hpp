//
//  Thread.hpp
//  Sockets
//
//  Created by games on 11/12/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef Thread_hpp
#define Thread_hpp

#include <stdio.h>

class Thread
{
    public:
        virtual void threadRun() = 0;
        virtual void socketRun() = 0;
};

#endif /* Thread_hpp */
