//
// Created by julia on 15/11/23.
//
#include "../include/guiatlf.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc!=3) {
        cout << "Error. Número incorrecto de parámetros " << endl;
        cout << "Uso: filtro [fichero con guía] [string que es el comienzo de un nombre]" << endl;
        exit(1);
    }

    Guia_Tlf guia;

    char *origen;
    string nombre;

    // Obtener argumentos
    origen = argv[1];
    nombre = argv[2];

    // Mostrar argumentos
    cout << endl;
    cout << "Fichero de origen: " << origen << endl;
    cout << "Nombre comienza por: " << nombre << endl;

    // Añadimos valores a las guias
    ifstream fichero(origen);
    while(fichero >> guia);

    // Filtrar guías por nombres que comiencen por nombre
    Guia_Tlf filtrado = guia.empiezaPor(nombre);
    cout << "Filtrado: " << endl;
    cout << filtrado << endl;


    return 0;
}