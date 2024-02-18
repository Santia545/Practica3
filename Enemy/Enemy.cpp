//
// Created by Victor Navarro on 15/02/24.
//

#include "Enemy.h"
#include "../Utils.h"


Enemy::Enemy(string _name, int _health, int _attack, int _defense, int _speed, int _experience) : Character(_name, _health, _attack, _defense, _speed) {
    experience = _experience;
}

void Enemy::doAttack(Character *target) {
    target->takeDamage(combat_utils::getRolledAttack(attack));
}

void Enemy::takeDamage(int damage) {
    int trueDamage = damage - defense;

    health-= trueDamage;
}

int Enemy::getExperience() {
    return experience;
}