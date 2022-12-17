//
// Created by nikita on 9.12.22.
//

#include "Engine.h"
#include "iostream"

void initMap(gameMap *gMap) {
    sf::Image image;//объект изображения для карты
    image.loadFromFile("images/map.png");//загружаем файл для карты
    gMap->image = image;
    sf::Texture texture;//текстура карты
    texture.loadFromImage(image);//заряжаем текстуру картинкой
    gMap->texture = texture;
    gMap->texture.loadFromImage(gMap->image);
    sf::Sprite sprite;//создаём спрайт для карты
    sprite.setTexture(texture);//заливаем текстуру спрайтом
    gMap->sprite = sprite;
}

void drawMap(Program *program) {
    gameMap *gMap = &(program->gMap);
    for (int i = 0; i < gMap->HEIGHT_MAP; i++) {
        for (int j = 0; j < gMap->WIDTH_MAP; j++) {
            gMap->sprite.setTextureRect(
                    //если встретили символ пробел, то рисуем 1‑й квадратик
                    sf::IntRect(0, 0, 32, 32));

            //По сути раскидывает квадратики, превращая в карту. То есть задает каждому из них позицию. Если убрать,
            // то вся карта рисуется в одном квадрате 32*32 и мы увидим один квадрат
            gMap->sprite.setPosition(j * 32, i * 32);
//            std::cout << "1";
            program->Window.draw(gMap->sprite);
        }
    }
//    program->Window.draw(gMap->sprite);
}