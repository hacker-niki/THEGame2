#include "Engine.h"
#include "Vadim.h"

int main() {

    Vadim vadim = initVadim();
    Vadim student = initStudent();

    Program program;

    initEngine(&program);

    glEnable(GL_TEXTURE_2D);

    start(&vadim, &program, &student);

    return 0;
}