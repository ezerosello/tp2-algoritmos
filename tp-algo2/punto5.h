#ifndef PUNTO5_H_
#define PUNTO5_H_

#include <iostream>
#include "lista.h"
#include "barrio.h"

Lista<Parada*>* paradasLineaBarrioOrdenadas(std::string nombreBarrio, unsigned int lineaColectivo, double usuarioCoordX, double usuarioCoordY, Lista<Barrio*>* barrios);

#endif