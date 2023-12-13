//
// Created by julia on 28/11/23.
//

#ifndef PRACTICAFINAL_RUTA_H
#define PRACTICAFINAL_RUTA_H

#include <punto.h>
#include <list>
#include <string>
#include <iostream>

class Ruta {
private:
    std::list<Punto> puntos;
    std::string code;

public:
    /**
     * @brief Constructor por defecto.
     */
    Ruta();

    /**
     * @brief Constructor con una lista de rutas.
     * @param pts puntos con los que inicializar la ruta.
     * @param cod código de la ruta.
     */
    Ruta(std::list<Punto> pts, std::string cod);

    /**
     * @brief Coger el código de la ruta.
     * @return código de la ruta.
     */
    std::string getCode() const;

    /**
     * @brief Establece el código de la ruta.
     * @param code código a introducir.
     */
    void setCode(std::string code);

    /**
    * @brief Coger la lista de puntos.
    * @return lista de puntos.
    */
    std::list<Punto> getPuntos() const;

    /**
     * @brief Clase para iterar sobre la lista de puntos.
     */

    class const_iterator {
    private:
        std::list<Punto>::const_iterator it;
    public:
        const_iterator(std::list<Punto>::const_iterator i){it = i;} //constructor
        const_iterator& operator++(){++it ; return *this;}
        const_iterator& operator--(){--it ; return *this;}
        bool operator ==(const const_iterator &i){return i.it == it;}
        bool operator !=(const const_iterator &i){return i.it != it;}
        const Punto & operator *() const {return *it;}
        friend class Ruta;
    };

    /**
     * @brief Clase para iterar sobre la lista de puntos.
     */
    class iterator {
    private:
        std::list<Punto>::iterator it;
    public:
        iterator(std::list<Punto>::iterator i){it = i;} //constructor
        iterator& operator++(){++it ; return *this;}
        iterator& operator--(){--it ; return *this;}
        bool operator ==(const iterator &i){return i.it == it;}
        bool operator !=(const iterator &i){return i.it != it;}
        Punto & operator *(){return *it;}
        friend class Ruta;
        friend class const_iterator;
    };

    /**
     * @brief Primer elemento de la ruta.
     * @return iterador apuntando al primer elemento de la ruta.
     */
    iterator begin();

    /**
     * @brief Elemento siguiente al último de la ruta.
     * @return iterador apuntando al elemento siguiente al último de la ruta.
     */
    iterator end();

    /**
     * @brief Primer elemento de la ruta.
     * @return iterador constante apuntando al primer elemento de la ruta.
     */
    const_iterator cbegin() const;

    /**
     * @brief Elemento siguiente al último de la ruta.
     * @return iterador constante apuntando al elemento siguiente al último de la ruta.
     */
    const_iterator cend() const;

    /**
     * @brief insertar un punto en la ruta.
     * @param pos iterador apuntando a la posición donde se quiera insertar
     * @param p punto a insertar.
     * @return iterador apuntando al punto insertado.
     */
    Ruta::iterator insertar(Ruta::iterator pos, Punto p);

    /**
     * @brief insertar un punto en la ruta.
     * @param pos iterador constante apuntando a la posición donde se quiera insertar
     * @param p punto a insertar.
     * @return iterador constante apuntando al punto insertado.
     */
    Ruta::const_iterator insertar(Ruta::const_iterator pos, Punto p);

    /**
     * @brief borra un punto en la ruta
     * @param p punto a borrar
     * @return iterador apuntando al punto siguiente al borrado.
     */
    Ruta::iterator borrar(Ruta::iterator p);

    /**
     * @brief borra un punto en la ruta
     * @param p punto a borrar
     * @return iterador constante apuntando al punto siguiente al borrado.
     */
    Ruta::const_iterator borrar(Ruta::const_iterator p);

    /**
     * @brief Sobrecarga del operador <<
     * @param os flujo de salida
     * @param r ruta a imprimir
     * @return flujo de salida
    */
    friend std::ostream & operator <<(std::ostream & os, const Ruta & r);

    /**
     * @brief Sobrecarga del operador >>
     * @param is flujo de entrada
     * @param r ruta a leer
     * @return flujo de entrada
    */
    friend std::istream & operator >>(std::istream & is, Ruta & r);
};

/**
 * @brief Sobrecarga del operador ==
 * @param r1 ruta a comparar
 * @param r2 ruta a comparar
 * @return true si las rutas son iguales, false en caso contrario.
 */
bool operator==(Ruta r1, Ruta r2);

/**
 * @brief Sobrecarga del operador <
 * @param r1 ruta a comparar
 * @param r2 ruta a comparar
 * @return true si r1 es menor que r2, false en caso contrario.
 */
bool operator<(Ruta r1, Ruta r2);

#endif //PRACTICAFINAL_RUTA_H
