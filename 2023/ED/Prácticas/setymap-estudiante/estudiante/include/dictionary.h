#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <set>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 *
 *  @author Andrés Alejo Martínez
  * @author Julia Miralles Martínez
  * @date 23 Noviembre 2023
 */

class Dictionary {

private:
    set<string> words;

public:

    /**
     * @brief Constructor por defecto.
     * @details Crea un Dictionary vacío.
     */
    Dictionary();

    /**
     * @brief Constructor de copia.
     * @details Crea un Dictionary con el mismo contenido que el que se pasa como argumento.
     * @param other Dictionary que se quiere copiar.
     */
    Dictionary(Dictionary &other);

    /**
     * @brief Constructor que crea un Diccionario a partir de un archivo.
     * @param f Fichero del que leer.
     */
    Dictionary(ifstream &f);

    /**
     * @brief Indica si una palabra está en el diccionario o no.
     * @details Este método comprueba si una determinada palabra se encuentra o no en el diccionario.
     * @param val la palabra que se quiere buscar.
     * @return Booleano indicando si la palabra existe o no en el diccionario.
     */
    bool exists(const string &val) const;

    /**
     * @brief Inserta una palabra en el diccionario.
     * @param val palabra a insertar en el diccionario.
     * @return Booleano que indica si la inserción ha tenido éxito. Una palabra se inserta con éxito si no existía previamente en el diccionario.
     */
    bool insert(const string &val);

    /**
     * @brief Elimina una palabra del diccionario.
     * @param val Palabra a borrar del dicccionario.
     * @return Booleano que indica si la palabra se ha borrado del diccionario.
     */
    bool erase(const string &val);

    /**
     * @brief Limpia el Dictionary.
     * @details Elimina todas las palabras contenidas en el conjunto.
     */
    void clear();

    /**
     * @brief Comprueba si el diccionario está vacío.
     * @return true si el diccionario está vacío, false en caso contrario.
     */
    bool empty() const;

    /**
     * @brief Tamaño del diccionario.
     * @return Número de palabras guardadas en el diccionario.
     */
    unsigned int size() const;

    /**
     * @brief Devuelve las palabras en el diccionario con una longitud dada.
     * @param length Longitud de las palabras buscadas.
     * @return Vector de palabras con la longitud deseada.
     */
    vector<string> wordsOfLength(int length);

    /**
     * @brief Indica el número de apariciones de una letra.
     * @param c letra a buscar.
     * @return Un entero indicando el número de apariciones.
     */
    int getOccurrences(const char c);

    /**
     * @brief Añade al diccionario actual el que se pasa como argumento.
     * @param dic Diccionario a añadir al actual.
     */
    void anade(const Dictionary &dic);

    /**
     * @brief Sobrecarga del operador de asignación.
     * @param dict Diccionario a asignar.
     * @return Diccionario asignado.
     */
    friend ostream & operator<<(ostream &os, const Dictionary &dict);

    /**
    * @brief clase para iterar sobre el diccionario
    * */
    class iterator{
        private:
            set<string>::iterator it;

        public:
            iterator & operator++(){++it;return *this;}
            iterator & operator--(){--it;return *this;}
            const string &operator*() const { return *it; }
            bool operator ==(const iterator &i){return i.it==it;}
            bool operator !=(const iterator &i){return i.it!=it;}
            friend class Dictionary;
    };

    /**
    * @brief Inicializa un iterator al comienzo del diccionario
    * */
    iterator  begin(){
        iterator i;
        i.it=words.begin();
        return i;
    }

    /**
    * @brief Inicializa un iterator al final del diccionario
    * */
    iterator  end(){
        iterator i;
        i.it=words.end();
        return i;
    }

};

#endif
