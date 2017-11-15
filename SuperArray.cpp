// File: SuperArray
// Created by Hugo Valle on 10/31/2017.
// Copyright (c) 2017 WSU
//

#include "SuperArray.h"
#include <cstring>
/*!
 * Constructor
 * @param begIndex: user's low index
 * @param capacity: maximum array capacity
 */
SuperArray::SuperArray(const int begIndex, const unsigned int capacity)
{
    /* This is declaring a local variable, if you have data member
     * called int* arr, the code on line ## will NOT refer to the data
     * member, instead you created a second arr pointer, and this
     * second pointer dies and is lost forever when the constructor ends
     */
    arr = new int[capacity];
    SuperArray::capacity = capacity;
    SuperArray::lowIndex = begIndex;
    SuperArray::highIndex = begIndex + (capacity-1);
}
/*!
 * Class Destructor
 */
SuperArray::~SuperArray()
{
    delete[] arr;
}
/*!
 * Convert int array to string.
 * Note: You do not need to modify this function
 * @param obj Instance of SuperArray to convert to string
 * @return string form of array
 */
string arrayToString(const SuperArray& obj)
{
    stringstream ss;
    cout << "Inside String"<< endl;
    for (int i = 0; i < obj.capacity; i++)
    {
        //cout << obj.arr[i] << " i " << i<<endl;
        ss << obj.arr[i] << " ";
        cout << obj.arr[i]<<" ";
    }
    string str = ss.str();
    size_t found;
    found = str.find_last_not_of(" ");
    if (found != string::npos)
        str.erase(found + 1);
    else
        str.clear();            // str is all whitespace

    return str;
}
/*!
 * Index operator overload
 * @param index: user's index notation
 * @return: actual index notation
 */
int &SuperArray::operator[](const int index)
{

    if(index < lowIndex)
    {
        throw("Invalid index request, too low");
    }
    else if(index > highIndex)
    {
        throw("Invalid index request, too high");
    }
    // index conversion
    int realIndex = index - lowIndex;

    return arr[realIndex];
}
/*!
 * Get low index of array
 * @return: low index
 */
int SuperArray::getLowIndex() const
{
    return lowIndex;
}
/*!
 * Get high index of array
 * @return: high index
 */
int SuperArray::getHighIndex() const
{
    return highIndex;
}
/*!
 * Get capacity of array
 * @return: capacity
 */
unsigned int SuperArray::length() const
{
    return capacity;
}
/*!
 * Resize array to new capacity and beginning index
 * @param begIndex: begindex of array
 * @param capacity: capacity of array
 */
void SuperArray::resize(const int begIndex, const unsigned int capacity)
{
    SuperArray  temp(begIndex,capacity);
    int numIndex;
    if(lowIndex > begIndex)
        numIndex = abs(lowIndex - begIndex);
    else
        numIndex = 0;
    cout << "Array Maybe " << capacity<<endl;

    for(int i = (numIndex+begIndex); i < (capacity+begIndex); i++)
    {
        temp[i] = arr[i-(numIndex+begIndex)];

    }

    delete [] arr;

    SuperArray::capacity = capacity;
    SuperArray::lowIndex = begIndex;
    SuperArray::highIndex = (capacity+begIndex)-1;
    arr = temp.arr;

    for (int i = 0; i < capacity; ++i) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    //Change where temp.arr points to
    temp.arr = NULL;
}
