#ifndef PUNTO_3_H_
#define PUNTO_3_H_

#include "lista.h"
#include "barrio.h"
#include "parada.h"
#include "linea.h"

/*
* PRE: la linea ingresada debe ser valida y pertenecer a las lineas de colectivo de la ciudad.
* POST: imprime un listado de las paradas de la linea de colectivo ingresada.
*/

void obtenerParadasDeLinea(const int linea, Lista<Barrio*>* barrios);

/*
* PRE: -
* POST: imprime un listado de las paradas de la linea de colectivo ingresada.
*/

void imprimirParadasDeLinea(Lista<Parada*>* paradas);

#endif /* PUNTO_3_H_ */
