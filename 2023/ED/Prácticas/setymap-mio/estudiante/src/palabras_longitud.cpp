//
// Created by julia on 15/11/23.
//

#include "../include/dictionary.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){

    if(argc != 3){
        cout << "Error. Número incorrecto de parámetros " << endl;
        cout << "Uso: palabras_longitud [fichero con palabras] [entero con longitud de palabra a buscar]" << endl;
        exit(1);
    }

    Dictionary dic;

    char *origen;
    int longitud;

    // Obtener argumentos
    origen = argv[1];
    longitud = atoi(argv[2]);

    // Mostrar argumentos
    cout << endl;
    cout << "Fichero de origen: " << origen << endl;
    cout << "Longitud de palabra a buscar: " << longitud << endl;

    // Añadir palabras de origen a dic
    ifstream fichero(origen);
    string palabra;
    while(fichero >> palabra){
        dic.insert(palabra);
    }
    // Coger las palabras de esa longitud
    vector<string> palabras = dic.wordsOfLength(longitud);
    cout << endl;
    cout << "Palabras de longitud " << longitud << ":" << endl;
    for(int i=0; i<palabras.size(); ++i){
        cout << palabras[i] << endl;
    }

    return 0;
}