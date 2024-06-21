/*
 * barrio.cpp
 *
 *  Created on: 14 jun. 2024
 *      Author: renzo
 */


#include "barrio.h"
#include <iostream>

using namespace std;

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

