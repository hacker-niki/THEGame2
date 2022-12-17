//
// Created by nikita on 12/2/22.
//
#include "Engine.h"
#include "Vadim.h"

void update(float time, Vadim *vadim, Vadim *student) {
    vadimUpdate(time, vadim, student);
    vadimUpdate(time, student, vadim);
}