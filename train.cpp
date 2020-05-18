#include "train.h"

bool ReadTrain(train&tr, std::ifstream &stream) {
    if(!stream.eof())
        stream >> tr.length;
    else return false;
    return true;
}

void OutTrain(std::ofstream &stream, train &tr) {
    stream << "; Length: " << tr.length << ";" << std::endl;
}
