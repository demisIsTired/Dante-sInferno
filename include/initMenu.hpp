/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** initMenu
*/

#pragma once
#include "./parallelJam.hpp"

class initMenu {
    public:
        initMenu();
        ~initMenu();
        void drawMenu();
        void handleEvents();

    private:
        int _loop = 1;
        sf::Event *_event;
        sf::Sprite *_sprite;
        sf::Texture *_texture;
        sf::RenderWindow *_window;
};