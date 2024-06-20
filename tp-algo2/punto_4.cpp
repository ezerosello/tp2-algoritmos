/*
 * punto_4.cpp
 *
 *  Created on: 19 jun. 2024
 *      Author: renzo
 */

#include "punto_4.h"
#include "parada.h"
#include "linea.h"
#include <iostream>

using namespace std;


bool estaEnListaLineas(int lineaParada, Lista<Linea*>*lineas){



	if(lineas->estaVacia()){
		return false;
	}
	else{
		lineas->iniciarCursor();
		while(lineas->avanzarCursor()){
			Linea* linea = lineas->obtenerCursor();
			if(linea->getNumeroLinea() == lineaParada){
				return true;
			}
		}
	}

	return false;
}



void crearListaLineas(Lista<Barrio*>*barrios, Lista<Linea*>*lineas){

	barrios->iniciarCursor();
	while(barrios->avanzarCursor()){

		Barrio* barrio = barrios->obtenerCursor();

		Lista<Parada*>* paradas = barrio->getParadas();
		paradas->iniciarCursor();
		while(paradas->avanzarCursor()){
			Parada * parada = paradas->obtenerCursor();
			int* lineasParada = parada->getLineas();

			for(unsigned int i = 0; i < parada->getCantidadDeLineas(); i++){
				if(!estaEnListaLineas(lineasParada[i],lineas)){
					Linea *lineaNueva = new Linea();
					lineas->agregar(lineaNueva);
					lineaNueva->agregarNumeroLinea(lineasParada[i]);
					lineaNueva->sumarCantidad();
				}
				else{

					lineas->iniciarCursor();
					while(lineas->avanzarCursor()){
						Linea* linea = lineas->obtenerCursor();

						if(linea->getNumeroLinea() == lineasParada[i]){
							linea->sumarCantidad();
						}
					}
				}


			}

		}

	}
}




void cantidadDeParadasPorLineaDeColectivo(Lista<Barrio*>*barrios){

	Lista<Linea*> *lineas = new Lista<Linea*>();
	crearListaLineas(barrios,lineas);

	if(!lineas->estaVacia()){

		lineas->iniciarCursor();
		while(lineas->avanzarCursor()){

			Linea *  lineaActual = lineas->obtenerCursor();
			cout << lineaActual->getNumeroLinea() << " " << lineaActual->getCantidadParadas() << endl;
		}

		cout << "fin" << endl;

	}
}


