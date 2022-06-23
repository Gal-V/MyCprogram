#include <iostream>
#include <string>
#include <map>

using namespace std;

struct access_s     //структура доступа
{
    string id;
    map<string, string>* pointer;
};

int main()
{
    map<string, map<string, string>> external;  //карта с картой
    //external["K"]["YID"] = "space1";// [key | [key | kontain]]
    external["K"]["YID"];   // first map
    external["K"]["UAV"];
    external["K"]["RDV"];
    external["Z"]["YID"];   // second map
    external["Z"]["UAV"];
    external["Z"]["RDV"];
    external["B"]["YID"]    ;// third map
    external["B"]["UAV"];
    external["B"]["RDV"];

    string key("K"); 
    auto it = external.find(key);
    if(it != external.end()) //проверка что эллемент существует
    {
        cout << it->first <<endl; //key
        //cout << it->second <<endl; //container
        cout << external[key]["UAV"] << endl; //container
    }else
    {
        cout << "not find" << endl;
    }
    const int quantityMap(3);           //кол-во структур в массиве
    access_s access[quantityMap] = {};  //массив структур
    access[0].id = "K";
    access[1].id = "Z";
    access[2].id = "B";
    //access[0].pointer = (*external)["K"];

    return 0;
}