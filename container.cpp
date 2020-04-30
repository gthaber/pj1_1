
#include "container.h"

void Read_Container(std::ifstream &stream, container &c) {
    while(!stream.eof()) {
        transport *temp_tr = Read_Transport(stream);
        if (temp_tr == nullptr) return; // Если не считалось, то ошибка
        element *el = new element{};
        el->t = temp_tr;
        containerAdd(el, c);
    }
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

void Out_Container(std::ofstream &stream, container &con, T_type but) {
    element *el = con.starting;
    for(int i = 0; i < con.size; i++) {
        if(el->t->tr_type != but) {
            stream << i+1 << ". ";
            Out_Transport(stream, el->t);
        }
        el = el->forward;
    }
}

