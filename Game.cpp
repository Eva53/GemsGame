#include "Game.h"
#include "GameControl.h"

Game::Game() {
    font.loadFromFile("bold.ttf");
    Score.setFont(font);
    Score.setString(printScore + to_string(controller.getScore()));
    Score.setPosition(Vector2f(width, height * 64));
    Score.setCharacterSize(100);
    Score.setFillColor(Color::Black);
}

void Game::UpdateField() {
    controller.CheckCombo();
    controller.RebuildField(window);
    controller.CreateNewGem(window);
}

void Game::Update(int& countOfClick, int& clickBonus, point_t& prev) {
    int sizeGem = 64;
    Event event;
    window.setFramerateLimit(60);
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();

        if (event.type == Event::MouseButtonPressed) {
            if (event.key.code == Mouse::Left) {
                Vector2i pos = Mouse::getPosition(window);
                point_t cur = { pos.x / sizeGem , pos.y / sizeGem };

                // поменять блоки местами
                if (controller.recolour.isActive && clickBonus < 2) {
                    controller.recolour.prev[clickBonus] = cur;
                    clickBonus++;
                    if (clickBonus >= 2) {
                        clickBonus = 0;
                        controller.recolour.Do(window, controller.sq);
                        controller.recolour.isActive = false;
                    }
                    continue;
                }
                countOfClick++;
                if (countOfClick == 2) {
                    controller.Move(window, cur, prev);

                    countOfClick = 0;
                }
                prev = cur;
            }
        }
        if (controller.boom.isActive) {
            controller.boom.Do(window, controller.sq);
            controller.boom.isActive = false;
        }
    }
}

void Game::Draw() {
    window.clear(Color::White);
    controller.DrawField(window);
    Score.setString(printScore + to_string(controller.getScore()));
    window.draw(Score);
    if (controller.getScore() >= 100) {
        Picture();
    }
    window.display();
}

void Game::Picture(void) {
    sf::Texture png;
    png.loadFromFile("picture.png");

    sf::RectangleShape shape(sf::Vector2f(width*55, height*55));
    shape.setPosition(width, height);
    shape.setTexture(&png);

    window.draw(shape);
}