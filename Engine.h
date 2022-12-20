//
// Created by nikita on 12/2/22.
//
#pragma once

#include "SFML/Graphics.hpp"
#include "Vadim.h"

struct Program {
    sf::RenderWindow Window;
    sf::Sprite BackSprite;
    sf::Texture BackTexture;
    sf::Image MapImage;
};

//Инициализирует поля структуры gameMap работает с указателем на gameMap

void input(Vadim *vadim, Program *program, Vadim *student);

void update(float time, Vadim *vadim, Vadim *student);

void draw(Program *program, Vadim *vadim, Vadim *student);

void start(Vadim *vadim, Program *program, Vadim *student);

void initEngine(Program *program);