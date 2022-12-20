//
// Created by nikita on 12/2/22.
//

#include "Engine.h"

void initEngine(Program *program) {
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    program->Window.create(sf::VideoMode(resolution.x, resolution.y),
                           "Vadim game",
                           sf::Style::Fullscreen);
    program->BackSprite.setColor(sf::Color(0, 0, 255, 100));
}

void start(Vadim *vadim, Program *program, Vadim *student) {
    sf::Clock clock;
    while (program->Window.isOpen()) {
        sf::Time dt = clock.restart();
        float time = dt.asSeconds();
        input(vadim, program, student);
        update(time, vadim, student);
        draw(program, vadim, student);
    }
}