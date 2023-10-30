/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author Julia Miralles
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include <queue>

#include <maxstack.h>

using namespace std;

/********************************
       FUNCIONES PÚBLICAS
********************************/

bool MaxStack::empty() const{
    return q.empty();
}

int MaxStack::get_size() const{
    return q.size();
}

element MaxStack::top() const{
    return q.front();
}

void MaxStack::pop(){
    q.pop();
}

void MaxStack::push(int n){
    queue<element> tmp;
    element elem;
    elem.value = n;

    // Asignamos el máximo al nuevo elemento introducido
    int max = (n > top().maximum)? n: top().maximum;
    elem.maximum = max;

    tmp.push(elem);

    while(!empty()){
        tmp.push(top());
        q.pop();
    }

    q = tmp;
}

