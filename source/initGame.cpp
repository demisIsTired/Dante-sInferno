/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** initGame
*/

#include "../include/parallelJam.hpp"


void GameModule::deleteGame()
{
    _enemyPos.clear();
    _enemyPush.clear();
    _map.clear();
}

void GameModule::initGame()
{

    _player_x = 2;
    _player_y = 15;
    _score = 0;
    _timer = 0;

    if (_window == nullptr) {
        _texture = new sf::Texture;
        _sprite = new sf::Sprite;
        _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "ParallelJam");
        _window->setFramerateLimit(60);
        _texture->loadFromFile("./utils/tileset.png");
        _event = new sf::Event;
        _font = new sf::Font;
        _font->loadFromFile("./utils/font.ttf");
    }
    
    struct Point pos;
    pos.x = 26;
    pos.y = 16;
    for (int i = 0; i < 4; i++) {
        _enemyPos.push_back(pos);
    }
    
    pos.x = 0.05;
    pos.y = 0.05;
    _enemyPush.push_back(pos);
    pos.x = -0.05;
    pos.y = -0.05;
    _enemyPush.push_back(pos);
    pos.x = 0.05;
    pos.y = -0.05;
    _enemyPush.push_back(pos);
    pos.x = -0.05;
    pos.y = 0.05;
    _enemyPush.push_back(pos);
    
    setMap();
    getNextChosenCell();
}

void GameModule::setMap()
{
    std::ifstream infile("./utils/map.txt");
    char c;

    while (infile.get(c))
        if (c >= '0' && c <= '8')
        _map.push_back(c - '0');
}

