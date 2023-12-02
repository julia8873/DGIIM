//
// Created by julia on 28/11/23.
//

#ifndef PRACTICAFINAL_RUTA_H
#define PRACTICAFINAL_RUTA_H

#include <punto.h>
#include <list>
#include <string>

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
     * @param code código de la ruta.
     */
    Ruta(std::list<Punto> pts, std::string code);

    /**
     * @brief insertar un punto en la ruta.
     * @param p punto a insertar.
     *
     */
    void insertar(Punto p);

    /**
     * @brief borra un punto en la ruta
     * @param p punto a borrar
     */
    void borrar(Punto p);


    /**
     * @brief Coger el código de la ruta.
     * @return código de la ruta.
     */
    std::string getCode();

    /**
     * @brief Establece el código de la ruta.
     * @param code código a introducir.
     */
    void setCode(std::string code);

    /**
    * @brief Coger la lista de puntos.
    * @return lista de puntos.
    */
    std::list<Punto> getPuntos();

    /**
     * @brief Clase para iterar sobre la lista de puntos.
     */

    class const_iterator {
    private:
        std::list<Punto>::const_iterator it;
    public:
        const_iterator& operator++(){++it ; return *this;}
        const_iterator& operator--(){--it ; return *this;}
        bool operator ==(const const_iterator &i){return i.it == it;}
        bool operator !=(const const_iterator &i){return i.it != it;}
        const Punto & operator *(){return *it;}
        friend class Ruta;
    };

    /**
     * @brief Clase para iterar sobre la lista de puntos.
     */
    class iterator {
    private:
        std::list<Punto>::iterator it;
    public:
        iterator& operator++(){++it ; return *this;}
        iterator& operator--(){--it ; return *this;}
        bool operator ==(const iterator &i){return i.it == it;}
        bool operator !=(const iterator &i){return i.it != it;}
        Punto & operator *(){return *it;}
        friend class Ruta;
        friend class const_iterator;
    };

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
