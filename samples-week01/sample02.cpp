#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
    string line;
    getline(cin,line);
    stringstream lineStream(line);
    int num = 0, total = 0;
    while (lineStream >> num && num > 0) {
        total += num; 
    }
    cout << "Total is " << total << endl;
    return 0;
}
