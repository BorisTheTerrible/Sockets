//
//  Buffer.hpp
//  Sockets
//
//  Created by games on 1/11/18.
//  Copyright © 2018 games. All rights reserved.
//

#ifndef Buffer_hpp
#define Buffer_hpp

class Buffer
{
public:
    Buffer(int totalSize);
    
    Buffer(char * byteArray, int byteArraySize);
    
    Buffer(char * byteArray, int byteArraySize, int totalSize);
    
    int getTotalSize();
    
    int getCurrentSize();
    
    void add(char * byteArray, int byteArraySize);
    
    char * getByteArray();
//public
    
private:
    int totalSize;
    
    int currentSize;
    
    char byteArray[];
//private
};

#endif /* Buffer_hpp */
