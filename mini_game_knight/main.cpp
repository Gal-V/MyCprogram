#include <iostream>
#include <string>
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
};

class Player: public Creature           //игрок
{
    int m_level = 1;

    public:
    Player(string p_name) : Creature(p_name, '@', 10, 1, 0) //начальные параметры
    {}

    int getLevel(){return m_level;}
    void levelUp(){m_level++; m_damage++;}  //при левелапе +1 к дамагу
    bool hasWon(){return (m_level == 20);}  //20 лвл = победа
};

int main(int argc, char const *argv[])
{
    string p_name("Player1");
    cout << "Enter your name: ";
    cin >> p_name;
    cout << endl;
    Player p(p_name);
    cout << "Welcome, " << p.getName() << endl;
    cout <<"You have " << p.getHealth() << " health and " << p.getGold() << " gold" << endl;

    Creature o("orc", 'o', 4, 2, 10);
    o.addGold(5);
    o.reduceHealth(1);
    cout << o.getName() << " has " << o.getHealth() << " health and " << o.getGold() << " gold" << endl;

    return 0;
}
