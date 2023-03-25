/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** initMenu
*/

#pragma once
#include "./parallelJam.hpp"

class MenuConfig {
    public:
        MenuConfig();
        ~MenuConfig();
        void drawMenu();
        void handleEvents();

    private:
        int _loop = 1;
        bool _quit = false;
        sf::Event *_event;
        sf::RenderWindow *_window;
        std::vector<sf::Sprite*> _sprites;
};