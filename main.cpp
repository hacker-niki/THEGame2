#include "Engine.h"
#include "Vadim.h"

int main() {

    Vadim vadim = initVadim();
    Vadim student = initStudent();

    Program program;

    initEngine(&program);

    start(&vadim, &program, &student);

    return 0;
}