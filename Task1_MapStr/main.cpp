#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, map<string, string>> external;
    external["K"]["YID"] = "space1";// key key kontain
    external["K"]["UAV"] = "space2";
    external["K"]["RDV"] = "space3";
    //external.emplace("K", make_pair("YID", "myItem1"));
    //cout << external["value"] << endl;
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

    return 0;
}