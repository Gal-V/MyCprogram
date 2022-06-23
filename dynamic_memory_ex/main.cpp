#include <iostream>

using namespace std;
int main()
{   
    // инициализируем динамический
    int *array = new int[5] { 9, 7, 5, 3, 1 }; 

    array[1] = 2;
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
    //cout << sizeof(array)/sizeof(array[0]) << endl;
    // используем оператор delete[] для освобождения
    // выделенной массиву памяти
    delete[] array;
    array = 0; // nullptr

    return 0;
}