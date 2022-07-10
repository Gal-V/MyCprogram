#include <iostream>
#include <exception>
#include <string>

using namespace std;
void foo(int a)
{
    if(a<0)
    {
        throw exception();//сюда можно передавать сообщение
    }
    std::cout<< "Hi"<<std::endl;
}

int main(int argc, char const *argv[])
{

    try
    {
        foo(-9);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
