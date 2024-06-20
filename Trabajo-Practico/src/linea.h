/*
 * linea.h
 *
 *  Created on: 19 jun. 2024
 *      Author: renzo
 */

#ifndef LINEA_H_
#define LINEA_H_

class Linea{

private:
	int numeroLinea;
	int cantidadParadas;


public:
	Linea();
	virtual ~Linea();
	int getNumeroLinea();
	int getCantidadParadas();
	void sumarCantidad();
	void agregarNumeroLinea(int numero);
};


#endif /* LINEA_H_ */
