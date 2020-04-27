
#ifndef PR1_1_TRAIN_H
#define PR1_1_TRAIN_H

#include <iostream>
#include <fstream>

struct train {
    int length;
};

inline bool Read_Train(train&tr, std::ifstream& stream);
inline void Out_Train(std::ofstream& stream, train &tr);

#endif //PR1_1_TRAIN_H
