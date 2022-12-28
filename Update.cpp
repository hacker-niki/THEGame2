#include "Engine.h"
#include "Vadim.h"

void update(float time, Vadim *vadim, Vadim *student, sf::Vector2i Display, Dot *dot) {
    vadimUpdate(time, vadim, student, Display);
    dotUpdate(dot, Display.y, Display.x, vadim);
    vadimUpdate(time, student, vadim, Display);
    dotUpdate(dot, Display.y, Display.x, student);
}