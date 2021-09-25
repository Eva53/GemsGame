#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

#define width 10
#define height 10

typedef struct {
    int x, y;
}point_t;

class Field {
private:
    point_t pointGem;
    int sizeGem = 64;
public: 
    RectangleShape* s;
    bool isToDelete = false;

    bool IsNeighboor(point_t neigh);

    point_t getPoint();
};