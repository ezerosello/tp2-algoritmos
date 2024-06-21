#ifndef PUNTO_4_H_
#define PUNTO_4_H_

#include "lista.h"
#include "barrio.h"


/*
* PRE: recibe una lista de barrios no vacia
* POST: imprime por pantalla el numero de la linea de colectivo seguido por la cantidad de paradas que realiza.
*/

void cantidadDeParadasPorLineaDeColectivo(Lista<Barrio*>* barrios);

/*
* PRE: la lista linea no puede estar vacia
* POST: imprime por pantalla el numero de la linea y cantidad de paradas que realiza.
*/

void imprimirParadasPorLinea(Lista<Parada*>* paradas);

/*
* PRE: la linea tiene que estar en la lista lineas
* POST: devuelve true si la linea esta en la lista, sino false.
*/

bool estaEnListaLineas(int linea, Lista<int>* lineas);

/*
* PRE: -
* POST: recorre la parada y agrega las lineas de colectivo a la lista lineas.
*/

void recorrerParada(Parada* parada, int* lineasParada, Lista<Parada*>* lineas);

/*
* PRE: -
* POST: crea e inicializa una lista de lineas de colectivo.
*/

void crearListaLineas(Lista<Barrio*>* barrios, Lista<Parada*>* lineas);



#endif /* PUNTO_4_H_ */
