#include <cmath>
#include <iostream>
#include "Vadim.h"

Vadim initVadim() {
    Vadim vadim;

    vadim.textureRight.loadFromFile("images/round.png");
    vadim.textureLeft.loadFromFile("images/round.png");
    vadim.textureUp.loadFromFile("images/round.png");
    vadim.textureDown.loadFromFile("images/round.png");

    vadim.textureRight.setSmooth(true);
    vadim.textureLeft.setSmooth(true);
    vadim.textureUp.setSmooth(true);
    vadim.textureDown.setSmooth(true);

    vadim.counter = 0;
    vadim.speed = 10;
    vadim.size = 85;
    vadim.position.x = 300;
    vadim.position.y = 300;
    vadim.sprite.setTexture(vadim.textureRight);

    return vadim;
}

Vadim initStudent() {
    Vadim student;

    student.textureRight.loadFromFile("images/roundg.png");
    student.textureLeft.loadFromFile("images/roundg.png");
    student.textureUp.loadFromFile("images/roundg.png");
    student.textureDown.loadFromFile("images/roundg.png");

    student.textureRight.setSmooth(true);
    student.textureLeft.setSmooth(true);
    student.textureUp.setSmooth(true);
    student.textureDown.setSmooth(true);

    student.speed = 10;
    student.size = 85;
    student.position.x = 900;
    student.position.y = 900;
    student.sprite.setTexture(student.textureRight);

    return student;
}

#include "Engine.h"

void moveRight(Vadim *vadim, Vadim *student, float rast) {
    sf::Vector2f positionV;
    positionV.y = vadim->position.y - 2 * vadim->size;
    positionV.x = vadim->position.x - 2 * vadim->size;

    sf::Vector2f positionS;
    positionS.y = student->position.y - 2 * student->size;
    positionS.x = student->position.x - 2 * student->size;

    if ((rast <= 2 * vadim->size && positionV.x < positionS.x))
        vadim->moveRight = false;
    else
        vadim->moveRight = true;
}

void moveLeft(Vadim *vadim, Vadim *student, float rast) {

    sf::Vector2f positionV;
    positionV.y = vadim->position.y - 2 * vadim->size;
    positionV.x = vadim->position.x - 2 * vadim->size;

    sf::Vector2f positionS;
    positionS.y = student->position.y - 2 * student->size;
    positionS.x = student->position.x - 2 * student->size;

    if ((rast <= 2 * vadim->size && positionV.x > positionS.x))
        vadim->moveLeft = false;
    else
        vadim->moveLeft = true;
}

void stopRight(Vadim *vadim) {
    vadim->moveRight = false;
}

void stopLeft(Vadim *vadim) {
    vadim->moveLeft = false;
}

void moveUp(Vadim *vadim, Vadim *student, float rast) {

    sf::Vector2f positionV;
    positionV.y = vadim->position.y - 2 * vadim->size;
    positionV.x = vadim->position.x - 2 * vadim->size;

    sf::Vector2f positionS;
    positionS.y = student->position.y - 2 * student->size;
    positionS.x = student->position.x - 2 * student->size;

    if ((rast <= 2 * vadim->size && positionV.y > positionS.y))
        vadim->moveUp = false;
    else
        vadim->moveUp = true;
}

void stopUp(Vadim *vadim) {
    vadim->moveUp = false;
}

void moveDown(Vadim *vadim, Vadim *student, float rast) {

    sf::Vector2f positionV;
    positionV.y = vadim->position.y - 2 * vadim->size;
    positionV.x = vadim->position.x - 2 * vadim->size;

    sf::Vector2f positionS;
    positionS.y = student->position.y - 2 * student->size;
    positionS.x = student->position.x - 2 * student->size;

    if ((rast <= 2 * vadim->size && positionV.y < positionS.y))
        vadim->moveDown = false;
    else
        vadim->moveDown = true;
}

void stopDown(Vadim *vadim) {

    vadim->moveDown = false;
}


void vadimUpdate(float time, Vadim *vadim, Vadim *student, sf::Vector2i Display) {

    sf::Vector2f positionV;
    positionV.y = vadim->position.y - 2 * vadim->size;
    positionV.x = vadim->position.x - 2 * vadim->size;

    sf::Vector2f positionS;
    positionS.y = student->position.y - 2 * student->size;
    positionS.x = student->position.x - 2 * student->size;

    float rast = sqrt((positionV.x - positionS.x) * (positionV.x - positionS.x) +
                      (positionV.y - positionS.y) * (positionV.y - positionS.y));
    if (rast < 2 * vadim->size) {

    }
//    std::cout << rast << ' ' << positionV.y << ' ' << positionV.x << ' ' << positionS.y << ' ' << positionS.x << '\n';

    if (vadim->moveRight && vadim->position.x < Display.x) {
        vadim->position.x += vadim->speed/* * time*/;
        vadim->sprite.setTexture(vadim->textureRight);

    } else if (vadim->moveLeft && vadim->position.x > 2 * vadim->size) {
        vadim->position.x -= vadim->speed/* * time*/;
        vadim->sprite.setTexture(vadim->textureLeft);

    } else if (vadim->moveUp && vadim->position.y > 2 * vadim->size) {
        vadim->position.y -= vadim->speed/* * time*/;
        vadim->sprite.setTexture(vadim->textureUp);

    } else if (vadim->moveDown && vadim->position.y < Display.y) {
        vadim->position.y += vadim->speed/* * time*/;
        vadim->sprite.setTexture(vadim->textureDown);
    }
    vadim->sprite.setPosition(positionV);
}

void studentUpdate(float time, Vadim *vadim, sf::Vector2i Display) {
    if (vadim->moveRight && vadim->position.x < Display.x - 2 * vadim->size) {
        vadim->position.x += vadim->speed/* * time*/;
        vadim->sprite.setTexture(vadim->textureRight);
    }
    if (vadim->moveLeft && vadim->position.x > 0) {
        vadim->sprite.setTexture(vadim->textureLeft);
        vadim->position.x -= vadim->speed/* * time*/;
    }

    if (vadim->moveUp && vadim->position.y > 0) {
        vadim->sprite.setTexture(vadim->textureUp);
        vadim->position.y -= vadim->speed/* * time*/;
    }

    if (vadim->moveDown && vadim->position.y < Display.y - 2 * vadim->size) {
        vadim->sprite.setTexture(vadim->textureDown);
        vadim->position.y += vadim->speed/* * time*/;
    }
    vadim->sprite.setPosition(vadim->position);
}