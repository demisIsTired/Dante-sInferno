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

class GameModule {
    public:
        GameModule() {}
        ~GameModule() {
            delete _sprite;
            delete _texture;
        }
        void initGame();
        void setMap();
        void drawMap();
        void drawGame();
        void handleEvents();
        sf::IntRect getMapRect(int type);
        int _size_x = 30;
        int _size_y = 30;
        int _player_x = 0;
        int _player_y = 0;
        int _left = 0;
        int _right = 0;
        int _up = 0;
        int _down = 0;
        int _loop = 1;
        float _pushTiles = 16.999969;
        float _scaleDown = 1;
        std::vector<int> _map;
        sf::Event *_event;
        sf::Sprite *_sprite;
        sf::Texture *_texture;
        sf::RenderWindow *_window;
};

int gameLoop();