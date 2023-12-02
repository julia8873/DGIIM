#ifndef __IMAGEN__H
#define __IMAGEN_H

#include <string>

struct Pixel{
    unsigned char r,g,b;
    unsigned char transparencia;
};

class Imagen{
private:
    Pixel **datos; //donde se almacena la información de la imagen
    int nf,nc;
public:
    /*
     * @brief Constructor por defecto
     *
     * Crea una imagen vacía (0 filas, 0 columnas)
     *
     */
    Imagen();

    /*
     * @brief Constructor de copia
     *
     * Crea una imagen con los mismos datos que otra imagen
     *
     * @param I Imagen a copiar
     */
    Imagen(const Imagen &I);

    /*
     * @brief Constructor con parámetros
     *
     * Crea una imagen con un número de filas y columnas
     *
     * @param nf Número de filas
     * @param nc Número de columnas
     */
    Imagen (int nf,int nc);

    /*
     * @brief Destructor
     *
     * Libera la memoria reservada para la imagen
     *
     */
    ~Imagen();

    Imagen & operator =(const Imagen & I);
    int GetFilas()const;
    int GetCols()const;
    Pixel & operator()(int i,int j);
    const Pixel & operator()(int i,int j)const;
    void Escribir (const char *nombre);
    void Leer(const char *nimagen, std::string nombre_mascara="");
};
#endif