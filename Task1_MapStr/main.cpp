#include <iostream>
#include <string>
#include <map>

using namespace std;

struct access_s     //структура доступа
{
    string id;
    map<string, string>* pointer;
};

//заполнение карты значениями 
void fillMap(map<string, map<string, string>>* myMap, access_s* access);
//вывод на экран карты
void printMap(map<string, map<string, string>> myMap);


int main()
{
    map<string, map<string, string>> external;  //карта с картой
    //заполнение карт
    external["K"]["YID"];   // first map
    external["K"]["UAV"];
    external["K"]["RDV"];
    external["Z"]["YID"];   // second map
    external["Z"]["UAV"];
    external["Z"]["RDV"];
    external["B"]["YID"];   // third map
    external["B"]["UAV"];
    external["B"]["RDV"];

    
    const int quantityMap(3);           //кол-во структур в массиве
    access_s access[quantityMap] = {};  //массив структур

    access[0].id = "YID";               //идентификаторы
    access[1].id = "UAV";
    access[2].id = "RDV";
    access[0].pointer = &external["K"]; //адреса карт intern
    access[1].pointer = &external["Z"];
    access[2].pointer = &external["B"];

    fillMap(&external, access);         //заполнение карт &access[quantityMap]
    printMap(external);                 //вывод результатов

    return 0;
}

void fillMap(map<string, map<string, string>>* myMap, access_s* access) 
{   
    (*access[0].pointer)[access[0].id] = "K1";
    (*access[0].pointer)[access[1].id] = "K2";
    (*access[0].pointer)[access[2].id] = "K3";
    (*access[1].pointer)[access[0].id] = "Z1";
    (*access[1].pointer)[access[1].id] = "Z2";
    (*access[1].pointer)[access[2].id] = "Z3";
    (*access[2].pointer)[access[0].id] = "B1";
    (*access[2].pointer)[access[1].id] = "B2";
    (*access[2].pointer)[access[2].id] = "B3";
    //cout << (*access[2].pointer)[access[2].id];
    
}

void printMap(map<string, map<string, string>> myMap)
{
    for(const auto& it : myMap)                  //вывод external key 
    {
        cout << it.first  << " ";
        cout << endl;
        for(const auto& itt : myMap[it.first])   //вывод internal key contain
        {
            cout << itt.first <<  " " << itt.second <<  "\n";
        }
    }

}