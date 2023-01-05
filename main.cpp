#include "Engine.h"

int main() {
    srand(time(nullptr));

    Vadim vadim = initVadim();
    Vadim student = initStudent();
    Dot dot[5];
    Program program;

    initEngine(&program);
    sf::Vector2f Display(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

    for (auto &i: dot)
        initDot(&i, Display.y, Display.x);

    glEnable(GL_TEXTURE_2D);

    TextView player1_score;
    sf::Vector2f player1_score_position;
    player1_score_position.x = 30;
    player1_score_position.y = 20;
    initText(&player1_score, "0", player1_score_position);

    TextView player2_score;
    sf::Vector2f player2_score_position;
    player2_score_position.x = sf::VideoMode::getDesktopMode().width - 400;
    player2_score_position.y = 20;
    initText(&player2_score, "0", player2_score_position);

    TextView frames_per_second;
    sf::Vector2f frames_per_second_position;
    frames_per_second_position.x = sf::VideoMode::getDesktopMode().width / 2 - 100;
    frames_per_second_position.y = 20;
    initText(&frames_per_second, "0", frames_per_second_position);

    start(&vadim, &program, &student, dot, &player1_score, &player2_score, &frames_per_second);

    return 0;
}