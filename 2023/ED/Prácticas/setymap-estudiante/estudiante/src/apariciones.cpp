//
// Created by julia on 15/11/23.
//
#include "../include/dictionary.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 3) {
        cout << "Error. Número incorrecto de parámetros " << endl;
        cout << "Uso: apariciones [fichero con palabras] [caracter a buscar]" << endl;
        exit(1);
    }

    Dictionary dic;

    char *origen;
    char c;

    // Obtener argumentos
    origen = argv[1];
    c = argv[2][0];

    // Mostrar argumentos
    cout << endl;
    cout << "Fichero de origen: " << origen << endl;
    cout << "Número de ocurrencias del caracter: " << c << endl;

    // Añadir palabras de origen a dic
    ifstream fichero(origen);
    string palabra;
    while (fichero >> palabra) {
        dic.insert(palabra);
    }
    // Número de ocurrencias del caracter
    int n = dic.getOcurrances(c);
    cout << endl;
    cout << "Número de ocurrencias del caracter " << c << ": " << n << endl;

    return 0;
}