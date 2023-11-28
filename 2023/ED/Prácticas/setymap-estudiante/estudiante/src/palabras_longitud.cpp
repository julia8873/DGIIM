//
// Created by andre on 19/11/2023.
//

#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ostream & operator<<(ostream &os, vector<string> v){
    for(auto it = v.begin(); it != v.end(); ++it)
        os << (*it) << endl;
    return os;
}

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Argumentos inválidos." << endl;
        return 1;
    }

    ifstream f;
    f.open(argv[1]);
    Dictionary dict(f);

    int length = atoi(argv[2]);
    vector<string> palabras = dict.wordsOfLength(length);
    cout << palabras << endl;
}