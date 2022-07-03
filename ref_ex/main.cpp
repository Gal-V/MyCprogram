#include <iostream>

void foo(int &x)
{
    x++;
}

int main()
{
    int myValue = 10;
    
    for (int i = 0; i < 10; i++)
    {
        foo(myValue);
        std::cout << myValue << std::endl;
    }
    
    return 0;
}
