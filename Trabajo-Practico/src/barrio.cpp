#include "barrio.h"
#include <iostream>

Barrio::Barrio(std::string nombre)
{
  this->nombre = nombre;
  this->paradas = new Lista<Parada *>;
};

Barrio::~Barrio()
{
  delete this->paradas;
};

std::string Barrio::getNombre()
{
  return this->nombre;
};

Lista<Parada *> *Barrio::getParadas()
{
  return this->paradas;
};
