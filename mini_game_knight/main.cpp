#include <iostream>
#include <string>
using namespace std;

class Creature
{
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

int main(int argc, char const *argv[])
{
    Creature o("orc", 'o', 4, 2, 10);
    o.addGold(5);
    o.reduceHealth(1);
    cout << o.getName() << " has " << o.getHealth() << " health and " << o.getGold() << " gold";
    return 0;
}
