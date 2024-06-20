#ifndef INICIALIZAR_DATOS_H_
#define INICIALIZAR_DATOS_H_

#include <string>
#include "lista.h"
#include "barrio.h"
#include <iostream>

void inicializarDatos(const std::string& archivo, Lista<Barrio*>* barrios);

#endif /* INICIALIZAR_DATOS_H_ */
