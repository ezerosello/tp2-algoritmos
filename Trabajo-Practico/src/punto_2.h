/*
 * punto_1.h
 *
 *  Created on: 20 jun. 2024
 *      Author: renzo
 */

#ifndef PUNTO_2_H_
#define PUNTO_2_H_

#include "lista.h"
#include "barrio.h"
#include "parada.h"
#include <string>

std::string obtenerParadaMasCercana(double coordX, double coordY, Lista<Barrio*>* barrios);

#endif /* PUNTO_2_H_ */
