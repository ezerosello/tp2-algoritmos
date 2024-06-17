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