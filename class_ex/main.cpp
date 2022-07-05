#include <iostream>

class Date
{
private:
    /* data */
public:
    int day;
    int month;
    int year;

    Date(int day = 11,int month = 11,int year = 2011)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
/*     Date()
    {
        day = 11;
        month = 11;
        year = 2011;
    } */

    void print()
    {
        std::cout << day << " " << month << " "
        << year << std::endl;
    }
};


int main()
{
    Date today (2, 7, 2022);
    today.print();
    today.day++;
    today.print();
    Date defdate;
    defdate.print();
    return 0;
}
