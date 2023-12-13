//
// Created by julia on 28/11/23.
//

#include "punto.h"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

Punto::Punto():latitud(0), longitud(0){}

Punto::Punto(double lat, double lon, string desc):latitud(lat), longitud(lon), descripcion(desc){}

double Punto::getLatitud() const {
    return latitud;
}

double Punto::getLongitud() const{
    return longitud;
}

string Punto::getDescripcion() const{
    return descripcion;
}

void Punto::setLatitud(double lat){
    latitud = lat;
}

void Punto::setLongitud(double lon){
    longitud = lon;
}

void Punto::setDescripcion(std::string desc){
    descripcion = desc;
}

double Punto::distancia(Punto & otro){
    double dif = (latitud - otro.getLatitud())^2 * (longitud - otro.getLongitud())^2;
    return sqrt(dif);
}

bool Punto::operator<(const Punto & otro) const{

}

bool Punto::operator==(const Punto & otro) const{
    return (latitud == otro.getLatitud() && longitud == otro.getLongitud() && descripcion == otro.getDescripcion());
}

ostream & operator<<(ostream & os, const Punto &p){
    os <<p.getDescripcion() <<"("<< p.getLatitud() << "," << p.getLongitud() << ")";
    return os;
}

istream & operator>>(istream & is, Punto &p){
    int lat, lon;
    string desc;
    is >> lat >> lon >> desc;
    p.setLatitud(lat);
    p.setLongitud(lon);
    p.setDescripcion(desc);
    return is;
}

