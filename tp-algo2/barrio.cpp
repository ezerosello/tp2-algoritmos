#include "../includes/barrio.h"

using namespace std;

Barrio::Barrio(std::string nombre, Lista<Parada *> *paradas)
{
  this->nombre = nombre;

  this->paradas = new Lista<Parada *>;
  paradas->iniciarCursor();
  while (paradas->avanzarCursor())
  {
    Parada *parada = paradas->obtenerCursor();
    this->paradas->agregar(parada);
  }
};

Barrio::~Barrio()
{
  delete this->paradas;
}

std::string Barrio::getNombre()
{
  return this->nombre;
};

Lista<Parada *> *Barrio::getParadas()
{
  return this->paradas;
};