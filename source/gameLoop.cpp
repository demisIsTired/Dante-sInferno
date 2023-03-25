/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** gameLoop
*/

#include "../include/parallelJam.hpp"
#include "../include/menuConfig.hpp"

int gameLoop()
{
    GameModule game;
    MenuConfig menu;

    menu.drawMenu();
    game.initGame();
    while (game._loop) {
        game.handleEvents();
        game.drawGame();
    }
    return 0;
}