
#ifndef PR1_1_TRAIN_H
#define PR1_1_TRAIN_H

#include <iostream>
#include <fstream>

struct train {
    int length;
};

bool ReadTrain(train&tr, std::ifstream& stream);
void OutTrain(std::ofstream& stream, train &tr);

#endif //PR1_1_TRAIN_H
