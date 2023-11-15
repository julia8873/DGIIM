//
// Created by julia on 15/11/23.
//
#include "../include/guiatlf.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc <4) {
        cout << "Error. Número incorrecto de parámetros " << endl;
        cout << "Uso: modificar [fichero con guía] [nombre al que se va a modificar] [tlf nuevo]" << endl;
        exit(1);
    }

    Guia_Tlf guia;

    char *origen;
    string nombre, tlf;

    // Obtener argumentos
    origen = argv[1];
    for(int i=2; i<argc-1; ++i) {
        nombre += argv[i];
        nombre += " ";
    }
    nombre.pop_back();

    tlf = argv[argc-1];

    // Mostrar argumentos
    cout << endl;
    cout << "Fichero de origen: " << origen << endl;
    cout << "Nombre a modificar: " << nombre << endl;
    cout << "Tlf nuevo: " << tlf << endl;

    // Añadimos valores a las guias
    ifstream fichero(origen);
    while(fichero >> guia);

    // Modificar télefono
    guia.modificarTlf(nombre, tlf);
    cout << "Guia modificada: " << endl;
    cout << guia << endl;

    return 0;
}