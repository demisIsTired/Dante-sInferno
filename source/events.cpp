/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** events
*/

#include "../include/parallelJam.hpp"

void GameModule::getNextChosenCell()
{
    std::vector<int> goodCells;

    for (size_t i = 0; i < _map.size(); i++) {
        if (_map[i] == 1)
            goodCells.push_back(i);
    }

    _pointCell = goodCells[rand() % goodCells.size()];
}

void GameModule::handleEvents()
{

    // Check Keyboard events
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
            if (_event->key.code == sf::Keyboard::W)
                _upPlayer = 1;
            if (_event->key.code == sf::Keyboard::S)
                _downPlayer = 1;
            if (_event->key.code == sf::Keyboard::A)
                _leftPlayer = 1;
            if (_event->key.code == sf::Keyboard::D)
                _rightPlayer = 1;
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
            if (_event->key.code == sf::Keyboard::W)
                _upPlayer = 0;
            if (_event->key.code == sf::Keyboard::S)
                _downPlayer = 0;
            if (_event->key.code == sf::Keyboard::A)
                _leftPlayer = 0;
            if (_event->key.code == sf::Keyboard::D)
                _rightPlayer = 0;
        
        }
    }

    //Move map
    if (_up)
        _map_y += 3;
    if (_down)
        _map_y -= 3;
    if (_left)
        _map_x += 3;
    if (_right)
        _map_x -= 3;

    int cell;

    //Move player
    if (_upPlayer) {
        cell = (int) ((int) (_player_y + 0.6) * _size_x) + (int) (_player_x + 0.43);
        if (_map[cell] == 1)
            _player_y -= 0.1;
    }
    if (_downPlayer) {
        cell = ((int) (_player_y + 1.3) * _size_x) + (_player_x + 0.43);
        if (_map[cell] == 1)
            _player_y += 0.1;
    }
    if (_leftPlayer) {
        cell = ((int) (_player_y + 0.7) * _size_x) + (_player_x + 0.33);
        if (_map[cell] == 1)
            _player_x -= 0.1;
    }
    if (_rightPlayer) {
        cell = ((int) (_player_y + 0.7) * _size_x) + (_player_x + 0.53);
        if (_map[cell] == 1)
            _player_x += 0.1;
    }
    

    //move Enemies
    for (int i = 0; i < 4; i++) {
        cell = (int) ((int) (_enemyPos[i].y + 0.5 + _enemyPush[i].y) * _size_x) + (int) (_enemyPos[i].x + 0.5);
        if (_map[cell] != 1)
            _enemyPush[i].y *= -1;
        cell = (int) ((int) (_enemyPos[i].y + 0.5) * _size_x) + (int) (_enemyPos[i].x + 0.5 + _enemyPush[i].x);
        if (_map[cell] != 1)
            _enemyPush[i].x *= -1;
        _enemyPos[i].y += _enemyPush[i].y;
        _enemyPos[i].x += _enemyPush[i].x;
    }

    //check collision
    int playerCell = ((int) (_player_y + 0.7) * _size_x) + (_player_x + 0.43);
    for (int i = 0; i < 4; i++) {
        cell = (int) ((int) (_enemyPos[i].y + 0.5 + _enemyPush[i].y) * _size_x) + (int) (_enemyPos[i].x + 0.5);
        if (cell == playerCell) {
            deleteGame();
            initGame();
        }
    }

    //handle score
    if (_timer && _timer % 60 == 0) {
        _timer = 0;
        _score += 1;
    }
    _timer += 1;

    if (_pointCell == playerCell) {
        _score += 10;
        getNextChosenCell();
    }
}