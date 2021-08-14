#include <iostream>

using namespace std;
int main()
{
    int n = 0;
    cout << "Enter the count of numbers: " << endl;
    cin >> n; 
    cout << "Enter " << n << " integers: " << endl; 
    int total = 0; 
    for (int i = 0; i < n; i++) {
        int num; 
        cin >> num; 
        total += num;
    }
    cout << "The total of " << n << " numbers is " << total << endl;
    return 0;
}
