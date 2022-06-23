#include <iostream>
#include <string>
#include <map>

#include <typeinfo>
using namespace std;

int main()
{
    /*пары
    pair<int, string> p(1, "myItem1");
    cout << p.first << endl;
    cout << p.second << endl;
    */
    map<int, string> myMap;
    myMap.insert(make_pair(1, "myItem1"));
    myMap.insert(pair<int, string>(2, "myItem2"));
    myMap.emplace(3, "myItem3");
    myMap[1] = "myItem11"; //запись либо добавление
    myMap.at(1) = "myItem";//только изменение, не добавляет
    int key;    //вводим ключ
    cin >> key;
    auto it = myMap.find(key);
    if(it != myMap.end()) //проверка что эллемент существует
    {
        cout << it->first <<endl; //key
        cout << it->second <<endl; //container
        cout << myMap[key] << endl; //container
        //cout << typeid(it).name() << endl;
    }else
    {
        cout << "not find" << endl;
    }
    myMap.erase(3); //удаление по ключу
    return 0;
}
