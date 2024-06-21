#include <iostream>
#include "punto_3.h"

void obtenerParadasDeLinea(const int linea, Lista<Barrio*>* barrios) {
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

  imprimirParadasDeLinea(resultado);
  
  delete resultado;
	
};

void imprimirParadasDeLinea(Lista<Parada*>* paradas) {
  std::cout << "Las paradas de la linea son las siguientes:" << std::endl;
  
  paradas->iniciarCursor();
  while (paradas->avanzarCursor()) {
      Parada* parada = paradas->obtenerCursor();
      
      std::cout << std::endl;
      std::cout << "- " << parada->getDireccion() << std::endl;
  }  
}

