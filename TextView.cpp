#include "TextView.h"
#include "Engine.h"
using namespace sf;

void initText(TextView *text_view, std::string information, Vector2f position) {
    text_view->font.loadFromFile("fonts/Roboto-Light.ttf");
    Text text("", text_view->font, 50);
    text.setColor(Color(2, 48, 71, 255));
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text_view->info = information;
    text.setString(text_view->info);
    text.setPosition(position);
    text.setStyle(text.Regular);
    text_view->text = text;
}

void updateText(TextView *text_view, std::string information){
    text_view->info = information;
    text_view->text.setString(text_view->info);
}