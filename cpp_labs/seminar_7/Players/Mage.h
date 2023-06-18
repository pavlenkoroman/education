//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_MAGE_H
#define SEMINAR_7_MAGE_H


#include "Player.h"

class Mage : public Player {
public:
    Mage(string player_name, int player_health, int player_attack, int player_defense)
            : Player(player_name, player_health, player_attack, player_defense) {}

    void cast_spell(Player &target) {
        int damage = get_attack() * 3 - target.get_defense();
        target.set_health(target.get_health() - damage);
        cout << get_name() << " произносит заклинание на " << target.get_name()
             << " и наносит " << damage << " урона." << endl;
    }
};


#endif //SEMINAR_7_MAGE_H
