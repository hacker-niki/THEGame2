#include "Dot.h"
#include "cmath"
#include <iostream>

sf::Vector2f randomPosition(Dot *dot, int height, int width) {
    sf::Vector2f random_number;
    random_number.x = float((int) random() % int(width - 4 * (int) dot->size)) + 2 * dot->size;
    random_number.y = float((int) random() % int(height - 4 * (int) dot->size)) + 2 * dot->size;
//    std::cout << random_number.x << ' ' << random_number.y << '\n';
    return random_number;
}

void initDot(Dot *dot, int height, int width) {
    dot->texture.loadFromFile("images/dot.png");
    dot->size = 23;
    dot->position = randomPosition(dot, height, width);
    dot->sprite.setPosition(dot->position);
    dot->sprite.setTexture(dot->texture);
}

void dotUpdate(Dot *dot, int height, int width, Vadim *vadim) {
    sf::Vector2f position_vadim, position_dot;
    position_vadim.y = vadim->position.y - 2 * vadim->size;
    position_vadim.x = vadim->position.x - 2 * vadim->size;
    position_dot.y = dot->position.y - 2 * dot->size;
    position_dot.x = dot->position.x - 2 * dot->size;
    float distance_vadim_dot = sqrt((position_vadim.x - position_dot.x) * (position_vadim.x - position_dot.x) +
                                    (position_vadim.y - position_dot.y) * (position_vadim.y - position_dot.y));
    if (distance_vadim_dot <= (dot->size + vadim->size)) {
        vadim->counter++;
        dot->position = randomPosition(dot, height, width);
        dot->sprite.setPosition(dot->position);
    }
}