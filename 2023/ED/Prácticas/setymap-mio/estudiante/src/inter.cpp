//
// Created by julia on 15/11/23.
//
#include "../include/guiatlf.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 3) {
        cout << "Error. Número incorrecto de parámetros " << endl;
        cout << "Uso: inter [fichero con guía] [otro fichero con guía]" << endl;
        exit(1);
    }

    Guia_Tlf guia, guia_otro;

    char *origen, *otro;

    // Obtener argumentos
    origen = argv[1];
    otro = argv[2];

    // Mostrar argumentos
    cout << endl;
    cout << "Fichero de origen: " << origen << endl;
    cout << "Fichero a realizar interseccion: " << otro << endl;

    // Añadimos valores a las guias
    ifstream fichero(origen);
    while(fichero >> guia);
    ifstream fichero_otro(otro);
    while(fichero_otro >> guia_otro);

    // Intersección de guías
    Guia_Tlf interseccion = guia.interseccion(guia_otro);
    cout << "Interseccion: " << endl;
    cout << interseccion << endl;

    return 0;
}