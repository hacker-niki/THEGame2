#pragma once

#include "SFML/Graphics.hpp"

#ifndef GUISML_VADIM_H
#define GUISML_VADIM_H

struct Vadim {

    sf::Vector2f position;
    sf::Texture textureLeft;
    sf::Texture textureRight;
    sf::Texture textureUp;
    sf::Texture textureDown;
    sf::Sprite sprite;

    float speedJump;
    float speed;
    float size;

    int counter;

    bool mudIsOk;
    bool otchislen = true;

    bool moveLeft = false;
    bool moveRight = false;
    bool moveDown = false;
    bool moveUp = false;
};

Vadim initVadim();

Vadim initStudent();

void moveRight(Vadim *vadim, Vadim *student, float rast);

void moveLeft(Vadim *vadim, Vadim *student, float rast);

void stopRight(Vadim *vadim);

void stopLeft(Vadim *vadim);

void stopUp(Vadim *vadim);

void moveUp(Vadim *vadim, Vadim *student, float rast);

void stopDown(Vadim *vadim);

void moveDown(Vadim *vadim, Vadim *student, float rast);

void vadimUpdate(float time, Vadim *vadim, Vadim *student, sf::Vector2i Display);

void studentUpdate(float time, Vadim *vadim);

#endif //GUISML_VADIM_H
