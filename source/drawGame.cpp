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
            rect.left = 76 + 5;
            rect.top = 129 + 10;
            rect.width = 16;
            rect.height = 3;
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

void GameModule::drawEnemy(int i)
{
    sf::IntRect rect;

    rect.top = 55;
    rect.left = 403;
    rect.width = 15;
    rect.height = 30;
    _sprite->setTextureRect(rect);

    sf::Vector2f pos;

    pos.x = (_enemyPos[i].x * (_pushTiles * _scaleDown)) + PUSH_MAP_X - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_x * (i + 2));
    pos.y = (_enemyPos[i].y * (_pushTiles * _scaleDown)) + PUSH_MAP_Y - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_y * (i + 2));
    _sprite->setPosition(pos);
    _sprite->setScale(_scaleDown * 1.8, _scaleDown * 1.8);
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

    sf::Vector2f pos;
    pos.x = (_player_x * (_pushTiles * _scaleDown)) + PUSH_MAP_X - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_x * (i + 2));
    pos.y = (_player_y * (_pushTiles * _scaleDown)) + PUSH_MAP_Y - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_y * (i + 2));
    _sprite->setPosition(pos);

    _sprite->setScale(_scaleDown, _scaleDown);
    _window->draw(*_sprite);
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
            _sprite->setPosition(sf::Vector2f((j % _size_x * (_pushTiles * _scaleDown)) + PUSH_MAP_X - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_x * (i + 2)), ((j / _size_x) * (_pushTiles * _scaleDown)) + PUSH_MAP_Y - (i * MAP_PUSH_BACK * (i * 0.85)) + (_map_y * (i + 2))));
            _sprite->setScale(_scaleDown, _scaleDown);
            _window->draw(*_sprite);
            drawPlayer(i);
            drawEnemy(i);
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