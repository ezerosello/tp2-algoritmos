#include "parada.h"

using namespace std;

Parada::Parada(std::string calle, std::string direccion, double coordenadaX, double coordenadaY, unsigned int cantidadDeLineas, int *lineas)
{
  this->calle = calle;
  this->direccion = direccion;
  this->coordenadaX = coordenadaX;
  this->coordenadaY = coordenadaY;
  this->cantidadDeLineas = cantidadDeLineas;

  this->lineas = new int[cantidadDeLineas];
  for (unsigned int i = 0; i < cantidadDeLineas; i++)
  {
    this->lineas[i] = lineas[i];
  }
};

Parada::~Parada()
{
  delete this->lineas;
}

string Parada::getCalle()
{
  return this->calle;
};

string Parada::getDireccion()
{
  return this->direccion;
};

double Parada::getCoordenadaX()
{
  return this->coordenadaX;
};

double Parada::getCoordenadaY()
{
  return this->coordenadaY;
};

unsigned int Parada::getCantidadDeLineas()
{
  return this->cantidadDeLineas;
};

int *Parada::getLineas()
{
  return this->lineas;
};
