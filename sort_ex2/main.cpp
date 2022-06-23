#include <iostream>
#include <algorithm> // для std::swap. В C++11 используйте заголовок <utility>

int main()
{
    const int length = 5;
    int array[length] = {20, 10, 50, 30, 40};

    std::sort(array, array+length);
    
    for (int i = 0; i < length; i++)
    {
        std::cout << array[i] << ' ';
    }
    
    return 0;
}