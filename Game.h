#pragma once
#include "GameControl.h"

class Game {
private:
    Text Score;
    Font font;
    string printScore = "Score: ";
    GameControl controller;
public:
    Game();

    RenderWindow window{ VideoMode(640, 750), "Gems" };

    void UpdateField();

    void Draw();

    void Picture();

    void Update(int& countOfClick, int& clickBonus, point_t& prev);
};
