//
//  LinkedListValue.h
//  Topic A
//
//  Created by user on 9/1/15.
//  Copyright (c) 2015 Ben Dahl. All rights reserved.
//

#ifndef __Topic_A__LinkedListValue__
#define __Topic_A__LinkedListValue__

#include <stdio.h>
#include "LinkedList.h"






// Class Definition
//-----------------

template<class ItemType>
class LinkedListValue : public LinkedList<ItemType> {
    
private:
    int search(const ItemType& value); // returns position of search value, if DNE then 0
    
public:
    LinkedListValue();
    LinkedListValue(const LinkedListValue<ItemType>& aListV);
    LinkedListValue(const LinkedList<ItemType>& aListV);
    LinkedListValue<ItemType>& operator= (const LinkedListValue<ItemType>& aListV);
    ~LinkedListValue();
    
    void display();
    void find(const ItemType& entry);
    bool insert(const ItemType& newEntry);
    bool remove(const ItemType& entry);
    bool setValue(const ItemType& value, const ItemType& newValue );
    void setEntry() = delete; // prevent client access
};







// Implementations
//----------------

template<class ItemType>
LinkedListValue<ItemType>::LinkedListValue()
: LinkedList<ItemType>()
{
} // End defualt constructor

template<class ItemType>
LinkedListValue<ItemType>::LinkedListValue(const LinkedListValue<ItemType>& aListV)
: LinkedList<ItemType>(aListV)
{
    
} // End copy constructor

template<class ItemType>
LinkedListValue<ItemType>::LinkedListValue(const LinkedList<ItemType>& aListV)
: LinkedList<ItemType>(aListV)
{
    
} // End copy LinkedList constructor

template<class ItemType>
LinkedListValue<ItemType>& LinkedListValue<ItemType>::operator= (const LinkedListValue<ItemType>& aListV)
{
    // Explicitly calling LinkedList assignment operator to handle operations
    LinkedList<ItemType>::operator=(aListV); // This is ok. Right? 
    
    return *this;
} // End assignment operator

template<class ItemType>
LinkedListValue<ItemType>::~LinkedListValue()
{
    
} // End destructor




template<class ItemType>
void LinkedListValue<ItemType>::display()
{
    cout << "There are " << this->getLength() << " values in the list:" << endl;
    for (int i = 1; i <= this->getLength(); i++) {
        cout << this->getEntry(i) << endl;
    }
    cout << endl;
}

template<class ItemType>
void LinkedListValue<ItemType>::find(const ItemType& entry)
{
    int pos = this->search(entry);
    if (pos) {
        cout << "The value " << entry << " was found in position " << pos << " and is the following:" << endl;
        cout << this->getEntry(pos);
    }
    
}

template<class ItemType>
bool LinkedListValue<ItemType>::insert(const ItemType& newEntry)
{
    int position = this->getLength() + 1;
    this->LinkedList<ItemType>::insert(position, newEntry);
    return true;
}

template<class ItemType>
bool LinkedListValue<ItemType>::remove(const ItemType& entry)
{
    int pos = this->search(entry);
    if (pos) {
        LinkedList<ItemType>::remove(pos);
        cout << entry << " was removed\n" << endl;
        return 1;
    } else {
        cout << entry << " was not removed\n" << endl;
        return 0;
    }
}



template<class ItemType>
int LinkedListValue<ItemType>::search(const ItemType& value)
{
    for (int pos = 1;pos <= this->getLength(); pos++) {
        if (this->getEntry(pos) == value) {
            return pos;
        }
    }
    return 0;
}

#endif /* defined(__Topic_A__LinkedListValue__) */
