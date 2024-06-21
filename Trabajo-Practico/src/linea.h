#ifndef LINEA_H_
#define LINEA_H_

class Linea{

private:
	int numeroLinea;
	int cantidadParadas;


public:

	/*
	*PRE: -
	*POST: crea una linea con el numero de la linea y la cantidad de paradas en 0.
	*/

	Linea();

	/*
  	*PRE: -
  	*POST: -
 	*/

	virtual ~Linea();

	/*
  	*PRE: -
  	*POST: devuelve el numero de la linea.
 	*/

	int getNumeroLinea();

	/*
  	*PRE: -
  	*POST: devuelve la cantidad de paradas de la linea.
  	*/

	int getCantidadParadas();

	/*
  	*PRE: -
  	*POST: suma 1 a la cantidad de paradas de la linea.
  	*/

	void sumarCantidad();

	/*
  	*PRE: -
  	*POST: agrega el numero de la linea.
  	*/

	void agregarNumeroLinea(int numero);
};


#endif /* LINEA_H_ */
