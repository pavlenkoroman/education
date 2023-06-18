//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_PLAYER_H
#define SEMINAR_7_PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Player {
private:
    std::string name_;
    int health_;
    int attack_;
    int defense_;

public:
    Player(string& player_name, int player_health, int player_attack, int player_defense)
            : name_(player_name), health_(player_health), attack_(player_attack), defense_(player_defense) {}

    void set_name(string& player_name) {
        name_ = player_name;
    }

    void set_health(int player_health) {
        health_ = player_health;
    }

    void set_attack(int player_attack) {
        attack_ = player_attack;
    }

    void set_defense(int player_defense) {
        defense_ = player_defense;
    }

    std::string get_name() const {
        return name_;
    }

    int get_health() const {
        return health_;
    }

    int get_attack() const {
        return attack_;
    }

    int get_defense() const {
        return defense_;
    }

    void attack_player(Player& target) {
        int damage = attack_ - target.get_defense();
        target.set_health(target.get_health() - damage);
        cout << name_ << " атакует " << target.get_name() << " и наносит " << damage << " урона." << endl;
    }

    void defend() {
        cout << name_ << " защищается." << endl;
    }
};


#endif //SEMINAR_7_PLAYER_H
