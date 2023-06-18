//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_SHOOTER_H
#define SEMINAR_7_SHOOTER_H

#include <iostream>
#include "Game.h"

using namespace std;

class Shooter : public Game {
public:
    Shooter(string game_name) : Game(game_name) {}
};


#endif //SEMINAR_7_SHOOTER_H
