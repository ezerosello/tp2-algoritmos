/*
 * menu.h
 *
 *  Created on: 20 jun. 2024
 *      Author: renzo
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <string>

void imprimirArchivoParadasDeColectivo(Lista<Barrio*>*barrios);
void imprimirOpciones();
bool validarOpcionRango(char opcion);
bool validarOpcion(std::string opcion);

#endif /* MENU_H_ */
