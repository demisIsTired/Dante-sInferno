/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** events
*/

#include "../include/parallelJam.hpp"

void GameModule::handleEvents()
{
    while (_window->pollEvent(*_event)) {
        if (_event->type == sf::Event::KeyPressed) {
            if (_event->key.code == sf::Keyboard::Escape)
                _loop = 0;
            if (_event->key.code == sf::Keyboard::Up)
                _up = 1;
            if (_event->key.code == sf::Keyboard::Down)
                _down = 1;
            if (_event->key.code == sf::Keyboard::Left)
                _left = 1;
            if (_event->key.code == sf::Keyboard::Right)
                _right = 1;
        }
        if (_event->type == sf::Event::KeyReleased) {
            if (_event->key.code == sf::Keyboard::Up)
                _up = 0;
            if (_event->key.code == sf::Keyboard::Down)
                _down = 0;
            if (_event->key.code == sf::Keyboard::Left)
                _left = 0;
            if (_event->key.code == sf::Keyboard::Right)
                _right = 0;
        }
    }
    if (_up)
        _player_y += 3;
    if (_down)
        _player_y -= 3;
    if (_left)
        _player_x += 3;
    if (_right)
        _player_x -= 3;
}