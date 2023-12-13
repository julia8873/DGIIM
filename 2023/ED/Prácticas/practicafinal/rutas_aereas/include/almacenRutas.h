//
// Created by julia on 28/11/23.
//

#ifndef PRACTICAFINAL_ALMACENRUTAS_H
#define PRACTICAFINAL_ALMACENRUTAS_H

#include "ruta.h"
#include "punto.h"

#include <string>
#include <map>
#include <utility>
#include <iostream>

class AlmacenRutas {
private:
    std::map<std::string, Ruta> rutas;
    //std::multimap<Punto, std::string> puntos;
public:

    /**
     * @brief Constructor por defecto.
    */
    AlmacenRutas();

    /**
     * @brief Constructor con un conjunto de rutas.
     * @param rutas conjunto de rutas.
    */
    AlmacenRutas(const std::map<std::string, Ruta> &rutas);

    /**
     * @brief Clase Iterador para recorrer las rutas.
    */
    class iterator {
    private:
        std::map<std::string, Ruta>::iterator it;
    public:
        iterator(const std::map<std::string, Ruta>::iterator &it){this->it = it;};
        iterator &operator++(){ ++it; return *this;};
        iterator &operator--(){ --it; return *this;};
        std::pair<const std::string, Ruta> & operator*(){return (*it);};
        bool operator==(const iterator &it) const{return this->it == it.it;};
        bool operator!=(const iterator &it) const{return this->it != it.it;};
    };

    /**
     * @brief Clase Iterador constante para recorrer las rutas.
    */
    class const_iterator {
    private:
        std::map<std::string, Ruta>::const_iterator it;
    public:
        const_iterator(const std::map<std::string, Ruta>::const_iterator &it){this->it = it;};
        const_iterator &operator++(){ ++it; return *this;};
        const_iterator &operator--(){ --it; return *this;};
        const std::pair<std::string, Ruta> & operator*() const{return (*it);};
        bool operator==(const const_iterator &it) const{return this->it == it.it;};
        bool operator!=(const const_iterator &it) const{return this->it != it.it;};
    };

    /**
     * @brief Primer elemento del conjunto de rutas.
     * @return iterador al primer elemento del conjunto de rutas.
    */
    iterator begin();

    /**
     * @brief Elemento siguiente al último del conjunto de rutas.
     * @return iterador al elemento siguiente al último del conjunto de rutas.
    */
    iterator end();

    /**
     * @brief Primer elemento del conjunto de rutas.
     * @return iterador constante al primer elemento del conjunto de rutas.
    */
    const_iterator cbegin() const;

    /**
     * @brief Elemento siguiente al último del conjunto de rutas.
     * @return iterador constante al elemento siguiente al último del conjunto de rutas.
    */
    const_iterator cend() const;

    /**
     * @brief Insertar una ruta en el conjunto de rutas.
     * @param ruta ruta a insertar.
     * @return pair con un iterador a la ruta insertada y un booleano que indica si se ha insertado o no.
    */
    std::pair<iterator, bool> insert(const std::pair<std::string, Ruta> &p);

    /**
     * @brief Eliminar una ruta del conjunto de rutas.
     * @param ruta ruta a eliminar.
     * @return número de elementos eliminados.
    */
    int erase(const std::string &ruta);

    /**
     * @brief Establece el conjunto de rutas.
     * @param rutas conjunto de rutas.
    */
    void setRutas(const std::map<std::string, Ruta> &rutas);

    /**
     * @brief Sobrecarga del operador de salida.
     * @param os flujo de salida.
     * @param rutas conjunto de rutas.
     * @return flujo de salida.
    */
    friend std::ostream &operator<<(std::ostream &os, const AlmacenRutas &rutas);

    /**
     * @brief Sobrecarga del operador de entrada.
     * @param is flujo de entrada.
     * @param rutas conjunto de rutas.
     * @return flujo de entrada.
    */
    friend std::istream &operator>>(std::istream &is, AlmacenRutas &rutas);
};

#endif //PRACTICAFINAL_ALMACENRUTAS_H