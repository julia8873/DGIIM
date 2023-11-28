/**
 *
 * @brief Reto 3
 * @autor Andrés Alejo Martínez
 * @author Julia Miralles Martínez
 * @author Nuria Ruiz Arroyo
 * @title Reto 3
 */


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <iterator>
#include <set>

using namespace std;
typedef pair<int, int> intervalo;

ostream & operator<<(ostream & os, const intervalo & i) {
    os << "[" << i.first << ", " << i.second << "]";
    return os;
}

ostream & operator<<(ostream & os, const list<intervalo> & i) {
    for(list<intervalo>::const_iterator it = i.begin(); it != i.end(); ++it)
        os << (*it) << " ";
    return os;
}

/**
 * @brief Extrae un intervalo de una lista de intervalos y lo añade a otra lista de intervalos.
 * @param L1 Lista de intervalos de la que se extrae el intervalo.
 * @param x Intervalo a extraer y añadir.
 * @param L2 Lista de intervalos a la que se añade el intervalo.
 * @return True si se ha podido extraer el intervalo (x tiene que estar incluido en un intervalo de L1), false en caso contrario.
*/

bool Extraer(list<intervalo> &L1, intervalo x, list<intervalo> &L2) {

    // Comprobar que x está dentro de algún intervalo de L1
    list<intervalo>::iterator it = L1.begin();
    bool encontrado = false;

    while(it!=L1.end() && !encontrado) {
        if((*it).first <= x.first && x.second <= (*it).second) {
            encontrado = true;
            // Extraer x de L1
            if((*it).first == x.first && (*it).second == x.second) L1.erase(it);
            else if((*it).first == x.first) (*it).first = x.second + 1;
            else if((*it).second == x.second) (*it).second = x.first - 1;
            else {
                L1.insert(it, intervalo((*it).first, x.first-1));
                (*it).first = x.second+1;
            }
        } else ++it;
    }

    set<intervalo> aux = set<intervalo>(L2.begin(), L2.end());
    aux.insert(x);
    
    set<intervalo>::iterator it1_s = aux.begin(), it2_s = it1_s;
    ++it2_s;
    while(it2_s != aux.end()) {
        if(it1_s -> second >= it2_s -> first){
            intervalo inter = *it1_s;
            if(it1_s -> second < it2_s -> second)
                inter.second = it2_s -> second;
            aux.erase(it2_s);
            aux.erase(it1_s);
            it1_s = aux.insert(inter).first;
            it2_s = it1_s;
            ++it2_s;
        } else if(it2_s != aux.end()) {
            ++it1_s;
            ++it2_s;
        }
    }

    L2 = list<intervalo>(aux.begin(), aux.end());

    return encontrado;
}

int main(int argc, char *argv[]){
    
    list<intervalo> L1;
    L1.push_back(intervalo(1,7));
    L1.push_back(intervalo(10,14));
    L1.push_back(intervalo(18,20));
    L1.push_back(intervalo(25,26));

    list<intervalo> L2;
    L2.push_back(intervalo(0,1));
    L2.push_back(intervalo(14,16));
    L2.push_back(intervalo(20, 23));

    intervalo x(12,14);

    cout << "x: " << x << endl;
    cout << "L1: " << L1 << endl;
    cout << "L2: " << L2 << endl;
    
    bool result = Extraer(L1,x,L2);

    cout << endl;
    cout << "Listas modificadas:" << endl;
    if(result) {
        cout << "L1: " << L1 << endl;
        cout << "L2: " << L2 << endl;
    } else {
        cout << "No es posible extraer el intervalo x de la lista L1" << endl; 
        cout << "L2: " << L2 << endl;
    }
    return 0;
}
