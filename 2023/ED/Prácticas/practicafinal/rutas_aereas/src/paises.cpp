//
// Created by julia on 3/12/23.
//

#include "paises.h"
#include <set>
#include <utility>

using namespace std;

Paises::Paises(): paises(set<Pais>()){}

Paises::Paises(const set<Pais> &paises) : paises(paises){}

set<Pais> Paises::getPaises() const {
    return paises;
}

void Paises::setPaises(const set<Pais> &paises) {
    this->paises = paises;
}

Paises::const_iterator Paises::begin() const {
    return const_iterator(paises.cbegin());
}

Paises::const_iterator Paises::end() const {
    return const_iterator(paises.cend());
}

Paises::const_iterator Paises::find(const Pais &pais) {
    return const_iterator(paises.find(pais));
}

pair<Paises::const_iterator, bool> Paises::insert(const Pais &pais) {
    pair<set<Pais>::iterator, bool> p = paises.insert(pais);
    return pair<Paises::const_iterator, bool>(const_iterator(p.first), p.second);
}

int Paises::erase(const Pais &pais) {
    return paises.erase(pais);
}

ostream &operator<<(std::ostream &os, const Paises &paises) {
    cout << "# Latitud\tLongitud\tPais\tBandera" << endl;
    for(auto it = paises.begin(); it != paises.end(); ++it){
        os << *it << endl;
    }
    return os;
}

istream &operator>>(std::istream &is, Paises &paises) {
    string linea;
    Pais pais;
    getline(is, linea);
    do{
        is >> pais;
        paises.insert(pais);
    } while(!is.eof());
    return is;
}