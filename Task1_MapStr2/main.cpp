#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
const int symbols = 26;

struct access_s     //структура доступа
{
    string id;
    map<string, string>* pointer;
};

//заполнение карты значениями 
void fillMap(map<string, map<string, string>>* myMap, access_s* access, array<string, 78> fill);
//вывод на экран карты
void printMap(map<string, map<string, string>> &myMap);


int main()
{
    int test;
                                                //ключи external map
    array<string, 26> alfabit = {"A","B","C","D","E","F","G","H",
                                "I","J","K","L","M","N","O","P",
                                "Q","R","S","T","U","V","W","X","Y","Z"};
    array<string, 78> alfabit_with_num;         //значения second internal map
    for (int i = 0, j = 0, a = 1; i < 78; i++, a++)
    {
        alfabit_with_num[i] = alfabit[j] + to_string(a);
        if (a == 3)
        {
            a = 0;
            j++;
        }
    }
     
    map<string, map<string, string>> external;  //карта с картой
    map <string,string> internal;
    internal = {{"YID", ""}, {"UAV", ""}, {"RDV", ""}};
    
    for (int i = 0; i < symbols; i++)           //заполнение external карты
    {
        external.insert(pair<string,map<string,string>>(alfabit[i], internal));
    }
    
    access_s access[symbols] = {};              //массив структур

    
    int a = 0;                                  //заполнение указателей структуры
    for(map<string, map<string, string>>::iterator it = external.begin(); it != external.end(); ++it, ++a) 
    {
        access[a].pointer = &external[it->first];
        // cout << "Key: " << access[a].id<<endl;
    }
    a = 0;                                      //заполнение id структуры
    for (map <string,string>::iterator it = internal.begin(); it != internal.end(); ++it, ++a)
    {
        access[a].id = it->first; 
        // cout << it->first;
    }
    
    fillMap(&external, access, alfabit_with_num);         //заполнение карт &access[quantityMap]
    printMap(external);                                   //вывод результатов

    // cin >> test;
    return 0;
}


void fillMap(map<string, map<string, string>>* myMap, access_s* access, array<string, 78> fill) 
{   
    for (int i = 0; i < symbols; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            (*access[i].pointer)[access[j].id] = fill[i];
        }
        
    }
    
}

void printMap(map<string, map<string, string>> &myMap)
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