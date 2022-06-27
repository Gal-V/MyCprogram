#include <iostream>
#include <string>
#include <map>
//#include <array>

using namespace std;

struct access_s     //структура доступа
{
    string id;
    map<string, string>* pointer;
};

void fillMap(map<string, map<string, string>>* myMap, access_s* access) 
{
    //string key1(access[0].id);
    //string key2(access[1].id);
    //string key3(access[2].id);
    
    //access[0].id = "K2";
    //(*myMap)[key1]["YID"] = "K1";
    /*(*myMap)[key1]["UAV"] = "K2";
    (*myMap)[key1]["RDV"] = "K3";
    (*myMap)[key2]["YID"] = "Z1";
    (*myMap)[key2]["UAV"] = "Z2";
    (*myMap)[key2]["RDV"] = "Z3";
    (*myMap)[key3]["YID"] = "B1";
    (*myMap)[key3]["UAV"] = "B2";
    (*myMap)[key3]["RDV"] = "B3";*/
    (*access[0].pointer)[access[0].id] = "K1";
    (*access[0].pointer)[access[1].id] = "K2";
    (*access[0].pointer)[access[2].id] = "K3";
    (*access[1].pointer)[access[0].id] = "Z1";
    (*access[1].pointer)[access[1].id] = "Z2";
    (*access[1].pointer)[access[2].id] = "Z3";
    (*access[2].pointer)[access[0].id] = "B1";
    (*access[2].pointer)[access[1].id] = "B2";
    (*access[2].pointer)[access[2].id] = "B3";
    
}

void printMap(map<string, map<string, string>> myMap)
{
    for(const auto& it : myMap)   //вывод external key 
    {
        cout << it.first  << " ";
        cout << endl;
        for(const auto& itt : myMap[it.first])   //вывод internal key contain
        {
            cout << itt.first <<  " " << itt.second <<  "\n";
        }
    }
    //auto it = *myMap.find("K");
    //cout << it->first <<endl; //key
    //cout << (*myMap)["K"]["YID"] << endl;
    /*
    cout << (*access[0].pointer)[access[0].id] << "\t";
    cout << (*access[0].pointer)[access[1].id] << "\t";
    cout << (*access[0].pointer)[access[2].id] << endl;
    cout << (*access[1].pointer)[access[0].id] << "\t";
    cout << (*access[1].pointer)[access[1].id] << "\t";
    cout << (*access[1].pointer)[access[2].id] << endl;
    cout << (*access[2].pointer)[access[0].id] << "\t";
    cout << (*access[2].pointer)[access[1].id] << "\t";
    cout << (*access[2].pointer)[access[2].id] << endl;
    */
    /*string key("K"); 
    auto it = external.find(key);
    if(it != external.end()) //проверка что эллемент существует
    {
        cout << it->first <<endl; //key
        //cout << it->second <<endl; //container
    }else
    {
        cout << "not find" << endl;
    }*/
}

int main()
{
    map<string, map<string, string>> external;  //карта с картой
    //external["K"]["YID"] = "space1";// [key | [key | kontain]]
    //заполнение карт
    external["K"]["YID"];   // first map
    external["K"]["UAV"];
    external["K"]["RDV"];
    external["Z"]["YID"];   // second map
    external["Z"]["UAV"];
    external["Z"]["RDV"];
    external["B"]["YID"]    ;// third map
    external["B"]["UAV"];
    external["B"]["RDV"];

    
    const int quantityMap(3);           //кол-во структур в массиве
    access_s access[quantityMap] = {};  //массив структур
    //access[0].id = "K";                 //идентификаторы
    //access[1].id = "Z";
    //access[2].id = "B";
    access[0].id = "YID";                 //идентификаторы
    access[1].id = "UAV";
    access[2].id = "RDV";
    access[0].pointer = &external["K"]; //адреса карт intern
    access[1].pointer = &external["Z"];
    access[2].pointer = &external["B"];

    fillMap(&external, access);         //заполнение карт &access[quantityMap]
    printMap(external);                 //вывод результатов

    return 0;
}