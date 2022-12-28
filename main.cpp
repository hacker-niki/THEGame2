#include "Engine.h"

int main() {

    Vadim vadim = initVadim();
    Vadim student = initStudent();
    Dot dot;
    Program program;

    initEngine(&program);
    sf::Vector2f Display(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

    initDot(&dot, Display.y, Display.x);

    glEnable(GL_TEXTURE_2D);

    start(&vadim, &program, &student, &dot);

    return 0;
}