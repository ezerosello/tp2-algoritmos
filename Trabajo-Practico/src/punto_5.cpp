/*
 * punto_5.cpp
 *
 *  Created on: 20 jun. 2024
 *      Author: renzo
 */


#include "punto_5.h"
#include "punto_1.h"
#include "punto_2.h"

Lista<Parada*>* paradasLineaBarrioOrdenadas(std::string nombreBarrio, int lineaColectivo, double usuarioCoordX, double usuarioCoordY, Lista<Barrio*>* barrios) {

    Lista<Parada*>* paradasLineaBarrioOrdenadas = new Lista<Parada*>();
    transformarMayusculas(nombreBarrio);
    barrios->iniciarCursor();

    while (barrios->avanzarCursor()) {
        if (barrios->obtenerCursor()->getNombre() == nombreBarrio) {
            Lista<Parada*>* listaParadas = barrios->obtenerCursor()->getParadas(); 
            listaParadas->iniciarCursor();

            double distanciaParadaMasProxima = -1;

            while (listaParadas->avanzarCursor()) {
                Parada* paradaActual = listaParadas->obtenerCursor(); 
                int* todasLasLineas = paradaActual->getLineas(); 

                for (unsigned int i = 0; i < paradaActual->getCantidadDeLineas(); i++) { 
                    if (todasLasLineas[i] == lineaColectivo) {
                        double distanciaX = usuarioCoordX - paradaActual->getCoordenadaX();
                        double distanciaY = usuarioCoordY - paradaActual->getCoordenadaY();
                        double distancia = distanciaX * distanciaX + distanciaY * distanciaY;

                        if (distanciaParadaMasProxima == -1 || distancia < distanciaParadaMasProxima) {
                            paradasLineaBarrioOrdenadas->agregarAlInicio(paradaActual);
                            distanciaParadaMasProxima = distancia;
                        } else {
                            paradasLineaBarrioOrdenadas->agregar(paradaActual); 
                        }
                    }
                }
            }
            break;
        }
    }

    paradasLineaBarrioOrdenadas->iniciarCursor();
    while(paradasLineaBarrioOrdenadas->avanzarCursor()){
    	std::cout << paradasLineaBarrioOrdenadas->obtenerCursor()->getDireccion() << std::endl;
    }

    return paradasLineaBarrioOrdenadas;
}

