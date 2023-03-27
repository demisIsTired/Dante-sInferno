/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** drawGame
*/

#include "../include/parallelJam.hpp"

#define SCALE_TILES 25
#define PUSH_MAP_X 850
#define PUSH_MAP_Y 300
#define SCALE_DOWN 1
#define NB_LOOPS 5

#define MAP_PUSH_BACK 75

#define BASE_SCALE 0.2

sf::IntRect GameModule::getMapRect(int type)
{
    sf::IntRect rect;
    switch (type) {
        case 1:
            rect.left = 16;
            rect.top = 65;
            rect.width = 16;
            rect.height = 16;
            return rect;
        case 2:
            rect.left = 20;
            rect.top = 129;
            rect.width = 16;
            rect.height = 16;
            return rect;    
        case 3:
            rect.left = 32;
            rect.top = 97 + 16;
            rect.width = 16;
            rect.height = 20;
            return rect;
        case 4:
            rect.left = 60;
            rect.top = 129;
            rect.width = 4;
            rect.height = 16;
            return rect;
        case 5:
            rect.left = 76 + 5;
            rect.top = 129 + 12;
            rect.width = 16;
            rect.height = 3;
            return rect;
    }
    return rect;
}

float getScaleDown(int level)
{
    if (!level)
        return 1;
    return (SCALE_DOWN * level);
}

float getPush(int level)
{
    return (100 * level) * - 1;
}

sf::Vector2f getScaledPosition(int i, int j, int size_x, float scaleTiles, float scaleDown)
{
    float base_x = (j % size_x) * scaleTiles;
    float base_y = (j / size_x) * scaleTiles;
    float scale = scaleDown + (0.1 * i);
    sf::Vector2f pos;
    pos.x = base_x * scale;
    pos.y = base_y * scale;
    return pos;
}

void GameModule::drawTitle(int i)
{
    sf::Text text;

    text.setFont(*_font);
    text.setString("DANTE'S INFERNO");

    sf::Vector2f pos;

    pos.x = (0 * (_pushTiles * _scaleDown)) + PUSH_MAP_X - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_x * (i + 2));
    pos.y = (-3 * (_pushTiles * _scaleDown)) + PUSH_MAP_Y - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_y * (i + 2));

    text.setPosition(pos);
    text.setCharacterSize((i + 1) * 20);
    text.setFillColor(sf::Color::Red);
    _window->draw(text);
}

void GameModule::drawText(int i)
{
    sf::Text text;

    text.setFont(*_font);
    text.setString("Score: " + std::to_string(_score));

    sf::Vector2f pos;

    pos.x = (13 * (_pushTiles * _scaleDown)) + PUSH_MAP_X - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_x * (i + 2));
    pos.y = (14 * (_pushTiles * _scaleDown)) + PUSH_MAP_Y - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_y * (i + 2));

    text.setPosition(pos);
    text.setCharacterSize((i + 1) * (5));
    _window->draw(text);
}

void GameModule::drawEnemy(int i)
{
    sf::IntRect rect;

    rect.top = 55;
    rect.left = 403;
    rect.width = 15;
    rect.height = 30;
    _sprite->setTextureRect(rect);
    int isFlipped = _enemyPush[i].x < 0;
    float scalePush[2] = {0, 0.9};
    int scaleFlip[2] = {1, -1};

    sf::Vector2f pos;

    pos.x = ((_enemyPos[i].x + scalePush[isFlipped]) * (_pushTiles * _scaleDown)) + PUSH_MAP_X - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_x * (i + 2));
    pos.y = (_enemyPos[i].y * (_pushTiles * _scaleDown)) + PUSH_MAP_Y - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_y * (i + 2));
    _sprite->setPosition(pos);
    _sprite->setScale(_scaleDown * 1.8 * scaleFlip[isFlipped], _scaleDown * 1.8);
    _sprite->setColor(sf::Color::White);
    _window->draw(*_sprite);
}

void GameModule::drawPlayer(int i)
{
    sf::IntRect rect;

    rect.top = 74;
    rect.left = 128;
    rect.width = 15;
    rect.height = 30;
    _sprite->setTextureRect(rect);
    float scalePush[2] = {0, 0.7};

    sf::Vector2f pos;
    pos.x = ((_player_x + scalePush[_scale]) * (_pushTiles * _scaleDown)) + PUSH_MAP_X - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_x * (i + 2));
    pos.y = (_player_y * (_pushTiles * _scaleDown)) + PUSH_MAP_Y - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_y * (i + 2));
    _sprite->setPosition(pos);

    _sprite->setScale(_scaleDown, _scaleDown);

    if (_scale) {
        _sprite->setScale(_sprite->getScale().x * -1, _sprite->getScale().y);
    }
    _sprite->setColor(sf::Color::White);
    _window->draw(*_sprite);
    _sprite->setScale(_sprite->getScale().x * -1, _sprite->getScale().y);
}   

void GameModule::drawMap()
{
    size_t size = _map.size();
    _scaleDown = 0.3;
    _sprite->setTexture(*_texture);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < size; j++) {
            if (!_map[j]) {
                continue;
            }
            _sprite->setTextureRect(getMapRect(_map[j]));
            _sprite->setColor(sf::Color::Blue);
            if (j == _pointCell)
                _sprite->setColor(sf::Color(255, 222, 46));
            _sprite->setPosition(sf::Vector2f((j % _size_x * (_pushTiles * _scaleDown)) + PUSH_MAP_X - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_x * (i + 2)), ((j / _size_x) * (_pushTiles * _scaleDown)) + PUSH_MAP_Y - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_y * (i + 2))));
            _sprite->setScale(_scaleDown, _scaleDown);
            _window->draw(*_sprite);
            drawPlayer(i);
            drawEnemy(i);
            if (i == 3) {
                drawText(i);
                drawTitle(i);
            }
        }
        _scaleDown *= 2;
    }
}

void GameModule::drawGame()
{
    sf::Color greyColor(15, 15, 15, 255);
    _window->clear(greyColor);
    drawMap();
    _window->display();
}