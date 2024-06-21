#include "punto_1.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool verificarIngresoValido (std::string barrioPorBuscar) {
	unsigned int numeroDePrueba;
	std::stringstream ss(barrioPorBuscar);
	unsigned int tamanioDeNombre = barrioPorBuscar.length();
	return (tamanioDeNombre != 0) &&  (tamanioDeNombre > 3) && !(ss >> numeroDePrueba);
}

void transformarMayusculas (std::string &palabraATransformar) {
	unsigned int tamanioPalabra = palabraATransformar.length();
    for(unsigned int i = 0; i < tamanioPalabra; i++) {
    	palabraATransformar[i] = toupper(palabraATransformar[i]);
    }
}

Barrio * buscarBarrio (std::string &nombreBarrio, Lista<Barrio *> * barrios) {
    barrios->iniciarCursor();
    Barrio * barrioActual;
    while(barrios->avanzarCursor()) {
    	barrioActual = barrios->obtenerCursor();
        std::string nombreBarrioActual = barrioActual->getNombre();

        transformarMayusculas(nombreBarrioActual);

        if(nombreBarrioActual == nombreBarrio) {
        	return barrioActual;
        }
    }
    barrioActual = NULL;
    return barrioActual;
}

Barrio * mostrarPorBarrio(Lista<Barrio *> * barrios, std::string barrioPorBuscar) {
	transformarMayusculas(barrioPorBuscar);
    Barrio * barrioResultante = buscarBarrio(barrioPorBuscar, barrios);
    return barrioResultante;
}
