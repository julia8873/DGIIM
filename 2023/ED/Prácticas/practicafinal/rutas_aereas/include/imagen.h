#ifndef __IMAGEN__H
#define __IMAGEN_H

#include <string>

struct Pixel{
    unsigned char r,g,b;
    unsigned char transparencia;  // 0 -> no, 255 -> si
};

enum Tipo_Pegado {OPACO, BLENDING};

class Imagen{
private:
    Pixel **datos; //donde se almacena la información de la imagen
    int nf,nc;
    /**
     * @brief Copia una imagen en otra
     * @param I Imagen a copiar
     * @pre La imagen actual debe tener el mismo tamaño que la imagen a copiar
     * @return Devuelve una referencia a la imagen copiada
     */
    void Copy(const Imagen & I);

    /**
     * @brief Borra la imagen
     * @post La imagen actual queda vacía
     */
    void Borrar();

public:
    /**
     * @brief Constructor por defecto
     *
     * Crea una imagen vacía (0 filas, 0 columnas)
     *
     */
    Imagen();

    /**
     * @brief Constructor de copia
     *
     * Crea una imagen con los mismos datos que otra imagen
     *
     * @param I Imagen a copiar
     */
    Imagen(const Imagen &I);

    /**
     * @brief Constructor con parámetros
     *
     * Crea una imagen con un número de filas y columnas
     *
     * @param nf Número de filas
     * @param nc Número de columnas
     */
    Imagen (int nf,int nc);

    /**
     * @brief Destructor
     *
     * Libera la memoria reservada para la imagen
     *
     */
    ~Imagen();

    /**
     * @brief Operador de asignación
     * @param I
     * @return Devuelve una referencia a la imagen asignada
     */
    Imagen & operator =(const Imagen & I);

    /**
     * @brief Devuelve el número de filas de la imagen
     * @return Devuelve el número de filas de la imagen
     */
    int GetFilas()const{return nf;}

    /**
     * @brief Devuelve el número de columnas de la imagen
     * @return Devuelve el número de columnas de la imagen
     */
    int GetCols()const{return nc;}

    /**
     * @brief Devuelve el pixel (i,j) de la imagen
     * @param i Fila
     * @param j Columna
     * @return Devuelve una referencia al pixel (i,j) de la imagen
     */
    Pixel & operator()(int i,int j);

    /**
     * @brief Devuelve el pixel (i,j) de la imagen
     * @param i Fila
     * @param j Columna
     * @return Devuelve una referencia constante al pixel (i,j) de la imagen
     */
    const Pixel & operator()(int i,int j)const;

    /**
     * @brief Escribe la imagen en un fichero
     * @param nombre nombre del archivo a escribir
     */
    void Escribir (const char *nombre);

    /**
     * @brief Lee una imagen de un fichero
     *        Si la máscara es vacía, todos los valores de la transparencia se ponen a 255
     * @param nombre nombre del archivo a leer
     * @param nombre_mascara nombre del archivo de la máscara
     */
    void Leer(const char *nombre, const std::string &nombre_mascara="");

    /**
     * @brief Pone la transparencia de todos los píxeles a 0
     * @post La imagen actual se queda transparentes
     */
    void LimpiarTransp();

    /**
     * @brief Pega una imagen con otra
     * @param i Fila donde empieza a pegar
     * @param j Columna donde empieza a pegar
     * @param I Imagen que quieres pegar
     * @param tipo 0: pegado opaco, se sustituyen píxeles de una imagen por otra
     *             1: pegado con blending, se hace la media de los píxeles
     */
    void PutImagen(int i, int j, const Imagen & I, Tipo_Pegado tippegado=OPACO);

    /**
     * @brief Extrae una imagen de otra
     * @param i Fila donde se empieza a extraer
     * @param j Columna donde se empieza a extraer
     * @param h Altura de la imagen a extraer
     * @param w Anchura de la imagen a extraer
     * @return
     */
    Imagen ExtraerImagen(int i, int j, int h, int w);

};
#endif