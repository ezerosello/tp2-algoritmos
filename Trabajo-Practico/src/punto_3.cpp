/*
 * punto_3.cpp
 *
 *  Created on: 20 jun. 2024
 *      Author: renzo
 */
#include <iostream>
#include "punto_3.h"

Lista<Parada*>* obtenerParadasDeLinea(const int linea, Lista<Barrio*>* barrios) {
  Lista<Parada*>* resultado = new Lista<Parada*>();

  barrios->iniciarCursor();
  while (barrios->avanzarCursor())
  {
    Barrio* barrio = barrios->obtenerCursor();
    Lista<Parada*>* paradas = barrio->getParadas();

    paradas->iniciarCursor();
    while (paradas->avanzarCursor())
    {
      Parada* parada = paradas->obtenerCursor();

      for (size_t i = 0; i < parada->getCantidadDeLineas(); i++)
      {
        int* lineas = parada->getLineas();
        if (lineas[i] == linea)
        {
          resultado->agregar(parada);
        }
      }
    }
  }

  return resultado;
};

void imprimirParadasDeLinea(Lista<Parada*>* paradas) {
  paradas->iniciarCursor();
  while (paradas->avanzarCursor()) {
      Parada* parada = paradas->obtenerCursor();
      
      std::cout << std::endl;
      std::cout << "- Calle: " << parada->getCalle() << std::endl;
      std::cout << "- Dirección: " << parada->getDireccion() << std::endl;
      std::cout << "- Coordenada X: " << parada->getCoordenadaX() << std::endl;
      std::cout << "- Coordenada Y: " << parada->getCoordenadaY() << std::endl;
      std::cout << "- Cantidad de líneas: " << parada->getCantidadDeLineas() << std::endl;
      
      unsigned int cantidadDeLineas = parada->getCantidadDeLineas();
      int* lineas = parada->getLineas();
      std::cout << "- Líneas: ";
      for (unsigned int i = 0; i < cantidadDeLineas; i++) {
          std::cout << lineas[i] << " ";
      }
      std::cout << std::endl;
      
      std::cout << std::endl;
  }
  std::cout << "-----------------------------------" << std::endl;
}

