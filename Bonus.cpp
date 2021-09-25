#include "Bonus.h"

void Recolour::Do(RenderWindow& window, Field** gems) {
    point_t posG = position;
    point_t newPos1 = { rand() % 9, rand() % 9 }, newPos2 = { rand() % 9, rand() % 9 };
    curColor = gems[position.x][position.y].s->getFillColor();
    newPos1 = prev[0];
    newPos2 = prev[1];

    if (gems[posG.x][posG.y].IsNeighboor(newPos1)) {
        newPos1.x = newPos1.x + 1;
        newPos1.y = newPos1.y + 1;
    }
    if (gems[posG.x][posG.y].IsNeighboor(newPos2)) {
        newPos2.x = newPos2.x + 1;
        newPos2.y = newPos2.y + 1;
    }

    gems[newPos1.x][newPos1.y].s->setFillColor(Color::Black);
    gems[newPos2.x][newPos2.y].s->setFillColor(Color::Black);
    window.draw(*gems[newPos1.x][newPos1.y].s);
    window.draw(*gems[newPos2.x][newPos2.y].s);
    window.display();
    sleep(seconds(0.2f));

    gems[newPos1.x][newPos1.y].s->setFillColor(curColor);
    gems[newPos2.x][newPos2.y].s->setFillColor(curColor);

    window.draw(*gems[newPos1.x][newPos1.y].s);
    window.draw(*gems[newPos2.x][newPos2.y].s);
    window.display();
    sleep(seconds(0.2f));
    gems[position.x][position.y].s->setOutlineThickness(-2);
}

void Boom::Do(RenderWindow& window, Field** gems) {
    point_t positions[4];
    for (auto pos : positions) {
        GenerateNewPosition(pos);
        gems[pos.x][pos.y].s->setFillColor(Color::Black);
    }
}