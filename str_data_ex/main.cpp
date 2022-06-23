#include <cstring> // для функции std::strlen()
#include <iostream>
#include <string_view>

int main()
{
    std::string_view str{ "balloon" };

    std::cout << str << '\n';

    //Для простоты мы воспользуемся функцией std::strlen(). Вместо нее можно
    //было бы использовать любую другую функцию, которая работает со строкой с нультерминатором в конце.
    //Здесь мы можем использовать функцию data(), так как мы не изменяли
    //представление и строка имеет нуль-терминатор
    std::cout << std::strlen(str.data()) << '\n';
    return 0;
}