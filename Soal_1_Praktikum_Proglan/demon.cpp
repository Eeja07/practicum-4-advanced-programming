#include "include/demon.h"

Demon::Demon() {
    srand((unsigned) time(NULL));
    health = 20 + (rand() % 980);
    attack = 5 + (rand() % 94);
}

int Demon::getHealth() {
    return health;
}

int Demon::getAttack() {
    return attack;
}
