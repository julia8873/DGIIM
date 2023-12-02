//
// Created by julia on 28/11/23.
//

#include "punto.h"
#include <string>
#include <cmath>

using namespace std;

Punto::Punto():latitud(0), longitud(0){}

Punto::Punto(int lat, int lon, string desc):latitud(lat), longitud(lon), descripción(desc){}

int Punto::getLatitud(){
    return latitud;
}

int Punto::getLongitud(){
    return longitud;
}

string Punto::getDescripcion(){
    return descripcion;
}

void Punto::setLatitud(int lat){
    latitud = lat;
}

void Punto::setLongitud(int lon){
    longitud = lon;
}

void Punto::setDescripcion(std::string desc){
    descripcion = desc;
}

double Punto::distancia(Punto & otro){
    double dif = (latitud - otro.getLatitud())^2 * (longitud - otro.getLongitud())^2;
    return sqrt(dif);
}