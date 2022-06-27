#include <iostream>
#include <string>
#include <map>
#include <array>

using namespace std;

void printMap(map<string, map<string, string>>* myMap)
{
    //auto it = *myMap.find("K");
    //cout << it->first <<endl; //key
    cout << (*myMap)["K"]["UAV"] << endl;
}

struct access_s     //структура доступа
{
    string id;
    map<string, string>* pointer;
};

void fillMap(map<string, map<string, string>>* myMap, access_s* access) 
{
    string key1(access[0].id);
    string key2(access[1].id);
    string key3(access[2].id);
    
    //access[0].id = "K2";
    (*myMap)[key1]["YID"] = "K1";
    (*myMap)[key1]["UAV"] = "K2";
    (*myMap)[key1]["RDV"] = "K3";
    (*myMap)[key2]["YID"] = "Z1";
    (*myMap)[key2]["UAV"] = "Z2";
    (*myMap)[key2]["RDV"] = "Z3";
    (*myMap)[key3]["YID"] = "B1";
    (*myMap)[key3]["UAV"] = "B2";
    (*myMap)[key3]["RDV"] = "B3";
    
}

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

    /*string key("K"); 
    auto it = external.find(key);
    if(it != external.end()) //проверка что эллемент существует
    {
        cout << it->first <<endl; //key
        //cout << it->second <<endl; //container
        cout << external[key]["UAV"] << endl; //container
    }else
    {
        cout << "not find" << endl;
    }*/
    const int quantityMap(3);           //кол-во структур в массиве
    access_s access[quantityMap] = {};  //массив структур
    access[0].id = "K";                 //индефикаторы
    access[1].id = "Z";
    access[2].id = "B";
    access[0].pointer = &external["K"]; //адреса карт intern
    access[1].pointer = &external["Z"];
    access[2].pointer = &external["B"];

    fillMap(&external, access);        // &access[quantityMap]
    printMap(&external);
    cout << "end" << endl;
    return 0;
}