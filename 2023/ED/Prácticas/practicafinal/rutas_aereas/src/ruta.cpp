#include "ruta.h"
#include <list>
#include <string>

using namespace std;

Ruta::Ruta(){
    puntos = list<Punto>();
    code = "";
}

Ruta::Ruta(list<Punto> pts, string cod){
    puntos = pts;
    code = cod;
}

Ruta::iterator Ruta::insertar(Ruta::iterator pos,  Punto p){
    return Ruta::iterator(puntos.insert(pos.it, p));
}

Ruta::const_iterator Ruta::insertar(Ruta::const_iterator pos,  Punto p){
    return Ruta::const_iterator(puntos.insert(pos.it, p));
}

Ruta::const_iterator Ruta::begin(){
    return Ruta::iterator(puntos.begin());
}

Ruta::iterator Ruta::end(){
    return Ruta::iterator(puntos.end());
}

Ruta::const_iterator Ruta::cbegin() const{
    return Ruta::const_iterator(puntos.cbegin());
}

Ruta::const_iterator Ruta::cend() const{
    return Ruta::const_iterator(puntos.cend());
}

Ruta::iterator Ruta::borrar(Ruta::iterator p){
    return Ruta::iterator(puntos.erase(p.it));
}

Ruta::const_iterator Ruta::borrar(Ruta::const_iterator p){
    return Ruta::const_iterator(puntos.erase(p.it));
}

string Ruta::getCode() const{
    return code;
}

void Ruta::setCode(std::string code){
    this->code = code;
}

list<Punto> Ruta::getPuntos() const{
    return puntos;
}

bool operator==(Ruta r1, Ruta r2){
    return r1.getCode() == r2.getCode() && r1.getPuntos() == r2.getPuntos();
}

bool operator<(Ruta r1, Ruta r2){
    return r1.getPuntos().size() < r2.getPuntos().size();
}

ostream & operator <<(ostream & os, const Ruta & r){
    os << r.getCode() << " ";
    for(auto it = r.getPuntos().cbegin(); it != r.getPuntos().cend(); ++it){
        os << (*it) << " ";
    }
    return os;
}

istream & operator >>(istream & is, Ruta & r){
    // Leer el código
    string code;
    is >> code;
    r.setCode(code);

    // Leer los puntos
    int numPuntos;
    is >> numPuntos;
    Punto p;
    double lat, lon;
    for(int i = 0; i < numPuntos; ++i){
        char c;
        is >> c >> lat >> c >> lon >> c;
        p.setLatitud(lat);
        p.setLongitud(lon);

        r.insertar(r.end(), p);
    }
}
