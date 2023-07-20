#include "include/council.h"

Council::Council() {
    srand((unsigned) time(NULL));
    gold = 100 + (rand() % 900);
}

int Council::getGold() {
    return gold;
}
