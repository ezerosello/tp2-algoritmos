#define NULL 0
#include "linea.h"

Linea::Linea(){

	this->numeroLinea = NULL;
	this->cantidadParadas = NULL;

}

Linea::~Linea(){

}

int Linea::getNumeroLinea(){
	return this->numeroLinea;
}

int Linea::getCantidadParadas(){
	return this->cantidadParadas;
}

void Linea::sumarCantidad(){
	this->cantidadParadas++;

}

void Linea::agregarNumeroLinea(int numero){

	this->numeroLinea = numero;
}
