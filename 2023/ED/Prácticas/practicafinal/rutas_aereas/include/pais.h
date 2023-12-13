//
// Created by julia on 28/11/23.
//

#ifndef PRACTICAFINAL_PAIS_H
#define PRACTICAFINAL_PAIS_H

#include "punto.h"
#include <string>
#include <iostream>

class Pais {
private:
    Punto p;
    std::string nombre;
    std::string bandera;

public:

    /**
     * @brief Constructor por defecto.
     */
    Pais();

    /**
     * @brief Constructor con el punto, el país y la bandera.
     * @param p punto del país.
     * @param nombre nombre del país.
     * @param bandera bandera del país.
     */
    Pais(const Punto &p, const std::string &nombre, const std::string &bandera);

    /**
     * @brief Consultar el punto del país.
     * @return punto del país.
     */
    Punto getPunto() const;

    /**
     * @brief Consultar el nombre del país.
     * @return nombre del país.
     */
    std::string getNombre() const;

    /**
     * @brief Consultar la bandera del país.
     * @return bandera del país.
     */
    std::string getBandera() const;

    /**
     * @brief Establecer el punto del país.
     * @param p punto a establecer.
     */
    void setPunto(const Punto &p);

    /**
     * @brief Establecer el nombre del país.
     * @param pais nombre a establecer.
     */
    void setNombre(const std::string &nombre);

    /**
     * @brief Establecer la bandera del país.
     * @param bandera bandera a establecer.
     */
    void setBandera(const std::string &bandera);

    /**
     * @brief Operador de salida.
     * @param os flujo de salida.
     * @param p país a imprimir.
     * @return flujo de salida.
     */
    friend std::ostream &operator<<(std::ostream &os, const Pais &p);

    /**
     * @brief Operador de entrada.
     * @param is flujo de entrada.
     * @param p país a leer.
     * @return flujo de entrada.
     */
    friend std::istream &operator>>(std::istream &is, Pais &p);
};

/**
 * @brief Sobrecarga de operador de igualdad.
 * @param p1 país 1.
 * @param p2 país 2.
 * @return true si son iguales, false en caso contrario.
*/
bool operator==(const Pais & p1, const Pais & p2);

/**
 * @brief Sobrecarga de operador de menor que.
 * @param p1 país 1.
 * @param p2 país 2.
 * @return true si p1 es menor que p2, false en caso contrario.
*/
bool operator<(const Pais & p1, const Pais & p2);


#endif //PRACTICAFINAL_PAIS_H
