//
// Created by nikita on 12/2/22.
//
#include "Engine.h"
#include "Vadim.h"

void input(Vadim *vadim, Program *program, Vadim *student) {

    //Движение Вадима
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        program->Window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        moveLeft(vadim, student);
    } else {
        stopLeft(vadim);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveRight(vadim, student);
    } else {
        stopRight(vadim);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        moveUp(vadim, student);
    } else {
        stopUp(vadim);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        moveDown(vadim, student);
    } else {
        stopDown(vadim);
    }

    //Движение студента
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        moveLeft(student, vadim);
    } else {
        stopLeft(student);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moveRight(student, vadim);
    } else {
        stopRight(student);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        moveUp(student, vadim);
    } else {
        stopUp(student);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        moveDown(student, vadim);
    } else {
        stopDown(student);
    }
}