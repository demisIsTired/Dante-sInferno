/*
** EPITECH PROJECT, 2023
** parrallelJam
** File description:
** initMenu
*/

#include "../include/menuConfig.hpp"

MenuConfig::MenuConfig()
{
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Dante's Inferno");
    _window->setFramerateLimit(60);

    sf::Texture* background_tx = new sf::Texture;
    background_tx->loadFromFile("./utils/menu/background.png");
    sf::Texture* play_btn_tx = new sf::Texture;
    play_btn_tx->loadFromFile("./utils/menu/menu_play_high.png");
    sf::Texture* quit_btn_tx = new sf::Texture;
    quit_btn_tx->loadFromFile("./utils/menu/menu_quit.png");

    sf::Sprite* background_sp = new sf::Sprite;
    background_sp->setTexture(*background_tx);
    background_sp->setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    background_sp->setPosition(450, 200);
    sf::Sprite* play_button_sp = new sf::Sprite;
    play_button_sp->setTexture(*play_btn_tx);
    play_button_sp->setTextureRect(sf::IntRect(0, 0, 600, 100));
    play_button_sp->setPosition(864, 486);
    sf::Sprite* quit_button_sp = new sf::Sprite;
    quit_button_sp->setTexture(*quit_btn_tx);
    quit_button_sp->setTextureRect(sf::IntRect(0, 0, 600, 100));
    quit_button_sp->setPosition(864, 586);

    _sprites.push_back(background_sp);
    _sprites.push_back(play_button_sp);
    _sprites.push_back(quit_button_sp);

    _event = new sf::Event;
}

MenuConfig::~MenuConfig()
{
    delete _event;
    delete _window;
    _sprites.clear();
}

void MenuConfig::drawMenu()
{
    for (int i = 0; i < _sprites.size(); i++)
        _window->draw(*_sprites[i]);
    _window->display();

    while (_loop == 1) {
        this->handleEvents();
        this->drawMenu();
    }
    if (_loop == 2)
        exit(0);
}

void MenuConfig::handleEvents()
{
    while (_window->pollEvent(*_event)) {
        if (_event->type == sf::Event::Closed) {
            _window->close();
            exit(0);
        }
        if (_event->type == sf::Event::KeyPressed) {
            if (_event->key.code == sf::Keyboard::Escape) {
                _window->close();
                exit(0);
            }
            if (_event->key.code == sf::Keyboard::Return) {
                _window->close();
                _loop = (!_quit) ? 0 : 2;
            }
            if (_event->key.code == sf::Keyboard::Up) {
                sf::Texture* play_btn_tx = new sf::Texture;
                play_btn_tx->loadFromFile("./utils/menu/menu_play_high.png");
                _sprites[1]->setTexture(*play_btn_tx);
                sf::Texture* quit_btn_tx = new sf::Texture;
                quit_btn_tx->loadFromFile("./utils/menu/menu_quit.png");
                _sprites[2]->setTexture(*quit_btn_tx);
                _quit = false;
            }
            if (_event->key.code == sf::Keyboard::Down) {
                sf::Texture* play_btn_tx = new sf::Texture;
                play_btn_tx->loadFromFile("./utils/menu/menu_play.png");
                _sprites[1]->setTexture(*play_btn_tx);
                sf::Texture* quit_btn_tx = new sf::Texture;
                quit_btn_tx->loadFromFile("./utils/menu/menu_quit_high.png");
                _sprites[2]->setTexture(*quit_btn_tx);
                _quit = true;
            }
        }
    }
}