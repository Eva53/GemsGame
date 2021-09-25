#pragma once
#include "Field.h"
#include "Bonus.h"

class GameControl {
private:
    int score = 0;

    bool SameColors(RectangleShape* r1, RectangleShape* r2);

    point_t GetPositionForBonus(point_t cur);

    bool CheckColorNeighboors(vector<point_t>& p);
public:
    Recolour recolour;
    Boom boom;
    Field** sq; 
    GameControl();

    GameControl(const GameControl&) = delete;
    GameControl& operator=(const GameControl&) = delete;

    void DrawField(RenderWindow& window);

    void Move(RenderWindow& window, point_t cur, point_t prev);

    bool CheckCombo();

    void RebuildField(RenderWindow& window);

    void CreateNewGem(RenderWindow& window);

    void CreateField();

    int getScore() {
        return score;
    }

    ~GameControl();
};
