#include "punto_1.h"
#include "punto_5.h"
#include "punto_2.h"
#include <iostream>

void paradasLineaBarrioOrdenadas(std::string nombreBarrio, int lineaColectivo, double usuarioCoordX, double usuarioCoordY, Lista<Barrio *> *barrios)
{
    Lista<Parada *> *paradasLineaBarrioOrdenadas = new Lista<Parada *>();
    transformarMayusculas(nombreBarrio);
    barrios->iniciarCursor();

    while (barrios->avanzarCursor())
    {
        if (barrios->obtenerCursor()->getNombre() == nombreBarrio)
        {
            Lista<Parada *> *listaParadas = barrios->obtenerCursor()->getParadas();
            listaParadas->iniciarCursor();

            double distanciaParadaMasProxima = -1;

            while (listaParadas->avanzarCursor())
            {
                Parada *paradaActual = listaParadas->obtenerCursor();
                int *todasLasLineas = paradaActual->getLineas();

                for (unsigned int i = 0; i < paradaActual->getCantidadDeLineas(); i++)
                {
                    if (todasLasLineas[i] == lineaColectivo)
                    {
                        double distanciaX = usuarioCoordX - paradaActual->getCoordenadaX();
                        double distanciaY = usuarioCoordY - paradaActual->getCoordenadaY();
                        double distancia = distanciaX * distanciaX + distanciaY * distanciaY;

                        std::string calle = paradaActual->getCalle();
                        std::string direccion = paradaActual->getDireccion();
                        double coordenadaX = paradaActual->getCoordenadaX();
                        double coordenadaY = paradaActual->getCoordenadaY();
                        unsigned int cantidadDeLineas = paradaActual->getCantidadDeLineas();
                        int *lineas = paradaActual->getLineas();

                        Parada *paradaAux = new Parada(calle, direccion, coordenadaX, coordenadaY, cantidadDeLineas, lineas);

                        if (distanciaParadaMasProxima == -1 || distancia < distanciaParadaMasProxima)
                        {
                            paradasLineaBarrioOrdenadas->agregarAlInicio(paradaAux);
                            distanciaParadaMasProxima = distancia;
                        }
                        else
                        {
                            paradasLineaBarrioOrdenadas->agregar(paradaAux);
                        }
                    }
                }
            }
            break;
        }
    }

    paradasLineaBarrioOrdenadas->iniciarCursor();
    while (paradasLineaBarrioOrdenadas->avanzarCursor())
    {
        std::cout << paradasLineaBarrioOrdenadas->obtenerCursor()->getDireccion() << std::endl;
    }

    delete paradasLineaBarrioOrdenadas;
}
