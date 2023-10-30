/**
 * @brief TDA Suma
 * 
 * Representa una suma de casillas.
 * 
 * @author Andrés Alejo Martínez
 * @author Julia Miralles Martínez
*/

class Suma {
private:

  /**
   * @section invConjunto Invariante de la representación
   * val >= 3
  */

  int val; /**< Valor de la suma.*/
  Posicion *posiciones; /**< Posiciones de las casillas que forman la suma.*/
  int nPos; /**< Número de posiciones que forman la suma.*/

public:
  /**
   * @brief Constructor por defecto.
   * @return Crea una suma vacía.
  */
  Suma();

  /**
   * @brief Destructor.
   * @return Libera la memoria dinámica reservada.
   * @post La Suma está vacía.
  */
  ~Suma();

  /**
   * @brief Constructor de copia.
   * @param otro Suma a copiar.
   * @return Suma, el objeto suma creado.
  */
  Suma(const Suma& otro);

  /**
   * @brief Operador de asignación.
   * @param otro Suma a copiar.
   * @return Una referencia a la suma copiado.
  */
  Suma& operator=(const Suma& otro);

  /**
   * @brief Tamaño de la suma.
   * @return Número de posiciones que forman la suma.
  */
  int getTam() const;

  /**
   * @brief Valor de la suma.
   * @return Valor de la suma.
  */
  int getValor() const;

  /**
   * @brief Establece el valor de la suma.
   * @param valor Valor de la suma.
   * @pre valor >= 3
  */
  void setValor(int valor);

  /**
   * @brief Añade una casilla a la suma.
   * @param pos Posición de la casilla añadida.
   * @pre 0 <= pos.fila < 9 && 0 <= pos.columna < 9
   *      pos tiene que ser una casilla contigua a las demás.
  */
  void AniadirCasilla(Posicion pos);

  /**
   * @brief Elimina una casilla de la suma.
   * @param pos Posición de la casilla a eliminar.
   * @pre 0 <= pos.fila < 9 && 0 <= pos.columna < 9
  */
  void EliminaCasilla(Posicion pos);

  /**
   * @brief Operador de acceso a una casilla.
   * @param i Posición de la casilla a acceder.
   * @return Una referencia a la posición de la casilla en el sudoku.
  */
  Posicion& operator[](int i);

  /**
   * @brief Operador de acceso a una casilla.
   * @param i Posición de la casilla a acceder.
   * @return Una referencia constante a la posición de la casilla en el sudoku.
  */
  const Posicion& operator[](int i) const;
};
