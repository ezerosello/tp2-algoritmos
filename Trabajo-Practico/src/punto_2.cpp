#include "punto_2.h"

std::string obtenerParadaMasCercana(double coordX, double coordY, Lista<Barrio*>* barrios) {

  std::string ParadaMasCercana = "";

  double distanciaMasCercana = 1e9;
  double compararX;
  double compararY;

  barrios->iniciarCursor();
  while (barrios->avanzarCursor())
  {
    Barrio* barrio = barrios->obtenerCursor();
    Lista<Parada*>* paradas = barrio->getParadas();

    paradas->iniciarCursor();
    while (paradas->avanzarCursor())
    {
      Parada* parada = paradas->obtenerCursor();

      compararX = coordX - parada->getCoordenadaX();
      compararY = coordY - parada->getCoordenadaY();

      double distancia = std::sqrt(compararX * compararX + compararY * compararY);

      if(distancia < distanciaMasCercana){
        distanciaMasCercana = distancia;
        ParadaMasCercana = parada->getDireccion();
      }
    }
  }

  return ParadaMasCercana;
};


