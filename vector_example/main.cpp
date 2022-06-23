#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> myVec { 12, 10, 8, 6, 4, 2, 1 };
    //cout << "The length is: " << myVec.size() << endl;
    myVec.push_back(2);
    myVec.push_back(22);

    for (int i = 0; i < myVec.size(); i++)
    {
        cout << myVec[i] << " ";
        //cout << myVec.at(i) << " ";     //проверка но медленее
    }
    myVec.pop_back();                     //удаление последнего эл
    cout << endl;
    for (int i = 0; i < myVec.size(); i++)
    {
        cout << myVec[i] << " ";
        //cout << myVec.at(i) << " ";     //проверка но медленее
    }
}