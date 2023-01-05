#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include "Vadim.h"
#include "cmath"
#include "Dot.h"
#include "TextView.h"

struct Program {
    sf::RenderWindow Window;
    sf::Sprite BackSprite;
    sf::Texture BackTexture;
    sf::Image MapImage;
};

//Инициализирует поля структуры gameMap работает с указателем на gameMap

void input(Vadim *vadim, Program *program, Vadim *student);

void update(Program *program, float time, Vadim *vadim, Vadim *student, sf::Vector2i Display, Dot *dot, TextView *player1_score, TextView *player2_score, TextView *frames_per_second);

void draw(Program *program, Vadim *vadim, Vadim *student, Dot *dot);

void start(Vadim *vadim, Program *program, Vadim *student, Dot *dot, TextView *player1_score, TextView *player2_score, TextView *frames_per_second);

void initEngine(Program *program);