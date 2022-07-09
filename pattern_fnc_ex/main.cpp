#include <iostream>

template <typename T>
const T& max(const T& a,const T& b)     //через константные ссылки чтобы  не копировать
{
    return (a>b) ? a:b;
}

int main(int argc, char const *argv[])
{
    std::cout<<max(9.6,5.9)<<std::endl;

    return 0;
}
