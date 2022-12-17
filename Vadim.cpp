//
// Created by nikita on 12/1/22.
//

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

    vadim.speed = 300;
    vadim.size = 170;
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

    student.speed = 400;
    student.size = 170;
    student.position.x = 900;
    student.position.y = 900;
    student.sprite.setTexture(student.textureRight);

    return student;
}

void moveRight(Vadim *vadim) {
    vadim->moveRight = true;
}

void moveLeft(Vadim *vadim) {
    vadim->moveLeft = true;
}

void stopRight(Vadim *vadim) {
    vadim->moveRight = false;
}

void stopLeft(Vadim *vadim) {
    vadim->moveLeft = false;
}

void moveUp(Vadim *vadim) {
    vadim->moveUp = true;
}

void stopUp(Vadim *vadim) {
    vadim->moveUp = false;
}

void moveDown(Vadim *vadim) {
    vadim->moveDown = true;
}

void stopDown(Vadim *vadim) {
    vadim->moveDown = false;
}

void vadimUpdate(float time, Vadim *vadim, Vadim *student) {

    sf::Vector2f positionV;
    positionV.y = vadim->position.y - vadim->size;
    positionV.x = vadim->position.x - vadim->size;

    sf::Vector2f positionS;
    positionS.y = student->position.y - student->size;
    positionS.x = student->position.x - student->size;

    float rast = sqrt((positionV.x - positionS.x) * (positionV.x - positionS.x) +
                      (positionV.y - positionS.y) * (positionV.y - positionS.y));

//    std::cout << rast << ' ' << positionV.y << ' ' << positionV.x << ' ' << positionS.y << ' ' << positionS.x << '\n';

    if (vadim->moveRight && vadim->position.x < sf::VideoMode::getDesktopMode().width) {
        vadim->position.x += vadim->speed * time;
        vadim->sprite.setTexture(vadim->textureRight);
    } else if (vadim->moveLeft && vadim->position.x > vadim->size) {
        vadim->position.x -= vadim->speed * time;
        vadim->sprite.setTexture(vadim->textureLeft);

    } else if (vadim->moveUp && vadim->position.y > vadim->size) {
        vadim->position.y -= vadim->speed * time;
        vadim->sprite.setTexture(vadim->textureUp);

    } else if (vadim->moveDown && vadim->position.y < sf::VideoMode::getDesktopMode().height) {
        vadim->position.y += vadim->speed * time;
        vadim->sprite.setTexture(vadim->textureDown);
    }
    vadim->sprite.setPosition(positionV);
}

void studentUpdate(float time, Vadim *vadim) {
    if (vadim->moveRight && vadim->position.x < sf::VideoMode::getDesktopMode().width - vadim->size) {
        vadim->position.x += vadim->speed * time;
        vadim->sprite.setTexture(vadim->textureRight);
    }
    if (vadim->moveLeft && vadim->position.x > 0) {
        vadim->sprite.setTexture(vadim->textureLeft);
        vadim->position.x -= vadim->speed * time;
    }

    if (vadim->moveUp && vadim->position.y > 0) {
        vadim->sprite.setTexture(vadim->textureUp);
        vadim->position.y -= vadim->speed * time;
    }

    if (vadim->moveDown && vadim->position.y < sf::VideoMode::getDesktopMode().height - vadim->size) {
        vadim->sprite.setTexture(vadim->textureDown);
        vadim->position.y += vadim->speed * time;
    }
    vadim->sprite.setPosition(vadim->position);
}