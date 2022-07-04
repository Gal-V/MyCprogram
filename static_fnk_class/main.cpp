#include <iostream>
using namespace std;

class foo
{
private:
    int a = 3;
    int b = 2;
public:
    void print() const
    {
        cout << a << endl;
        cout << b << endl;
    }
};



int main(int argc, char const *argv[])
{
    foo f;
    f.print();
    return 0;
}
