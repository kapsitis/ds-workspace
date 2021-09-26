#include "CircularList.h"

using namespace ds_course;
using namespace std;
CircularList::CircularList()
{
    elts = new int[100];
    size = 0;
}

CircularList::~CircularList()
{
    delete[] elts;
}

bool CircularList::empty() const
{
    return size == 0;
}

const int &CircularList::back() const
{
    if (size == 0)
    {
        throw new OutOfBoundsException("underflow");
    }
    return elts[size - 1];
}

const int &CircularList::front() const
{
    if (size == 0)
    {
        throw new OutOfBoundsException("underflow");
    }
    return elts[0];
}

/**
 * "0 1 ^2" -> "1 2 ^0"
 */
void CircularList::advance()
{
    if (size > 0)
    {
        int temp = elts[0];
        for (int j = 0; j < size - 1; j++)
        {
            elts[j] = elts[j + 1];
        }
        elts[size - 1] = temp;
    }
}

/**
 * "0 1 ^2" -> "2 0 ^1"
 */
void CircularList::retreat()
{
    if (size > 0)
    {
        int temp = elts[size-1];
        for (int j = size-1; j >=1; j--)
        {
            elts[j] = elts[j -1];
        }
        elts[0] = temp;
    }
}


/**       
 *  "0  1  2  3  ^4" -> "5  0  1  2  3  ^4"
 */
void CircularList::add(const int &e)
{
    if (size == 100)
    {
        throw new OutOfBoundsException("overflow");
    }
    for (int j = size - 1; j >= 0; j--)
    {
        elts[j + 1] = elts[j];
    }
    elts[0] = e;
    size++;
}

/**       
 *  "0  1  2  3  ^4" -> "1  2  3  ^4"
 */
void CircularList::remove()
{
    if (size == 0)
    {
        throw new OutOfBoundsException("underflow");
    }
    for (int j = 0; j < size; j++)
    {
        elts[j] = elts[j + 1];
    }
    elts[size - 1] = 0;
    size--;
}

string CircularList::to_str()
{
    if (size == 0)
    {
        return "";
    }
    string sep = "";
    string result = "";
    // for (int j = size-1; j >=0; j--)
    // {
    //     result.append(sep);
    //     result.append(to_string(elts[j]));        
    //     sep = " ";
    // }

    for (int j = 0; j < size; j++)
    {
        result.append(sep);
        result.append(to_string(elts[j]));        
        sep = " ";
    }
    return result;
}

int CircularList::getSize()
{
    return size;
}
