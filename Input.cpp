//
// Created by nikita on 12/2/22.
//
#include "Engine.h"
#include "Vadim.h"

void input(Vadim *vadim, Program *program, Vadim* student) {

    //Движение Вадима
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        program->Window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        moveLeft(vadim);
    } else {
        stopLeft(vadim);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveRight(vadim);
    } else {
        stopRight(vadim);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        moveUp(vadim);
    } else {
        stopUp(vadim);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        moveDown(vadim);
    } else {
        stopDown(vadim);
    }

    //Движение студента
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        moveLeft(student);
    } else {
        stopLeft(student);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moveRight(student);
    } else {
        stopRight(student);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        moveUp(student);
    } else {
        stopUp(student);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        moveDown(student);
    } else {
        stopDown(student);
    }
}