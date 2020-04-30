
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
