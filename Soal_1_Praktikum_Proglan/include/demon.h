#ifndef DEMON_H
#define DEMON_H

#include <cstdlib>
#include <ctime>

class Demon {
private:
    int health;
    int attack;
public:
    Demon();
    int getHealth();
    int getAttack();
};

#endif
