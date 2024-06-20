/*
 * punto_3.h
 *
 *  Created on: 20 jun. 2024
 *      Author: renzo
 */

#ifndef PUNTO_3_H_
#define PUNTO_3_H_

#include "lista.h"
#include "barrio.h"
#include "parada.h"

Lista<Parada*>* obtenerParadasDeLinea(const int linea, Lista<Barrio*>* barrios);

#endif /* PUNTO_3_H_ */
