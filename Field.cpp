#include "Field.h"

bool Field::IsNeighboor(point_t neigh) {
    point_t cur = { (int)s->getPosition().x / sizeGem, (int)s->getPosition().y / sizeGem };
    if (cur.x == neigh.x) {
        return ((cur.y = neigh.y + 1) || (cur.y == neigh.y - 1));
    }
    if (cur.y == neigh.y) {
        return ((cur.x == neigh.x + 1) || (cur.x == neigh.x - 1));
    }
    return false;
}

point_t Field::getPoint() {
    pointGem = { (int)s->getPosition().x / sizeGem,  (int)s->getPosition().y / sizeGem };
    return pointGem;
}