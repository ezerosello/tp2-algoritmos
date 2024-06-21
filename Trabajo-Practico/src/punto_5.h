#ifndef PUNTO5_H_
#define PUNTO5_H_

#include "punto_2.h"
#include "lista.h"
#include "barrio.h"

/*
*PRE: EL NOMBRE DEL BARRIO DEBE SER VALIDO Y EXISTIR EN LA LISTA DE BARRIOS, las coordenadas del usuario deben ser validas., la linea de colectivo debe ser valida.
*POST: imprime por pantalla las paradas de la linea de colectivo ingresada, ordenadas por cercania al usuario.
*/

void paradasLineaBarrioOrdenadas(std::string nombreBarrio, int lineaColectivo, double usuarioCoordX, double usuarioCoordY, Lista<Barrio*>* barrios);

#endif
