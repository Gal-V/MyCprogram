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

    access_s access[3] = {};


    return 0;
}