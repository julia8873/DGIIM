//
// Created by andre on 19/11/2023.
//

#include "dictionary.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Argumentos erróneos." << endl;
        return 1;
    }

    ifstream f;
    f.open(argv[1]);
    Dictionary dict(f);

    ifstream f_unir;
    f.open(argv[2]);
    Dictionary dict_unir(f_unir);

    dict.anade(dict_unir);
    cout << dict << endl;
}