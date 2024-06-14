#ifndef BARRIO_H_
#define BARRIO_H_

#include <string>
#include "lista.h"
#include "parada.h"

class Barrio
{
private:
  std::string nombre;
  Lista<Parada *> *paradas;

public:
  Barrio(std::string nombre, Lista<Parada *> *paradas);
  ~Barrio();
  std::string getNombre();
  Lista<Parada *> *getParadas();
};

#endif /* BARRIO_H_ */