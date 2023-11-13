#include <iostream>
#include <list>
#include <utility>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> intervalo;

bool Extraer(list<intervalo> &L1, intervalo x, list<intervalo> &L2){
    bool encontrado = false;

    // Convertir a lista de sets
    list<set<int>> L1_set;
    set<int>::iterator it1;
    set<int> x_aux, L2_set;
    for (int i = x.first; i <= x.second; ++i)  x_aux.insert(i);

    list<intervalo>::iterator itL1 = L1.begin(), itL2 = L2.begin();

    while(itL1 != L1.end() && itL2 != L2.end()){
        set<int> aux, dif1, dif2, temp2;
        for (int i = (*itL1).first; i <= (*itL1).second; ++i) aux.insert(i);
        if (x.first >= (*itL1).first && x.second <= (*itL1).second) {
            encontrado = true;
            set_difference(aux.begin(),  aux.find(*x_aux.begin()), x_aux.begin(), x_aux.end(), inserter(dif1, dif1.begin()));
            set_difference(aux.find(*x_aux.begin()),  aux.end(), x_aux.begin(), x_aux.end(), inserter(dif2, dif2.begin()));
            L1_set.push_back(dif1);
            aux = dif2;
        }
        L1_set.push_back(aux);
        // L2_set
        for (int i = (*itL2).first; i <= (*itL2).second; ++i)  L2_set.insert(i);
        // Unión con x_aux
        set_union(L2_set.begin(), L2_set.end(), x_aux.begin(), x_aux.end(), inserter(temp2, temp2.begin()));
        L2_set = temp2;
        ++itL1, ++itL2;
    }

    L1.clear(), L2.clear();
    for (list<set<int>>::iterator it = L1_set.begin(); it != L1_set.end(); ++it)
        L1.push_back(intervalo(*min_element((*it).begin(), (*it).end()), *max_element((*it).begin(), (*it).end())));

    for (auto it = L2_set.begin(); it != L2_set.end();) {
        int min = *it, max = min;
        for (++it; it != L2_set.end() && *it == max + 1; ++it) ++max;
        L2.push_back(intervalo(min, max));
    }

    return encontrado;
}

int main(int argc, char *argv[]){
    list<intervalo> L1;
    L1.push_back(intervalo(1, 7));
    L1.push_back(intervalo(10, 22));
    L1.push_back(intervalo(25, 26));

    list<intervalo> L2;
    L2.push_back(intervalo(0, 1));
    L2.push_back(intervalo(14, 16));
    L2.push_back(intervalo(20, 23));

    // Imprimir L1, L2 de antes
    cout << "x: " << 12 << " " << 20 << endl;
    cout << "L1 antes: ";
    for(list<intervalo>::iterator it = L1.begin(); it != L1.end(); ++it){
        cout << (*it).first << " " << (*it).second << " ";
    }
    cout << endl;

    cout << "L2: ";
    for(list<intervalo>::iterator it = L2.begin(); it != L2.end(); ++it){
        cout << (*it).first << " " << (*it).second << " ";
    }
    cout << endl;
    bool result = Extraer(L1, intervalo(12, 20), L2);

    // Imprimir L1, L2 y result
    cout << "L1: ";
    for(list<intervalo>::iterator it = L1.begin(); it != L1.end(); ++it){
        cout << (*it).first << " " << (*it).second << " ";
    }
    cout << endl;

    cout << "L2: ";
    for(list<intervalo>::iterator it = L2.begin(); it != L2.end(); ++it){
        cout << (*it).first << " " << (*it).second << " ";
    }
    cout << endl;

    cout << "result: " << result << endl;

    return 0;
}
