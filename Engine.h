//
// Created by nikita on 12/2/22.
//
#pragma once

#include "SFML/Graphics.hpp"
#include "Vadim.h"

struct gameMap {
    static const int HEIGHT_MAP = 33;//размер карты высота
    static const int WIDTH_MAP = 60;//размер карты ширина
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::String TileMap[HEIGHT_MAP] = {
            "0000000000000000000000000000000000000000",
            "0                                      0",
            "0   s                                  0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0000000000000000000000000000000000000000",
    };
};

struct Program {
    gameMap gMap;
    sf::RenderWindow Window;
    sf::Sprite BackSprite;
    sf::Texture BackTexture;
    sf::Image MapImage;
};

//Инициализирует поля структуры gameMap работает с указателем на gameMap
void initMap(gameMap *map);

void drawMap(Program *program);

void input(Vadim *vadim, Program *program, Vadim *student);

void update(float time, Vadim *vadim, Vadim *student);

void draw(Program *program, Vadim *vadim, Vadim *student);

void start(Vadim *vadim, Program *program, Vadim *student);

void initEngine(Program *program);