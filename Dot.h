#pragma once

#include "SFML/Graphics.hpp"
#include "Vadim.h"

struct Dot {
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
    float size;
};

sf::Vector2f randomPosition(int height, int width);

void initDot(Dot *dot, int height, int width);

void dotUpdate(Dot *dot, int height, int width, Vadim *vadim);