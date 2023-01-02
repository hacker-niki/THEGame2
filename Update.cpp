#include "Engine.h"
#include "Vadim.h"

void update(Program *program, float time, Vadim *vadim, Vadim *student, sf::Vector2i Display, Dot *dot,
            TextView *player1_score, TextView *player2_score) {

    program->Window.clear(sf::Color::White);

    vadimUpdate(time, vadim, student, Display);
    program->Window.draw(vadim->sprite);

    for (int i = 0; i < 5; i++)
        dotUpdate(&(dot[i]), Display.y, Display.x, vadim);

    vadimUpdate(time, student, vadim, Display);
    program->Window.draw(student->sprite);

    for (int i = 0; i < 5; i++)
        dotUpdate(&(dot[i]), Display.y, Display.x, student);

    for (int i = 0; i < 5; i++)
        program->Window.draw((dot[i]).sprite);

    updateText(player1_score, "Player1 score: " + std::to_string(vadim->counter));

    updateText(player2_score, "Player2 score: " + std::to_string(student->counter));

    program->Window.draw(player1_score->text);

    program->Window.draw(player2_score->text);

    program->Window.display();
}