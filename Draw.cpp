#include "Engine.h"

void draw(Program *program, Vadim *vadim, Vadim *student, Dot *dot) {

    program->Window.clear(sf::Color(142, 202, 230, 255));

//    program->Window.draw(program->BackSprite);

    program->Window.draw(vadim->sprite);

    program->Window.draw(student->sprite);

    program->Window.draw(dot->sprite);

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    program->Window.display();
}