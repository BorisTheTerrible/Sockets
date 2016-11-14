//
//  UnixThread.hpp
//  Sockets
//
//  Created by games on 11/12/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef UnixThread_hpp
#define UnixThread_hpp

//Only compiles this class if its on unix
#if defined(__APPLE__) || defined(__linux__) || defined(unix)

#include "Thread.hpp"

class UnixThread : Thread
{
    
};

#endif

#include <stdio.h>

#endif /* UnixThread_hpp */
