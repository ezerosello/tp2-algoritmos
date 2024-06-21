#include "barrio.h"
#include <iostream>


Barrio::Barrio(std::string nombre)
{
  this->nombre = nombre;
  this->paradas = new Lista<Parada *>;
};

Barrio::~Barrio()
{
  for (int i = 0; i < this->paradas->getTamanio(); ++i) {
    delete this->paradas->obtener(i);
  }
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

