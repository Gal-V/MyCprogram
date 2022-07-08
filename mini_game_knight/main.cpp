#include <iostream>
#include <string>
#include <cstdlib>//rand()
#include <ctime> //time()
#include <cstdio>//для гетчара

using namespace std;

class Creature
{
    protected:
    string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;

    public:
    Creature(string name, char symbol, int health, int damage, int gold):
    m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
    {}

    string getName(){return m_name;}
    char getSymbol(){return m_symbol;}
    int getHealth(){return m_health;}
    int getDamage(){return m_damage;}
    int getGold(){return m_gold;}

    void reduceHealth(int damage_value) //уменьшает здоровье Creature
    {
        m_health -= damage_value;
    }
    bool isDead()                       //проверка смерти
    {
        return (m_health <= 0); 
    }
    void addGold(int gold_value)        //добавление золота
    {
        m_gold += gold_value;
    }

    void printHealth()
    {
        for (int i = 0; i < m_health; i++)
        {
            cout<<"♥";
        }
        cout<<endl;
    }
};

class Player: public Creature           //игрок
{
    int m_level = 1;

    public:
    Player(string p_name) : Creature(p_name, '@', 10, 1, 0) //начальные параметры
    {}

    int getLevel(){return m_level;}
    void levelUp(){m_level++; m_damage++;}  //при левелапе +1 к дамагу
    bool hasWon(){return (m_level >= 20);}  //20 лвл = победа
};

class Monster: public Creature          //монстры
{

    public:
    enum Type{DRAGON, ORC, SLIME, MAX_TYPES}; //типы монстров
    Monster(Type type) : Creature(monsterData[type].name, monsterData[type].symbol,
                                  monsterData[type].health, monsterData[type].damage,
                                  monsterData[type].gold)
    {}

    struct MonsterData                  //структура данных о монстарах
    {
        string name;
        char symbol;
        int health;
        int damage;
        int gold;
    };
    static MonsterData monsterData[MAX_TYPES];//обьявление массива
    static Type getRandomMonster()   //рандомное число от 1 до MAX_TYPES
    {
        int min = 0;            
        int max = MAX_TYPES;
        return static_cast<Type>(rand() % max);    //преобразуем в тип монстров
    }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]//1101 1631
{   //данные о монстрах
    { "dragon", 'D', 20, 4, 100 },//name symbol Hp Damage Gold
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }

};

void playerAttackMonster(Player &p, Monster &m)
{
    m.reduceHealth(p.getDamage());
    cout<< "You hit  "<< m.getName()<< " for " << p.getDamage()<< " damage" <<endl;
    if (m.isDead())     //при убийстве монста
    {
        cout << "You killed  "<< m.getName()<<endl;
        p.levelUp();    //лвл ап
        cout<< "lvl "<< p.getLevel()<< " \tdamage "<< p.getDamage() <<endl;
        p.addGold(m.getGold()); //+голда
        cout<< "+ "<< m.getGold()<< " gold \t u have "<< p.getGold()<< " gold"<<endl;
        cout<<"hp "<<p.getHealth()<<endl;
        cout<<endl;
    }
    
}

void monsterAttackPlayer(Monster &m, Player &p)
{
    p.reduceHealth(m.getDamage());
    cout<< m.getName() << " hit you for " << m.getDamage()<< " damage" <<endl;
    cout<<endl;
}

void fightMonster(Player &p) 
{
    char input = '0'; 
    int flag = 0;
    Monster m(Monster::getRandomMonster());
    cout << "You have met a "<< m.getName() << " " << m.getSymbol() << endl;
    while (!m.isDead() && !p.isDead())  //пока никто не умер
    {
        cout << "Run(r) or Fight(f): ";
        do
        {
            if (flag > 2)
            {
                cout << "incorrect action, enter r or f " << endl;
            }
            input =  getchar(); 
            flag++;
        } while ((input != 'f') && (input != 'r'));
        flag = 0;
        cout<<endl;
    
        if (input == 'r')   //если выбран бег
        {
        bool escape_success = static_cast<bool>(rand() % 2);  //50/50 шанс убежать
        if (escape_success)
        {
            cout << "You can escape"<< endl;
            return;
        }else{
            cout<< "You failed escape"<<endl;
            monsterAttackPlayer(m, p);
            //continue;
        }
        
        }else{
            playerAttackMonster(p, m);
            if (!m.isDead())
            {
                monsterAttackPlayer(m, p);
            }
            //cout<<endl;
        }
            cout<< "your hp:   ";
            p.printHealth();
            cout<< m.getName() << " hp: ";
            m.printHealth();
    }
}


int main(int argc, char const *argv[])
{
    srand(time(NULL)); 
    //инициализация игрока
    string p_name("Player1");
    cout << "Enter your name: ";
    cin >> p_name;
    cout << endl;
    Player p(p_name);
    cout << "Welcome, " << p.getName() << endl;
    cout <<"You have " << p.getHealth() << " health and " << p.getGold() << " gold" << endl << endl;
    //встреча с монстром
    while (!p.isDead() && !p.hasWon())
    {
        fightMonster(p);
    }

    if (p.isDead())
    {
        cout<<endl;
        cout<<"You DIED with "<< p.getGold()<< " gold"<<endl;
        cout<< "The dead don't need gold"<<endl;
    }else{
        cout<<endl;
        cout<<"You are won and earn "<< p.getGold()<<" gold"<<endl;
    }
    
    return 0;
}

