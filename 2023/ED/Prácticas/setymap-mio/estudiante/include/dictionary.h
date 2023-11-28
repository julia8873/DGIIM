#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__


/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */
#include <string>
#include <vector>
#include <set>

class Dictionary {
private:
    std::set<std::string> words;
public:

    /**
     * @brief Constructor por defecto
     *        Crea un Dictionary vacío
     */
    Dictionary();

    /**
     * @brief Constructor de copia
     *         Crea un Dictionary con el mismo contenido que el que se le pasa como argumento
     * @param other Dictionary que se quiere copiar
     */
    Dictionary(const Dictionary& other);

    /**
     * @brief Indica si una palabra está en el diccionario o no
     *        Este método comprueba si una determinada palabra se encuentra o no en el diccionario
     * @param val la palabra que se quiere buscar
     * @return Booleano indicando si la palabra existe o no en el diccionario
     */
    bool exists(const std::string& val) const;

    /**
     * @brief Inserta una palabra en el diccionario
     * @param val Palabra a insertar en el diccionario
     * @return Booleano que indica si la inserción ha tenido éxito.
     *          Una palabra se inserta con éxito si no existía previamente en el diccionario
     */
    bool insert(const std::string& val);

    /**
     * @brief Elimina una palabra del diccionario
     * @param val Palabra a borrar del diccionario
     * @return Booleano que indica si la palabra se ha borrado del diccionario
     */
    bool erase(const std::string& val);

    /**
     * @brief Limpia el Dictionary
     *          Elimina todas las palabras contenidas en el conjunto
     */
    void clear();

    /**
     * @brief Comprueba si el diccionario está vacío
     * @return true si el diccionario está vacío, false en caso contrario
     */
    bool empty() const;

    /**
     * @brief Tamaño del diccionario
     * @return Número de palabras guardadas en el diccionario
     */
    unsigned int size() const;

    /**
     * @brief Devuelve las palabras en el diccionario con una longitud dada
     * @param length Longitud de las palabras buscadas
     * @return Vector de las palabras con la longitud deseada
     */
    std::vector<std::string>wordsOfLength(int length);

    /**
     * @brief Indica el número de apariciones de una letra
     * @param c letra a buscar
     * @return Un entero indicando el número de apariciones
     */
    int getOcurrances(const char c);

    /**
     * @brief Añade al diccionario actual el que se pasa como argumento
     * @param dic Diccionario a añadir
     */
    void anade(const Dictionary& dic);

    /**
     * @brief Imprime las palabras del diccionario
     *
     */
    void toString() const;
};

#endif
