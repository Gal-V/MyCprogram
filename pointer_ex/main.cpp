#include <iostream>
using namespace std;

int main()
{
    int myValue = 1;
    cout << myValue << endl;
    int *p_myValue = &myValue;

    cout << p_myValue << endl;
    *p_myValue = 5;

    cout << myValue << endl;
    cout << *p_myValue << endl;

    cout << &myValue << endl;
    cout << p_myValue << endl;
    return 0;
}