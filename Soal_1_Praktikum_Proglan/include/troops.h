#ifndef TROOPS_H
#define TROOPS_H

class Troops {
protected:
    int health;
    int attack;
    int cost;
public:
    int getHealth();
    int getAttack();
    int getCost();
    void attackStats();
};

#endif
