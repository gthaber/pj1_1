
#include "transport.h"

void Read_Container(std::ifstream &stream, container &c) {
    while(!stream.eof()) {
        transport *temp_tr = Read_Transport(stream);
        if (temp_tr == nullptr) return; // Если не считалось, то ошибка
        element *el = new element{};
        el->t = temp_tr;
        containerAdd(el, c);
    }
}

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

void containerAdd(element *el, container&con) {
    con.size++;
    if(con.starting == nullptr) {
        con.starting = con.ending = el;
    } else {
        con.ending->forward = el;
        con.ending = el;
        el->forward = con.starting;
    }
}

void containerInit(container &con) {
    con.size = 0;
    con.starting = con.ending = nullptr;
}

void containerClear(container &con) {
    element *el = con.starting;
    for(int i = 0; i < con.size; i++) {
        delete el->t;
        element *next = el->forward;
        delete el;
        el = next;
    }
}

void Out_Container(std::ofstream &stream, container &con) {
    element *el = con.starting;
    for(int i = 0; i < con.size; i++) {
        stream << i+1 << ". ";
        Out_Transport(stream, el->t);
        el = el->forward;
    }
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
