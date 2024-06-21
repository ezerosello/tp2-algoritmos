/*
 * punto_5.h
 *
 *  Created on: 20 jun. 2024
 *      Author: renzo
 */

#ifndef PUNTO5_H_
#define PUNTO5_H_

#include <iostream>
#include "lista.h"
#include "barrio.h"

Lista<Parada*>* paradasLineaBarrioOrdenadas(std::string nombreBarrio, int lineaColectivo, double usuarioCoordX, double usuarioCoordY, Lista<Barrio*>* barrios);

#endif
