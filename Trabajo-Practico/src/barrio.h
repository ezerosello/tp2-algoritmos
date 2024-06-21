
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
  
  /*
  * PRE: el barrio no puede tener un nombre vacio.
  * POST: crea un barrio con el nombre ingresado.
  */

  Barrio(std::string nombre);

  /*
  * PRE: -
  * POST: libera la memoria utilizada por el barrio (elimina la lista paradas)
  */

  ~Barrio();

  /*
  * PRE: -
  * POST: devuelve el nombre del barrio.
  */

  std::string getNombre();
  
  /*
  * PRE: -
  * POST: devuelve la lista de paradas del barrio.
  */

  Lista<Parada *> *getParadas();

};

#endif /* BARRIO_H_ */

