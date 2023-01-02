#pragma once

#include "SFML/Graphics.hpp"


struct TextView{
    sf::Font font;
    sf::Text text;
    std::string info;
};

void initText(TextView *text_view, std::string information, sf::Vector2f position);

void updateText(TextView *text_view, std::string information);