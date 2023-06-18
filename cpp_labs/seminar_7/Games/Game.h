//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_GAME_H
#define SEMINAR_7_GAME_H


#include <iostream>

using namespace std;

class Game {
private:
    std::string game_name_;
    bool game_started_;
    bool game_finished_;

public:
    Game(string game_name) : game_name_(game_name), game_started_(false), game_finished_(false) {}

    void start_game() {
        game_started_ = true;
        cout << "Игра " << game_name_ << " началась!" << endl;
    }

    void finish_game() {
        game_finished_ = true;
        cout << "Игра " << game_name_ << " завершена!" << endl;
    }

    void display_game_state() const {
        if (game_started_) {
            cout << "Текущее состояние игры " << game_name_ << ": ";
            if (game_finished_) {
                cout << "завершена" << endl;
            } else {
                cout << "в процессе" << endl;
            }
        } else {
            cout << "Игра " << game_name_ << " еще не начата." << endl;
        }
    }
};


#endif //SEMINAR_7_GAME_H
