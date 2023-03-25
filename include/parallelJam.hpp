/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** parallelJam
*/

#pragma once

#include <stdio.h>
#include <vector>
#include <string>
#include <dlfcn.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <SFML/System/String.hpp>


struct Point {
    float x;
    float y;
};

class GameModule {
    public:
        GameModule() {}
        ~GameModule() {
            delete _sprite;
            delete _texture;
        }
        void initGame();
        void deleteGame();
        void setMap();
        void drawMap();
        void drawGame();
        void drawMenu();
        void drawPlayer(int i);
        void handleEvents();
        void drawEnemy(int i);
        sf::IntRect getMapRect(int type);
        int _size_x = 30;
        int _size_y = 30;
        int _map_x = 0;
        int _map_y = 0;
        float _player_x = 2;
        float _player_y = 15;
        int _left = 0;
        int _right = 0;
        int _up = 0;
        int _down = 0;
        int _leftPlayer = 0;
        int _rightPlayer = 0;
        int _upPlayer = 0;
        int _downPlayer = 0;
        int _loop = 1;
        int _menu = 1;
        float _pushTiles = 16.999969;
        float _scaleDown = 1;
        std::vector<struct Point> _enemyPos;
        std::vector<struct Point> _enemyPush;
        std::vector<int> _map;
        sf::Event *_event = nullptr;
        sf::Sprite *_sprite = nullptr;
        sf::Texture *_texture = nullptr;
        sf::RenderWindow *_window = nullptr;
};

int gameLoop();