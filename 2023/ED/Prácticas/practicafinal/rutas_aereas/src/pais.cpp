//
// Created by julia on 28/11/23.
//

#include "pais.h"

using namespace std;

Pais::Pais(): p(Punto()), nombre(""), bandera("") {}

Pais::Pais(const Punto &p, const string &nombre, const string &bandera): p(p), nombre(nombre), bandera(bandera) {}

Punto Pais::getPunto() const {
    return p;
}

string Pais::getNombre() const {
    return nombre;
}

string Pais::getBandera() const {
    return bandera;
}

void Pais::setPunto(const Punto &p) {
    this->p = p;
}

void Pais::setNombre(const string &nombre) {
    this->nombre = nombre;
}

void Pais::setBandera(const string &bandera) {
    this->bandera = bandera;
}

std::ostream &operator<<(std::ostream &os, const Pais &p) {
    os << p.p << " " << p.nombre << " " << p.bandera;
    return os;
}

std::istream &operator>>(std::istream &is, Pais &p) {
    is >> p.p >> p.bandera;
    p.setNombre(p.getPunto().getDescripcion());
    return is;
}

bool operator==(const Pais & p1, const Pais & p2) {
    return (p1.getPunto() == p2.getPunto()) && (p1.getNombre() == p2.getNombre()) && (p1.getBandera() == p2.getBandera());
}

bool operator<(const Pais & p1, const Pais & p2) {
    return p1.getPunto() < p2.getPunto();
}
