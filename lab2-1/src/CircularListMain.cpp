#include "CircularList.h"
#include <iostream>

using namespace ds_course;
using namespace std;

void INS(CircularList &cl, int pos, int num)
{
    if (pos > cl.getSize())
    {
        throw OutOfBoundsException("overflow");
    }
    for (int j = 0; j < pos; j++)
    {
        cl.advance(); 
    }
    cl.add(num);
    for (int j = 0; j < cl.getSize() - pos; j++)
    {
        cl.advance();
    }
}

void DEL(CircularList &cl, int pos)
{
    if (pos >= cl.getSize())
    {
        throw OutOfBoundsException("overflow");
    }
    for (int j = 0; j < pos; j++)
    {
        cl.advance();
    }
    cl.remove();
    for (int j = 0; j < cl.getSize() - pos; j++)
    {
        cl.advance();
    }
}

using namespace std;
int main()
{
    int N;
    cin >> N;
    CircularList cL;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        cL.add(num);
        cL.advance();
    }

    string type;
    int pos, nn;
    try
    {

        while (cin >> type)
        {
            if (type == "INS")
            {
                cin >> pos >> nn;
                INS(cL, pos, nn);
            }
            else if (type == "DEL")
            {
                cin >> pos;
                DEL(cL, pos);
            }
            else
            {
                cerr << "Unknown operation '" << type << "'" << endl;
            }
        }
        cout << cL.to_str() << endl;
    }
    catch (const OutOfBoundsException &e)
    {
        cout << "OutOfBoundsException";
    }
}
