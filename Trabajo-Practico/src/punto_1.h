#ifndef PUNTO_1_H
#define PUNTO_1_H
#include "lista.h"
#include "barrio.h"
#include <string>

/*
*PRE: -
*POST: verifica si el texto ingresado por el usuario es valido para busqueda, si es valido devuelve true, sino false.
*/

bool verificarIngresoValido (std::string barrioPorBuscar);

/*
*PRE: - 
*POST: transforma todas las letras de la palabra ingresada a minusculas.
*/

void transformarMinusculas (std::string &palabraATransformar);

/*
* PRE: recibe como parametro un puntero a un puntero de barrios y
* el nombre que el usuario ingreso.
* POST: busca en toda la lista el barrio buscado y lo devuelve como resultado.
*/

Barrio * buscarBarrio (std::string &nombreBarrio, Lista<Barrio *> * barrios);

/*
*PRE: recibe como parametro un puntero a puntero de barrios.
*POST: Devuelve el Barrio buscado.
*/

Barrio * mostrarPorBarrio(Lista<Barrio *> * barrios, std::string barrioPorBuscar);

#endif //PUNTO_1_H
