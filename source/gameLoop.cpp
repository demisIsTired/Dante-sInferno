/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** gameLoop
*/

#include "../include/parallelJam.hpp"

int gameLoop()
{
    GameModule game;

    game.initGame();
    while (game._loop) {
        game.handleEvents();
        game.drawGame();
    }
    return 0;
}