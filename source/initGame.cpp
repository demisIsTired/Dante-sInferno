/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** initGame
*/

#include "../include/parallelJam.hpp"

void GameModule::initGame()
{
    _texture = new sf::Texture;
    _sprite = new sf::Sprite;
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "ParallelJam");
    _window->setFramerateLimit(60);
    _texture->loadFromFile("./utils/tileset.png");
    _event = new sf::Event;
    setMap();
}

void GameModule::setMap()
{
    std::ifstream infile("./utils/map.txt");
    char c;

    while (infile.get(c))
        if (c >= '0' && c <= '8')
        _map.push_back(c - '0');
}

