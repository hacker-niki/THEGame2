//
// Created by nikita on 12/3/22.
//
#include "Engine.h"

void draw(Program *program, Vadim *vadim, Vadim *student) {

    program->Window.clear(sf::Color::White);

//    program->Window.draw(program->BackSprite);


    program->Window.draw(vadim->sprite);

    program->Window.draw(student->sprite);

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    program->Window.display();
}