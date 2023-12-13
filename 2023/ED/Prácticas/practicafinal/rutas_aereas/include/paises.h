//
// Created by julia on 3/12/23.
//

#ifndef PRACTICAFINAL_PAISES_H
#define PRACTICAFINAL_PAISES_H

#include "pais.h"
#include <set>
#include <utility>

class Paises {
private:
    std::set<Pais> paises;
public:

    /**
     * @brief Constructor por defecto.
    */
    Paises();

    /**
     * @brief Constructor con un conjunto de países.
     * @param paises conjunto de países.
    */
    Paises(const std::set<Pais> &paises);

    /**
     * @brief Consultar el conjunto de países.
     * @return países.
    */
    std::set<Pais> getPaises() const;

    /**
     * @brief Establecer el conjunto de países.
     * @param paises conjunto de países a establecer.
    */
    void setPaises(const std::set<Pais> &paises);

    /**
     * @brief Clase const_iterator para iterar sobre los países.
    */
    class const_iterator {
    private:
        std::set<Pais>::const_iterator it;
    public:
        const_iterator(std::set<Pais>::const_iterator it){this->it = it;};
        const_iterator &operator++(){ ++it; return *this;};
        const_iterator &operator--(){ --it; return *this;};
        const Pais &operator*() const{return *it;};
        bool operator==(const const_iterator &it) const{return this->it == it.it;};
        bool operator!=(const const_iterator &it) const{return this->it != it.it;};
    };

    /**
     * @brief Primer elemento del conjunto de países.
     * @return iterador constante al primer elemento del conjunto de países.
    */
    Paises::const_iterator begin() const;

    /**
     * @brief Elemento siguiente del último del conjunto de países.
     * @return iterador constante al elemento siguiente del último del conjunto de países.
    */
    Paises::const_iterator end() const;

    /**
     * @brief Buscar un país en el conjunto de países.
     * @param pais país a buscar.
     * @return iterador constante al país buscado.
    */
    Paises::const_iterator find(const Pais &pais);

    /**
     * @brief Insertar un país en el conjunto de países.
     * @param pais país a insertar.
     * @return pair que contiene un iterador constante al elemento insertado y un booleano que indica si se ha insertado o no.
    */
    std::pair<Paises::const_iterator, bool> insert(const Pais &pais);

    /**
     * @brief Borrar un país del conjunto de países.
     * @param pais país a borrar.
     * @return número de elementos borrados.
    */
    int erase(const Pais &pais);

    /**
     * @brief Sobrecarga del operador de salida.
     * @param os flujo de salida.
     * @param paises conjunto de países a mostrar.
     * @return flujo de salida.
    */
    friend std::ostream &operator<<(std::ostream &os, const Paises &paises);

    /**
     * @brief Sobrecarga del operador de entrada.
     * @param is flujo de entrada.
     * @param paises conjunto de países a leer.
     * @return flujo de entrada.
    */
    friend std::istream &operator>>(std::istream &is, Paises &paises);
};

#endif //PRACTICAFINAL_PAISES_H