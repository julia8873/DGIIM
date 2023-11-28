//
// Created by andre on 19/11/2023.
//

#include <iostream>
#include <fstream>
#include "dictionary.h"

using namespace std;

int main(int argc, char* argv[]){

    if (argc != 3) {
        cout << "Error. Número incorrecto de parámetros " << endl;
        cout << "Uso: apariciones [fichero con palabras] [caracter a buscar]" << endl;
        exit(1);
    }

    ifstream f;
    f.open(argv[1]);
    Dictionary dict(f);

    char c = argv[2][0];
    cout << dict.getOccurrences(c) << endl;
}