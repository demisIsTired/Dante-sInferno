/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** initMenu
*/

#include "../include/menuConfig.hpp"

MenuConfig::MenuConfig()
{
    _texture = new sf::Texture;
    _sprite = new sf::Sprite;
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade");
    _window->setFramerateLimit(60);
    _texture->loadFromFile("./utils/tileset.png");
    _event = new sf::Event;
}

MenuConfig::~MenuConfig()
{
    delete _sprite;
    delete _texture;
    delete _window;
}

void MenuConfig::drawMenu()
{
    _sprite->setTexture(*_texture);
    _sprite->setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    _window->draw(*_sprite);
    _window->display();
    while (_loop == 1) {
        this->handleEvents();
        this->drawMenu();
    }
}

void MenuConfig::handleEvents()
{
    while (_window->pollEvent(*_event)) {
        if (_event->type == sf::Event::Closed) {
            _window->close();
            _loop = 0;
        }
        if (_event->type == sf::Event::KeyPressed) {
            if (_event->key.code == sf::Keyboard::Escape) {
                _window->close();
                _loop = 0;
            }
        }
    }
}