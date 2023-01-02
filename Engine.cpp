//
// Created by nikita on 12/2/22.
//

#include "Engine.h"

void initEngine(Program *program) {
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    program->Window.create(sf::VideoMode(resolution.x, resolution.y),
                           "Vadim game",
                           sf::Style::Fullscreen,
                           settings);
    program->Window.setVerticalSyncEnabled(true);
    program->BackSprite.setColor(sf::Color(0, 0, 255, 100));
//    glEnable(GL_TEXTURE_2D);
}

void start(Vadim *vadim, Program *program, Vadim *student, Dot *dot, TextView *player1_score, TextView *player2_score) {
    sf::Clock clock;
    sf::Vector2i Display(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

    while (program->Window.isOpen()) {
        sf::Time dt = clock.restart();
        float time = dt.asSeconds();
        input(vadim, program, student);
        update(program, time, vadim, student, Display, dot, player1_score, player2_score);
//        draw( vadim, student, dot);
    }
}