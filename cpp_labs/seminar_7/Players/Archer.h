//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_ARCHER_H
#define SEMINAR_7_ARCHER_H


#include "Player.h"

class Archer : public Player {
public:
    Archer(string player_name, int player_health, int player_attack, int player_defense)
            : Player(player_name, player_health, player_attack, player_defense) {}

    void shoot_arrow(Player &target) {
        int damage = get_attack() - target.get_defense();
        target.set_health(target.get_health() - damage);
        cout << get_name() << " стреляет стрелой в " << target.get_name() << " и наносит " << damage << " урона."
             << endl;
    }
};


#endif //SEMINAR_7_ARCHER_H
