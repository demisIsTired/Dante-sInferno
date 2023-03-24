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
        sf::IntRect getMapRect(int type);
        int _size_x = 30;
        int _size_y = 30;
        std::vector<int> _map;
        sf::Sprite *_sprite;
        sf::Texture *_texture;
        sf::RenderWindow *_window;
};

int gameLoop();