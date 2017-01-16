//
//  UTF16String.cpp
//  Sockets
//
//  Created by games on 12/5/16.
//  Copyright © 2016 games. All rights reserved.
//

//Anything interacting with characters and strings sent by clients must use this

#include "UTF16String.hpp"

UTF16String::UTF16String()
{
    
}

UTF16String::UTF16String(std::string stringToConvert)
{
    //Normal char size = 1, multiple this by four to get
    int length = stringToConvert.length() * 4;
}

UTF16String::UTF16String(UTF16String const & stringToCopy)
{
    
}

void UTF16String::append(std::string stringToAppend)
{
    
    
}
void UTF16String::append(UTF16String stringToCopy)
{
    
}

std::vector<char> UTF16String::getCopyOfBytesVector()
{
    return * bytesVectorPtr;
}

unsigned long UTF16String::getLength()
{
    return bytesVectorPtr->size();
}

UTF16String::~UTF16String()
{
    delete bytesVectorPtr;
}