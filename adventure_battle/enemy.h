#ifndef __enemy_h__
#define __enemy_h__

#include <string>

using namespace std;

//basic virtual class that all specific enemies derive from
class enemy
{
public:

    enemy(string n, int h, int s);

    //returns enemy health
    int health() const;
    //returns enemy's max health
    int max_health() const;
    //returns true if enemy is dead
    bool dead() const;
    //included because main has problems if an enemy doesnt have access to fireballs() function
    virtual int fireballs() const;
    //included because main has problems if an enemy doesnt have access to max_fireballs() function
    virtual int max_fireballs() const;
    //included because main has problems if an enemy doesnt have access to potions() function
    virtual int potions() const;
    //included because main has problems if an enemy doesnt have access to max_potions() function
    virtual int max_potions() const;
    //returns enemy name
    virtual string name() const;
    //returns random tip based on enemy type - does nothing in base class
    virtual string tip() const;
    //returns attack name
    virtual string attack_name() const;
    //returns description of enemy
    virtual string out() const;

    //included because main has problems if an enemy doesnt have access to fireball() function
    virtual void fireball();
    //included because main has problems if an enemy doesnt have access to potion() function
    virtual void potion();
    //how enemy takes damage
    virtual void hit(int amount);
    //how enemy does damage
    //an enemy pointer is passed and hit() is executed on explicit parameter
    virtual void attack(enemy* my_enemy);

private:

    string name_;
    int health_;
    int max_health_;
    int strength_;
    bool dead_;

protected:
    //protected so derivatives can directly access it and change it
    string attack_name_;
};

#endif