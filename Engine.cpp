//
// Created by nikita on 12/2/22.
//

#include <iostream>
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

void start(Vadim *vadim, Program *program, Vadim *student, Dot *dot, TextView *player1_score, TextView *player2_score,
           TextView *frames_per_second) {
    sf::Clock clock;
    sf::Time dt = clock.restart();
    sf::Vector2i Display(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    int fps = 0;
    while (program->Window.isOpen()) {
        float time = dt.asSeconds();
//        std::cout << clock.getElapsedTime().asSeconds() << '\n';
        fps++;
        if (clock.getElapsedTime().asSeconds() >= 1) {
            frames_per_second->info = "FPS: " + std::to_string(fps);
            frames_per_second->text.setString(frames_per_second->info);
            fps = 0;
            clock.restart();
        }
        input(vadim, program, student);
        update(program, time, vadim, student, Display, dot, player1_score, player2_score, frames_per_second);
        if (player1_score->info == "Player1 score: 20" || player2_score->info == "Player2 score: 20") {
            program->Window.close();
            initEngine(program);
            program->Window.clear(sf::Color::White);
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
            TextView text;
            sf::Vector2f position;
            position.x = sf::VideoMode::getDesktopMode().width / 2 - 100;
            position.y = sf::VideoMode::getDesktopMode().height / 2;
            if (player1_score->info == "Player1 score: 20")
                initText(&text, "Player1 wins", position);
            else
                initText(&text, "Player2 wins", position);
            text.text.setColor(sf::Color::White);
            program->Window.draw(text.text);
            program->Window.display();
            while (true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    program->Window.close();
                    break;
                }
            }
            exit(0);
        }
//        draw( vadim, student, dot);
    }
}