#include <iostream>
#include <string>
#include "punto_3.h"

void obtenerParadasDeLinea(const int linea, Lista<Barrio *> *barrios)
{
  Lista<Parada *> *resultado = new Lista<Parada *>();

  barrios->iniciarCursor();
  while (barrios->avanzarCursor())
  {
    Barrio *barrio = barrios->obtenerCursor();
    Lista<Parada *> *paradas = barrio->getParadas();

    paradas->iniciarCursor();
    while (paradas->avanzarCursor())
    {
      Parada *parada = paradas->obtenerCursor();

      for (size_t i = 0; i < parada->getCantidadDeLineas(); i++)
      {
        int *lineas = parada->getLineas();
        if (lineas[i] == linea)
        {
          std::string calle = parada->getCalle();
          std::string direccion = parada->getDireccion();
          double coordenadaX = parada->getCoordenadaX();
          double coordenadaY = parada->getCoordenadaY();
          unsigned int cantidadDeLineas = parada->getCantidadDeLineas();
          int *lineas = parada->getLineas();

          Parada *paradaAux = new Parada(calle, direccion, coordenadaX, coordenadaY, cantidadDeLineas, lineas);

          resultado->agregar(paradaAux);
        }
      }
    }
  }

  imprimirParadasDeLinea(resultado);

  delete resultado;
};

void imprimirParadasDeLinea(Lista<Parada *> *paradas)
{
  std::cout << "Las paradas de la linea son las siguientes:" << std::endl;

  paradas->iniciarCursor();
  while (paradas->avanzarCursor())
  {
    Parada *parada = paradas->obtenerCursor();

    std::cout << std::endl;
    std::cout << "- " << parada->getDireccion() << std::endl;
  }
}
