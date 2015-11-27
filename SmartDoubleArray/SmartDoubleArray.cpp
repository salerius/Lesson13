#include "SmartDoubleArray.h"
#include <iostream>
#include <string>

using namespace std;

namespace MyArray
{
    SmartDoubleArray::SmartDoubleArray()
    {
        capacity = 8;
        size = 0;
        chiefPointer = new int[capacity];
     }

    SmartDoubleArray::~SmartDoubleArray()
    {
        if (chiefPointer != nullptr)
            delete chiefPointer;
    }

    //add element to the end
    void SmartDoubleArray::add(int value)
    {
        int* tempArray = nullptr;
        if (size == capacity)
        {
            capacity *= 2;
            tempArray = new int[capacity];

            for (int i = 0; i < size; i++)
            {
                tempArray[i] = chiefPointer[i];
            }
            delete[] chiefPointer;
            chiefPointer = new int[capacity];

            for (int i = 0; i < size; i++)
            {
                chiefPointer[i] = tempArray[i];
            }
            delete[] tempArray;
        }
        chiefPointer[size] = value;
        size++;
    }

    // insert element after 'index'
    void SmartDoubleArray::insert(int value, int index)
    {
        if (!indexCheck(index))
            return;
        int* tempArray = nullptr;
        if (size == capacity)
        {
            capacity *= 2;
            tempArray = new int[capacity];
            for (int i = size; i >= 0; --i)
            {
                if (i > index + 1)
                {
                    tempArray[i] = chiefPointer[i - 1];
                    continue;
                }
                if (i == index + 1)
                {
                    tempArray[index + 1] = value;
                    continue;
                }
                tempArray[i] = chiefPointer[i];
            }
            chiefPointer = nullptr;
            chiefPointer = tempArray;
            delete[] tempArray;
        }
        else
        {
            for (int i = size; i > index + 1; --i)
            {
                chiefPointer[i] = chiefPointer[i - 1];
            }
            chiefPointer[index + 1] = value;
        }

        size++;
    }

    //remove element at 'index'
    void SmartDoubleArray::remove(int index)
    {
        if (!indexCheck(index))
            return;
        size--;
        int *tempArray = nullptr;
        tempArray = new int[capacity];

        for (int i = 0; i < index; i++)
        {
            tempArray[i] = chiefPointer[i];
        }
        for (int i = index; i < size; i++)
        {
            tempArray[i] = chiefPointer[i + 1];
        }
        delete[] chiefPointer;
        chiefPointer = tempArray;
    }

    // get count of some value in array
    int SmartDoubleArray::count(int value) const
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (chiefPointer[i] == value)
            {
                count++;
            }
        }
        return count;
    }

    //return index of next value occurrence starting from 
    //given index
    int SmartDoubleArray::findNext(int value, int index) const
    {
        if (!indexCheck(index))
            return -1;
        for (int i = index; i < size; i++)
        {
            if (chiefPointer[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    //get size array
    int SmartDoubleArray::getSize() const
    {
        return size;
    }

    //get size array
    int SmartDoubleArray::getCapacity() const
    {
        return capacity;
    }


    // Method for get the value of the index
    int SmartDoubleArray::getValueOfIndex(int index) const
    {
        if (!indexCheck(index))
            return 0;
        return chiefPointer[index];
    }
   
    //get element by index
    int SmartDoubleArray::getAt(int index) const
    {
        return getValueOfIndex(index);
    }

    //Override []
    int SmartDoubleArray::operator[](int index)
    {
        return getValueOfIndex(index);
    }

    bool SmartDoubleArray::indexCheck(int index) const
    {
         return !(index >= size || index < 0);
    }

    std::ostream& operator<<(std::ostream& os, const SmartDoubleArray& chiefPointer)
    {
        for (int i = 0; i < chiefPointer.size; i++)
        {
             os << chiefPointer.getValueOfIndex(i)<<" ";
        }
         return os;
    }   
}