#include "Dot.h"
#include "cmath"

sf::Vector2f randomPosition(int height, int width) {
    sf::Vector2f ans;
    ans.x = rand() % width;
    ans.y = rand() % height;
    return ans;
}

void initDot(Dot *dot, int height, int width) {
    dot->position = randomPosition(height, width);
    dot->texture.loadFromFile("images/dot.png");
    dot->size = 50;
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
    if ((distance_vadim_dot <= dot->size + vadim->size && position_vadim.x < position_dot.x)) {
        vadim->counter++;
        dot->sprite.setPosition(randomPosition(height, width));
    }
}