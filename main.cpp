#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

string logAttack(Character *attacker, Character *attacked);

int main() {
    Player *player = new Player("Victor", 100, 10, 4, 10);
    Enemy *enemy = new Enemy("Estudiante de Redes", 50, 18, 2, 5, 10);


    cout << player->toString() << endl;
    cout << enemy->toString() << endl;
    int i = 1;
    do {
        cout << "Round " << i << ":" << endl;
        player->doAttack(enemy);
        cout << logAttack(player, enemy) << endl;
        if (enemy->getHealth() > 0) {
            enemy->doAttack(player);
            cout << logAttack(enemy, player) << endl;
        }
        i++;
        cout << "=====================" << endl;
    } while (player->getHealth() > 0 && enemy->getHealth() > 0);
    if (player->getHealth() > enemy->getHealth()) {
        cout << "Player: "<<player->getName()<<" Won" << endl;
    } else {
        cout << "Enemy: \""<<enemy->getName()<<"\" Won" << endl;
    }

    delete player;
    delete enemy;
    return 0;
}

string logAttack(Character *attacker, Character *attacked) {
    return attacker->getName() + " attacked " + attacked->getName() + " , he's left with " +
           to_string(attacked->getHealth()) + " hp";
}
