
#ifndef MENU_H_
#define MENU_H_

#include <string>

/*
*PRE: -
*POST: imprime las opciones disponibles.
*/

void imprimirOpciones();

/*
*PRE: la opcion ingresada tiene que estar en el rango de opciones
*POST: devuelve true si la opcion ingresada es valida, sino false.
*/

bool validarOpcionRango(char opcion);

/*
*PRE: la  opcion ingresada tiene que ser un string de un solo caracter
*POST: devuelve true si la opcion ingresada es valida, sino false.
*/

bool validarOpcion(std::string opcion);

#endif /* MENU_H_ */
