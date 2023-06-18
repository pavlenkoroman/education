//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_RPG_H
#define SEMINAR_7_RPG_H

#include <iostream>
#include "Game.h"

using namespace std;

class RPG : public Game {
public:
    RPG(string game_name) : Game(game_name) {}
};


#endif //SEMINAR_7_RPG_H
