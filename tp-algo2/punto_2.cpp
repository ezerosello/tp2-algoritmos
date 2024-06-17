#include "punto_2.h"
#include "lista.h"

std::string obtenerParadaMasCercana(double coordX, double coordY, Lista<Barrio*>* barrios) {

  std::string ParadaMasCercana = "";
    
  double distanciaMasCercana = 1e9;  
  double compararX;
  double compararY;

  Lista<Parada*>* paradas = new Lista<Parada*>();  

  barrios->iniciarCursor();
  while (barrios->avanzarCursor())
  {
    Barrio* barrio = barrios->obtenerCursor();
    paradas = barrio->getParadas();

    paradas->iniciarCursor();
    while (paradas->avanzarCursor())
    {
      Parada* parada = paradas->obtenerCursor();

      compararX = coordX - parada->getCoordenadaX();
      compararY = coordY - parada->getCoordenadaY();

      double distancia = compararX * compararX + compararY * compararY;

      if(distancia < distanciaMasCercana){
        distanciaMasCercana = distancia;
        ParadaMasCercana = parada->getDireccion();
        }


    }
  }

  return ParadaMasCercana;
};