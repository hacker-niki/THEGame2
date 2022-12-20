//
// Created by nikita on 12/2/22.
//
#include <cmath>
#include "Engine.h"
#include "Vadim.h"

void input(Vadim *vadim, Program *program, Vadim *student) {

    sf::Vector2f positionV;
    positionV.y = vadim->position.y - vadim->size;
    positionV.x = vadim->position.x - vadim->size;

    sf::Vector2f positionS;
    positionS.y = student->position.y - student->size;
    positionS.x = student->position.x - student->size;

    float rast = sqrt((positionV.x - positionS.x) * (positionV.x - positionS.x) +
                      (positionV.y - positionS.y) * (positionV.y - positionS.y));

    //Движение Вадима
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        program->Window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        moveLeft(vadim, student, rast);
    } else {
        stopLeft(vadim);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveRight(vadim, student, rast);
    } else {
        stopRight(vadim);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        moveUp(vadim, student, rast);
    } else {
        stopUp(vadim);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        moveDown(vadim, student, rast);
    } else {
        stopDown(vadim);
    }

    //Движение студента
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        moveLeft(student, vadim, rast);
    } else {
        stopLeft(student);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moveRight(student, vadim, rast);
    } else {
        stopRight(student);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        moveUp(student, vadim, rast);
    } else {
        stopUp(student);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        moveDown(student, vadim, rast);
    } else {
        stopDown(student);
    }
}