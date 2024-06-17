#ifndef PUNTO_3_H_
#define PUNTO_3_H_

#include "lista.h"
#include "barrio.h"
#include "parada.h"

Lista<Parada*>* obtenerParadasDeLinea(const int linea, Lista<Barrio*>* barrios);

#endif /* PUNTO_3_H_ */