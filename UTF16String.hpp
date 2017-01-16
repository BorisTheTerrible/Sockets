//
//  UTF16String.hpp
//  Sockets
//
//  Created by games on 12/5/16.
//  Copyright © 2016 games. All rights reserved.
//

#ifndef UTF16String_hpp
#define UTF16String_hpp

#include <stdio.h>
#include <string>
#include <Vector>

//Anything interacting with characters and strings sent by clients must use this

class UTF16String
{
    public:
        UTF16String();
        UTF16String(std::string stringToConvert);
        UTF16String(UTF16String const & stringToCopy);
        ~UTF16String();
        void append(std::string stringToAppend);
        void append(UTF16String stringToCopy);
        std::vector<char> getCopyOfBytesVector();
        unsigned long getLength();
    
    private:
        std::vector<char> * bytesVectorPtr;
};

#endif /* UTF16String_hpp */
