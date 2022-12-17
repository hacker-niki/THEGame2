//
// Created by nikita on 12/3/22.
//
#include "Engine.h"

void draw(Program *program, Vadim *vadim, Vadim *student) {

    program->Window.clear(sf::Color::White);

//    program->Window.draw(program->BackSprite);

    drawMap(program);

    program->Window.draw(vadim->sprite);

    program->Window.draw(student->sprite);

    program->Window.display();
}