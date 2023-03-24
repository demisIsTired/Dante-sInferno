/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** drawGame
*/

#include "../include/parallelJam.hpp"

sf::IntRect GameModule::getMapRect(int type)
{
    switch (type) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
    }
}

void GameModule::drawMap()
{
    size_t size = _map.size();
    _sprite->setTexture(*_texture);

    for (int i = 0; i < size; i++) {
        
    }
}

void GameModule::drawGame()
{
    _window->clear(sf::Color::Black);
    drawMap();
    _window->display();
}