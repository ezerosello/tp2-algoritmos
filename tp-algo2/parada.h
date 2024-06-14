#ifndef PARADA_H_
#define PARADA_H_

#include <string>

class Parada
{
private:
  std::string calle;
  std::string direccion;
  double coordenadaX;
  double coordenadaY;
  unsigned int cantidadDeLineas;
  int *lineas;

public:
  Parada(std::string calle, std::string direccion, double coordenadaX, double coordenadaY, unsigned int cantidadDeLineas, int *lineas);
  ~Parada();
  std::string getCalle();
  std::string getDireccion();
  double getCoordenadaX();
  double getCoordenadaY();
  unsigned int getCantidadDeLineas();
  int *getLineas();
};

#endif /* PARADA_H_ */