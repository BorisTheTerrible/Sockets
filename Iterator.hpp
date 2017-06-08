//
//  Iterator.hpp
//  Sockets
//
//  Created by games on 5/23/17.
//  Copyright © 2017 games. All rights reserved.
//

#ifndef Iterator_hpp
#define Iterator_hpp

#include <stdio.h>

template <typename T>
class Iterator
{
public:
    Iterator(LinkedList<T> & linkedListRef) : currentIndex(0), linkedListRef(linkedListRef)
    {
        linkedListRef
    }
    bool hasNext()
    {
        if(currentIndex < length - 1)
        {
            return true;
        }
        
        return false;
    }
    T getNextElement()
    {
        return linkedListRef.getElementAt(++currentIndex);
    }
    
private:
    currentIndex;
    LinkedList & linkedListRef;
};

#endif /* Iterator_hpp */
