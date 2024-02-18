//
// Created by cors90 on 18/02/2024.
//
#include "utils.h"

namespace combat_utils {
    int getRolledAttack(int attack) { // Function definition
        srand(time(0)); // Use current time as seed for random generator
        int lowerLimit = attack * .80;
        return (rand() % (attack - lowerLimit + 1)) + lowerLimit;
    }
}
