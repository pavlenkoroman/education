//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_WARRIOR_H
#define SEMINAR_7_WARRIOR_H


#include "Player.h"

class Warrior : public Player {
public:
    Warrior(string player_name, int player_health, int player_attack, int player_defense)
            : Player(player_name, player_health, player_attack, player_defense) {}

    void special_attack(Player &target) {
        int damage = get_attack() * 2 - target.get_defense();
        target.set_health(target.get_health() - damage);
        cout << get_name() << " выполняет специальную атаку на " << target.get_name()
             << " и наносит " << damage << " урона." << endl;
    }
};


#endif //SEMINAR_7_WARRIOR_H
