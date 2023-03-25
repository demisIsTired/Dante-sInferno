/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** initMenu
*/

#include "../include/initMenu.hpp"

initMenu::initMenu()
{
    _texture = new sf::Texture;
    _sprite = new sf::Sprite;
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade");
    _window->setFramerateLimit(60);
    _texture->loadFromFile("./utils/menu.png");
    _event = new sf::Event;
}

initMenu::~initMenu()
{
    delete _sprite;
    delete _texture;
    delete _window;
}