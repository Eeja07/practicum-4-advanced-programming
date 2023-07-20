/*
 * Runner class definition
 *
 * You can add function definitions as you need.
 */

#include <iostream>
#include <cstdlib>
#include "runner.h"

Runner::Runner(coordinate pos) : Zombie(pos, (rand() % 100 + 100), (rand() % 100 + 100), 13, static_cast<int>(0.1), 2) {}