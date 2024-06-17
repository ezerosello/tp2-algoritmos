#ifndef PUNTO_2_H_
#define PUNTO_2_H_

#include "lista.h"
#include "barrio.h"
#include "parada.h"
#include <string>

std::string obtenerParadaMasCercana(double coordX, double coordY, Lista<Barrio*>* barrios);

#endif /* PUNTO_2_H_ */