#include <iostream>
#include <array>
#include <algorithm>
int main()
{
    std::array<int, 4> maArray {1, 2, 3, 4};
    maArray.at(0) = 5; //присваинвание с проверкой диапозона
    std::cout << maArray.size() << std::endl;
    std::sort(maArray.begin(), maArray.end());
    for (auto &i : maArray)
    {
        std::cout << i << " ";
    }
    
    return 0;
}
