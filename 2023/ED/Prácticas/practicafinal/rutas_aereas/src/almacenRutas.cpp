//
// Created by julia on 28/11/23.
//

#include "almacenRutas.h"

using namespace std;

AlmacenRutas::AlmacenRutas(): rutas(map<string, Ruta>()){}

AlmacenRutas::AlmacenRutas(const map<string, Ruta> &rutas) : rutas(rutas){}

AlmacenRutas::iterator AlmacenRutas::begin(){
    return iterator(rutas.begin());
}

AlmacenRutas::iterator AlmacenRutas::end(){
    return iterator(rutas.end());
}

AlmacenRutas::const_iterator AlmacenRutas::cbegin() const{
    return const_iterator(rutas.cbegin());
}

AlmacenRutas::const_iterator AlmacenRutas::cend() const{
    return const_iterator(rutas.cend());
}

pair<AlmacenRutas::iterator, bool> AlmacenRutas::insert(const std::pair<std::string, Ruta> &p){
    pair<map<string, Ruta>::iterator, bool> ret = rutas.insert(p);
    return pair<AlmacenRutas::iterator, bool>(iterator(ret.first), ret.second);
}

int AlmacenRutas::erase(const std::string &ruta){
    return rutas.erase(ruta);
}

void AlmacenRutas::setRutas(const std::map<std::string, Ruta> &rutas){
    this->rutas = rutas;
}

std::ostream &operator<<(std::ostream &os, const AlmacenRutas &rutas) {
    for (auto it = rutas.rutas.cbegin(); it != rutas.rutas.cend(); ++it) {
        os << it->first << ": " << it->second << endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, AlmacenRutas &rutas){
    string desc;
    Ruta ruta;
    while (is >> ruta) {
        rutas.insert(pair<string, Ruta>(ruta.getCode(), ruta));
    }
    return is;
}
