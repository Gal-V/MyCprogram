#include <iostream>
#include <vector>
#include <cstdio>   //для гетчара

using namespace std;

class Users
{
private:
    int m_id;   //id пользователя
    int m_root; //его права доступа, предполагается ввод допустим от 1 до 3х но мне было лень ограничивать
public:
    Users(int root = 0): m_root(root), m_id(getId())    //конструктор со списком инициализации
    {                                                   //реализация мб не самая классная но как пришло в голову
        printUser();    //принт при каждом создании для наглядности
    }

    int getId()
    {
        static int s_id = 0;    //переменная типа статик хранит изменения (как глобальная но безопасно)
        return s_id++;          //увеличиваем чтобы каждый id был уникален
    }
    
    void printUser()            //просто фунция вывода
    {
        cout << "Obj with id = "<< m_id << " and root = "<< m_root<< " create"<< endl;
    }

};


int main()
{
    vector <Users> userslist;   //создаем вектор пользователей, члены которого обьекты нашего класса
    char input;
    do                          //я не знал как имитировать нажатие кнопки поэтому сделал гетчаром
    {
        input = getchar();      
        if(input != '\n')   //шобы по 2 обьекта за ввод не создавать, тип '\n' не хавать
        {
            userslist.push_back(static_cast<int>(input)-48);    //тут проблемка возникла что для создания нового обьекта нужно
                                                                //что-то вводить, но вариант вводить рут оказался логичным
                                                                //поэтому конструктор int(root)
        }                                                       //статик каст и -48 баззированно с теплицы ахах
    } while (input != '0'); //символ выхода
    
    cout << "We have "<< userslist.size()<< " users" << endl;   //в конце вывод количества пользователей в векторе
                                                                //с отладчика хорошо видно как всё лежит

    for (vector<Users>::iterator it = userslist.begin() ; it!=userslist.end() ; ++it)
        it->printUser();
    
    return 0;
}
