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
        cout << "Uso: union [fichero origen con palabras] [fichero a unir con palabras]" << endl;
        exit(1);
    }

    Dictionary dic, dic_otro;

    char *origen, *otro;

    // Obtener argumentos
    origen = argv[1];
    otro = argv[2];

    // Mostrar argumentos
    cout << endl;
    cout << "Fichero de origen: " << origen << endl;
    cout << "Fichero a unir: " << otro << endl;

    // Añadir palabras de origen a dic
    ifstream fichero(origen);
    string palabra;
    while (fichero >> palabra) {
        dic.insert(palabra);
    }
    // Añadir palabras de otro a dic
    ifstream fichero_otro(otro);
    while (fichero_otro >> palabra) {
        dic_otro.insert(palabra);
    }

    // Unir diccionarios
    cout << "Longitud del diccionario de antes: " << dic.size() << endl;
    cout << "Longitud del diccionario a aniadir: " << dic_otro.size() << endl;
    dic.anade(dic_otro);
    cout << "Longitud del diccionario despues: " << dic.size() << endl;
    cout << "Diccionario unido: " << endl;
    dic.toString();

    return 0;
}