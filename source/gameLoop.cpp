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
    game.drawGame();
    return;
}