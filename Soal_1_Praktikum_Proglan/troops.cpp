#include "include/troops.h"
#include <iostream>

int Troops::getHealth() {
    return health;
}

int Troops::getAttack() {
    return attack;
}

int Troops::getCost() {
    return cost;
}

void Troops::attackStats() {
    std::cout << "Attacking with " << attack << " attack points!" << std::endl;
}
