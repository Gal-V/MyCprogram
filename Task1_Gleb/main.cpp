#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Key
{
    string id;
    map<string,string> *ptr;
};

void fillMap(Key *arr)          //заполняем значения внутренней карты
{
    map <string,string> :: iterator itArr = arr->ptr->begin();
    /*
    for(int i = 0; itArr!=arr->ptr->end();i++,itArr++){
        for(int j = 1; itArr!=arr->ptr->end(); j++){
            itArr->second = (arr[i].id+to_string(j));
        }
    }
    */
    /*
     for(int j = 0; itArr!=arr->ptr->end(); j++,itArr++){
            itArr->second = (arr[j].id+to_string(j));
        }
        */
    itArr->second = "123";
}

int main()
{
    map <string,map <string,string>> Extern ;   //внешняя и внутрення карты 
    map <string,string> Intern;
    
    Intern = {  {"YID",""},
                {"UAV",""},
                {"RDV",""}};
    
    Extern.insert(pair<string,map<string,string>>("K", Intern));
    Extern.insert(pair<string,map<string,string>>("Z", Intern));
    Extern.insert(pair<string,map<string,string>>("B", Intern));

    const int SIZE = 3;
    Key arr[SIZE];      //Создаем массив для заполнения внутренней карты
    
    map <string,map <string,string>> :: iterator itExt = Extern.begin();
    
    
    for (int i = 0; itExt != Extern.end(); itExt++, i++)        //копируем ключи из внешней карты в массив
    {
        arr[i].id=itExt->first;
    }
    
    itExt = Extern.begin();
         
    for(int i = 0; itExt != Extern.end(); itExt++, i++)        //копируем указатели внутренней карты в массив 
    {
        arr[i].ptr = &itExt->second;
    }
    
    fillMap(arr);
    /*
    for(auto &el: Intern){
        cout<<el.second<<endl;    
    }
    */
    /*
    for(auto el : Extern)
    {
        cout<<el.first<<"\t";
        for(auto &it : Intern){
            cout<<it.first<<"\t"<<it.second<<endl;
        }
    }
    */
}