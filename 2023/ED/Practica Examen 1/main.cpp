#include <iostream>
#include <queue>

using namespace std;

// Diseñar una función que dada una cola L devuelva otra cola R conteniendo los elementos repetidos de L.
// Si no hay elementos repetidos de R será la cola vacía

int main() {
    cout << "jopasfd"  << endl;
    queue<int> L;
    L.push(5);
    L.push(2);
    L.push(7);
    L.push(2);
    L.push(5);
    L.push(5);
    L.push(1);

    queue<int> R;
    queue<int> aux;

    while (!L.empty()) {
        int x = L.front();
        L.pop();
        bool repetido = false;
        if(L.empty()) break;
        aux = L;
        aux.pop();
        while(!aux.empty() && !repetido){
            if(aux.front() == x) {
                R.push(x);
                repetido = true;
            }
            aux.pop();
        }
    }

    cout << "Cola R: ";
    while (!R.empty()) {
        cout << R.front() << " ";
        R.pop();
    }


    return 0;
}
