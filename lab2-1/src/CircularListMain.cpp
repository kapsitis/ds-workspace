#include "CircularList.h"
#include <iostream>

using namespace ds_course;
using namespace std;

int main() {
     cout << "Hello from CircularListMain" << endl;
     CircularList myList; 
     // initialize with at least 2 elements
     myList.pushFront(2);
     myList.pushFront(3);
     myList.pushFront(4);
     myList.pushFront(5);
     myList.head() = 17;
     myList.tail() = 18;
     // The following line should return "[17, 4, 3, 18]": 
     cout << myList.toString();
}
