#pragma once
#include "Field.h"

class Bonus {
protected:
    point_t position;
public:
    bool isActive = false;

    virtual void Do(RenderWindow& window, Field** gems) = 0;
    void SetPosition(point_t position) {
        this->position = position;
    }
};

class Recolour : public Bonus {
public:
    point_t prev[2];
    Color curColor;

    virtual void Do(RenderWindow& window, Field** gems);
};

class Boom : public Bonus {
private:
    void GenerateNewPosition(point_t& newPos) {
        newPos = { rand() % 9, rand() % 9 };
    }
public:
    virtual void Do(RenderWindow& window, Field** gems);
};
