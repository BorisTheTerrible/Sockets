//
//  EnvironmentChecks.cpp
//  Sockets
//
//  Created by games on 1/17/18.
//  Copyright © 2018 games. All rights reserved.
//

#include "EnvironmentChecks.hpp"

int EnvironmentChecks::dummyVariable = runtimeMethod();

bool EnvironmentChecks::isBigEndian = false;

bool EnvironmentChecks::getIsBigEndian()
{
    return isBigEndian;
}

/*
    Runtime checks should be placed in here.
    Runtime environment variables should be set in here.
 */
int EnvironmentChecks::runtimeMethod()
{
    if(htonl(47) == 47)
    {
        EnvironmentChecks::isBigEndian = true;
    }
    else
    {
        EnvironmentChecks::isBigEndian = false;
    }
    
    return 0;
}
