/*
 * punto_5.cpp
 *
 *  Created on: 20 jun. 2024
 *      Author: renzo
 */


#include "punto_5.h"
#include "punto_2.h"

Lista<Parada*>* paradasLineaBarrioOrdenadas(std::string nombreBarrio, unsigned int lineaColectivo, double usuarioCoordX, double usuarioCoordY, Lista<Barrio*>* barrios) {

    Lista<Parada*>* paradasLineaBarrioOrdenadas = new Lista<Parada*>(); //creo una lista de paradas

    barrios->iniciarCursor(); //recorre los barrios

    while (barrios->avanzarCursor()) {
        Barrio* barrioActual = barrios->obtenerCursor(); //obtiene el barrio actual

        if (barrioActual->getNombre() == nombreBarrio) { //chequea si el barrio actual coincide con el que buscamos
            Lista<Parada*>* listaParadas = barrioActual->getParadas(); //crea una lista de las paradas del barrio
            listaParadas->iniciarCursor(); //recorre las paradas del barrio

            double distanciaParadaMasProxima = -1;

            while (listaParadas->avanzarCursor()) {
                Parada* paradaActual = listaParadas->obtenerCursor(); // obtiene la parada actual
                int* todasLasLineas = paradaActual->getLineas(); // arma un vector de enteros con todas las lineas de la parada

                for (unsigned int i = 0; i < paradaActual->getCantidadDeLineas(); i++) { //recorre todas las lineas de una parada
                    if (todasLasLineas[i] == lineaColectivo) { // si la linea coincide
                        double distanciaX = usuarioCoordX - paradaActual->getCoordenadaX();
                        double distanciaY = usuarioCoordY - paradaActual->getCoordenadaY();
                        double distancia = distanciaX * distanciaX + distanciaY * distanciaY;

                        if (distanciaParadaMasProxima == -1 || distancia < distanciaParadaMasProxima) {
                            paradasLineaBarrioOrdenadas->agregarAlInicio(paradaActual);
                            distanciaParadaMasProxima = distancia;
                        } else {
                            paradasLineaBarrioOrdenadas->agregar(paradaActual); // si la distancia no es menor, la agrega al final
                        }
                    }
                }
            }
            break; // salgo del while porque ya encontré el barrio
        }
    }

    return paradasLineaBarrioOrdenadas;
}
