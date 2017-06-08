//
//  LinkedList.hpp
//  Sockets
//
//  Created by games on 5/9/17.
//  Copyright © 2017 games. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <string>
#include <iostream>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        Node(int index, T * element)
        {
            this->index = index;
            this->element = element;
            
            nextNode = nullptr;
        }
        
        int index;
        T * element;
        Node * nextNode;
    };
    
    public:
    LinkedList() : length(0)
        {
        
        }
        T * getElementAt(int indexToGet)
        {
            return getNodeAt(indexToGet)->element;
        }
    int getIndexOfElement(T * element)
    {
        
    }
        T * replaceAt(int index, T * element)
        {
            Node * node = getNodeAt(index);
        
            T * oldElement = node->element;
        
            node->element = element;
        
            //Returns pointer to old element for deallocation purposes if needed
            return oldElement;
        }
        //
        void add(T * element)
        {
            //If the length is zero, create and add the first node
            if(length == 0)
            {
                firstNode = new Node(0, element);
                
                length = 1;
                
                return;
            }
            
            //Get the last node of the list
            Node * lastNode = getNodeAt(length - 1);
        
            //Create a new node to add to the end
            Node * newNode = new Node(++length - 1, element);
        
            //Sets the new node as the next node of the last node
            lastNode->nextNode = newNode;
        }
        int getLength()
        {
            return length;
        
        }
         /*
    Iterator * getNewIterator()
    {
        
    }
         */
    static void createAndPrintTestCase()
    {
        LinkedList<int> ints;
        
        std::cout << ints.getLength() << std::endl;
        
        std::cout << "---------" << std::endl;
        
        ints.add(new int(0));
        
        std::cout << ints.getLength() << std::endl;
        
        std::cout << * ints.getElementAt(0) << std::endl;
        
        std::cout << "---------" << std::endl;
        
        ints.add(new int(1));
        
        std::cout << ints.getLength() << std::endl;
        
        std::cout << * ints.getElementAt(1) << std::endl;
        
        std::cout << "---------" << std::endl;
        
        ints.add(new int(2));
        
        std::cout << ints.getLength() << std::endl;
        
        std::cout << * ints.getElementAt(2) << std::endl;
        
        std::cout << "---------" << std::endl;
        
        ints.replaceAt(1, new int(1337));
        
        std::cout << ints.getLength() << std::endl;
        
        std::cout << * ints.getElementAt(1) << std::endl;
        
        std::cout << "---------" << std::endl;
        
        ints.replaceAt(1, new int(69));
        
        std::cout << ints.getLength() << std::endl;
        
        std::cout << * ints.getElementAt(1) << std::endl;
        
        std::cout << "---------" << std::endl;
        
        ints.replaceAt(0, new int(-69));
        
        std::cout << ints.getLength() << std::endl;
        
        std::cout << * ints.getElementAt(0) << std::endl;
        
        std::cout << * ints.getElementAt(1) << std::endl;
        
        std::cout << * ints.getElementAt(2) << std::endl;
        
        std::cout << "---------" << std::endl;
        
        ints.add(new int(3));
        
        std::cout << ints.getLength() << std::endl;
        
        std::cout << * ints.getElementAt(0) << std::endl;
        
        std::cout << * ints.getElementAt(1) << std::endl;
        
        std::cout << * ints.getElementAt(2) << std::endl;
        
        std::cout << * ints.getElementAt(3) << std::endl;
        
        std::cout << "---------" << std::endl;
    }
    
    private:
        Node * getNodeOfElement(T * element)
    {
        
    }
        Node * getNodeAt(int indexToGet)
        {
            if(indexToGet > length - 1)
            {
                throw std::out_of_range("Attempted to access LinkedList at an index larger than is contained!");
            }
            else if(indexToGet < 0)
            {
                throw std::out_of_range("Attempted to access LinkedList at an index smaller than 0!");
            }
        
            Node * currentNode = firstNode;
        
            //Iterates through the list until it gets to the appropriate node
            for(int currentIndex = 0; currentIndex < indexToGet; currentIndex++)
            {
                currentNode = currentNode->nextNode;
            }
        
            return currentNode;
        }
    
        //Indexing and length works the same way an array does
        //Ex: length of five, last element has index of 4
        int length;
        Node * firstNode;
    
    friend class Iterator;
};

#endif /* LinkedList_hpp */
