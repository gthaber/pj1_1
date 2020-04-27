
#include "transport.h"


transport *Read_Transport(std::ifstream &stream) {
    int type;
    stream >> type;
    if(type < 1 || type > 2) {
        std::cout << "Input error." << std::endl;
        return nullptr;
    }
    transport* temp_t = nullptr;
    switch (type) {
        case T_type::PLANES:
            temp_t = new transport{};
            Read_Plane(temp_t->u.pl, stream);
            temp_t->tr_type = T_type::PLANES;
            break;
        case T_type::TRAIN:
            temp_t = new transport{};
            Read_Train(temp_t->u.tr, stream);
            temp_t->tr_type = T_type::TRAIN;
            break;
        default:
            return temp_t;
    }
    if(!stream.eof()) stream >> temp_t->speed;
    else delete temp_t;
    if(!stream.eof()) stream >> temp_t->distance;
    else delete temp_t;
    return temp_t;
}

bool Read_Plane(planes&pl, std::ifstream &stream) {
    if(!stream.eof())
        stream >> pl.range;
    else return false;
    if(!stream.eof())
        stream >> pl.carry;
    else return false;
    return true;
}

bool Read_Train(train&tr, std::ifstream &stream) {
    if(!stream.eof())
        stream >> tr.length;
    else return false;
    return true;
}

void Out_Transport(std::ofstream &stream, transport *tran) {
    stream << "Speed: " << tran->speed << "; Distance: " << tran->distance << "; Type: ";
    switch (tran->tr_type) {
        case T_type::PLANES:
            stream << "Planes";
            Out_Planes(stream, tran->u.pl);
            break;
        case T_type::TRAIN:
            stream << "Train";
            Out_Train(stream, tran->u.tr);
            break;
    }
}

void Out_Planes(std::ofstream &stream, planes &pl) {
    stream << "; Range: " << pl.range << "; Carry: " << pl.carry << ";" << std::endl;
}

void Out_Train(std::ofstream &stream, train &tr) {
    stream << "; Length: " << tr.length << ";" << std::endl;
}
