#include "Game.h"
#include "GameControl.h"

int main()
{
    srand(time(0));

    Game game;
    int Gem = 0, Bonus = 0;
    point_t prev;

    while (game.window.isOpen())
    {
        game.Update(Gem, Bonus, prev);
        game.UpdateField();
        game.Draw();
    }
    return 0;
}