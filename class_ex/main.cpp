#include <iostream>

class Date
{
private:
    /* data */
public:
    int day;
    int month;
    int year;

    void print()
    {
        std::cout << day << " " << month << " "
        << year << std::endl;
    }
};


int main()
{
    Date today {2, 7, 2022};
    today.print();
    today.day++;
    today.print();
    return 0;
}
