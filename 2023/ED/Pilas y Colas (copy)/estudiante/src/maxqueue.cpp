/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author Julia Miralles
*/

#include <cstring>
#include <cassert>
#include <iostream>
#include <queue>

#include <maxqueue.h>

using namespace std;

/********************************
       FUNCIONES PÚBLICAS
********************************/

bool MaxQueue::empty() const{
    return s.empty();
}

int MaxQueue::get_size() const{
    return s.size();
}

element MaxQueue::front() const{
    return s.top();
}

void MaxQueue::pop(){
    s.pop();
}

void MaxQueue::push(int n){
    stack<element> tmp;

    element elem, elem_tmp;
    elem.value = n;
    elem.maximum = n;

    if(!empty()){
        bool cambiar_max = n > front().maximum;
        // volcamos pila a temporal
        while(!empty()){
            tmp.push(s.top());
            s.pop();
        }
        s.push(elem);

        // volvemos a volcar los elementos a s
        while (!tmp.empty()){
            elem_tmp.value = tmp.top().value;

            if(cambiar_max) elem_tmp.maximum = n;
            else elem_tmp.maximum = tmp.top().maximum;

            s.push(elem_tmp);
            tmp.pop();
        }
    }else s.push(elem);

}

