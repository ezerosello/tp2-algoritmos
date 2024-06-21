#ifndef PUNTO_2_H_
#define PUNTO_2_H_

#include "lista.h"
#include "barrio.h"
#include "parada.h"
#include <cmath>
#include <string>


/*
* PRE: las coordenadas ingresadas deben estar adentro del rango solicitado y ser numeros.
* POST: devuelve la parada mas cercana a las coordenadas ingresadas.
*/

std::string obtenerParadaMasCercana(double coordX, double coordY, Lista<Barrio*>* barrios);

#endif /* PUNTO_2_H_ */
