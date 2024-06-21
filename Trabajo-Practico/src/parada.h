#ifndef PARADA_H_
#define PARADA_H_

#include <string>

class Parada{

private:
  std::string calle;
  std::string direccion;
  double coordenadaX;
  double coordenadaY;
  unsigned int cantidadDeLineas;
  int *lineas;

public:
  
  /*
  * PRE: parada no puede estar vacio
  * POST: crea una parada con los datos (calle,direccion,coordenadaX,coordenadaY,cantidadDeLineas,Lineas).
  */

  Parada(std::string calle, std::string direccion, double coordenadaX, double coordenadaY, unsigned int cantidadDeLineas, int *lineas);
  
  /*
  * PRE: -
  * POST: libera la memoria utilizada por la parada.
  */

  ~Parada();

  /*
  * PRE: -
  * POST: devuelve la calle de la parada.
  */

  std::string getCalle();

  /*
  * PRE: -
  * POST: devuelve la direccion de la parada.
  */

  std::string getDireccion();

  /*
  * PRE: -
  * POST: devuelve la coordenada X de la parada.
  */

  double getCoordenadaX();

  /*
  * PRE: -
  * POST: devuelve la coordenada Y de la parada.
  */

  double getCoordenadaY();

  /*
  * PRE: -
  * POST: devuelve la cantidad de lineas de la parada.
  */

  unsigned int getCantidadDeLineas();

  /*
  * PRE: -
  * POST: devuelve las lineas de la parada.
  */

  int *getLineas();

};

#endif /* PARADA_H_ */
