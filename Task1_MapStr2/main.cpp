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
void fillMap(map<string, map<string, string>>* myMap, access_s* access);
//вывод на экран карты
void printMap(map<string, map<string, string>> &myMap);


int main()
{
    int test;

    array<string, 26> alfabit = {"A","B","C","D","E","F","G","H",
                                "I","J","K","L","M","N","O","P",
                                "Q","R","S","T","U","V","W","X","Y","Z"}; 
    map<string, map<string, string>> external;  //карта с картой
    map <string,string> internal;
    internal = {{"YID", ""}, {"UAV", ""}, {"RDV", ""}};
    
    for (int i = 0; i < symbols; i++)           //заполнение внешней карты
    {
        external.insert(pair<string,map<string,string>>(alfabit[i], internal));
    }
    
    access_s access[symbols] = {};  //массив структур

    int a = 0;
    for(map<string, map<string, string>>::iterator it = external.begin(); it != external.end(); ++it, ++a) 
    {
        access[a].id = it->first;
        cout << "Key: " << access[a].id<<endl;
    }

}
