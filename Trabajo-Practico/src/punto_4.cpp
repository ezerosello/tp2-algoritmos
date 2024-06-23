#include "punto_4.h"
#include <iostream>

void imprimirParadasPorLinea(Lista<Linea *> *lineas)
{
	if (!lineas->estaVacia())
	{
		lineas->iniciarCursor();
		while (lineas->avanzarCursor())
		{
			Linea *lineaActual = lineas->obtenerCursor();
			std::cout << "Linea: " << lineaActual->getNumeroLinea() << " | " << "Cantidad de paradas: " << lineaActual->getCantidadParadas() << std::endl;
		}
	}
}

bool estaEnListaLineas(int lineaParada, Lista<Linea *> *lineas)
{
	bool devolver = false;

	if (lineas->estaVacia())
	{
		devolver = false;
	}
	else
	{
		lineas->iniciarCursor();
		while (lineas->avanzarCursor())
		{
			Linea *linea = lineas->obtenerCursor();

			if (linea->getNumeroLinea() == lineaParada)
			{
				devolver = true;
			}
		}
	}

	return devolver;
}

void recorrerParada(Parada *parada, int *lineasParada, Lista<Linea *> *lineas)
{
	for (unsigned int i = 0; i < parada->getCantidadDeLineas(); i++)
	{
		if (!estaEnListaLineas(lineasParada[i], lineas))
		{

			Linea *lineaNueva = new Linea();
			lineas->agregar(lineaNueva);
			lineaNueva->agregarNumeroLinea(lineasParada[i]);
			lineaNueva->sumarCantidad();
		}
		else
		{
			lineas->iniciarCursor();
			while (lineas->avanzarCursor())
			{
				Linea *linea = lineas->obtenerCursor();

				if (linea->getNumeroLinea() == lineasParada[i])
				{
					linea->sumarCantidad();
					break;
				}
			}
		}
	}
}

void crearListaLineas(Lista<Barrio *> *barrios, Lista<Linea *> *lineas)
{
	barrios->iniciarCursor();
	while (barrios->avanzarCursor())
	{

		Barrio *barrio = barrios->obtenerCursor();
		Lista<Parada *> *paradas = barrio->getParadas();

		paradas->iniciarCursor();
		while (paradas->avanzarCursor())
		{
			Parada *parada = paradas->obtenerCursor();
			int *lineasParada = parada->getLineas();

			recorrerParada(parada, lineasParada, lineas);
		}
	}
}

void cantidadDeParadasPorLineaDeColectivo(Lista<Barrio *> *barrios)
{
	Lista<Linea *> *lineas = new Lista<Linea *>();

	crearListaLineas(barrios, lineas);
	imprimirParadasPorLinea(lineas);

	delete lineas;
}
