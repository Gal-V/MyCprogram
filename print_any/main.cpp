#include <iostream>

void printAnyInt(const int &a)
{
    std::cout << a <<std::endl;
}
void printInt(int a)
{
    std::cout << a <<std::endl;
}
void printIntRef(int &a)
{
    std::cout << a <<std::endl;
}

int main()
{
    const int x = 10;
    printAnyInt(x);
    int y = 15;
    printAnyInt(y);

    printInt(x);
    printInt(y);

    //printIntRef(x); //так нельзя
    printIntRef(y);
    return 0;
}