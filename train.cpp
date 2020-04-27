#include "train.h"

bool Read_Train(train&tr, std::ifstream &stream) {
    if(!stream.eof())
        stream >> tr.length;
    else return false;
    return true;
}

void Out_Train(std::ofstream &stream, train &tr) {
    stream << "; Length: " << tr.length << ";" << std::endl;
}
