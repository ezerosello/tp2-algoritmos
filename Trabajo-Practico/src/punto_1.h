#ifndef PUNTO_1_H
#define PUNTO_1_H
#include "lista.h"
#include "barrio.h"
#include <string>

/*
 * Verifica si el texto ingresado por el usuario es valido para busqueda.
 * Devuelve true si es valido o false caso contrario.
 */
bool verificarIngresoValido (std::string barrioPorBuscar);

/*
 *Funcion auxiliar que transforma todos los caracteres de un flujo de
 *	cadena a minusculas.
 */
void transformarMinusculas (std::string &palabraATransformar);

/*
 * Funcion que recibe como parametro un puntero a un puntero de barrios y
 * el nombre que el usuario ingreso.
 * Busca en toda la lista el barrio buscado y lo devuelve como resultado.
 */
Barrio * buscarBarrio (std::string &nombreBarrio, Lista<Barrio *> * barrios);

/*
 * Funcion que recibe como parametro un puntero a puntero de barrios.
 * Devuelve el Barrio buscado.
 */
Barrio * mostrarPorBarrio(Lista<Barrio *> * barrios);

#endif //PUNTO_1_H
