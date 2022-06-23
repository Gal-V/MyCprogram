#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main()
{
    int b(5);
    bool a;
    cout << b/2 << endl;
    cout << static_cast<double>(b)/3 << endl;
    cout << sizeof(b/2) << endl;
    cout << double(b)/2 << endl;
    cout <<(static_cast<double>(b)/3 == 5.0/3) << endl;    
    
    bitset<8> mybits;
    cout << mybits << endl;
    mybits.set(3);
    cout << mybits << endl;

    
        
}