#include <iostream>

class myClass
{
    private:
        int m_value = 10;
    public:
        myClass() { m_value = 5;}//конструктор

        void print()             //ф-я вывода
        {
            std::cout << m_value << std::endl;
        }
        friend void reset(myClass &anything);
};

void reset(myClass &anything)    //дружественная ф-ия
{
    anything.m_value = 0;
}

int main(int argc, char const *argv[])
{
    myClass obj;
    obj.print();

    reset(obj);
    obj.print();

    return 0;
}
