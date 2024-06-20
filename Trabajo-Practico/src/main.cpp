#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "barrio.h"
#include "parada.h"
#include "lista.h"
#include "inicializar_datos.h"
#include "punto_4.h"
#include "menu.h"
#include "punto_2.h"
#include "punto_3.h"
#include "punto_5.h"


int main() {
    Lista<Barrio*>* barrios = new Lista<Barrio*>();

    // para punto 2
    double coordX;
	double coordY;

	//para punto 3
	int linea;

	//para punto 5;
	std::string nombreBarrio;
	unsigned int lineaColectivo;
	double usuarioCoordX;
	double usuarioCoordY;

    inicializarDatos("paradas-de-colectivo.csv", barrios);

    std::string ingresoUsuario;
        char opcionElegida;
        bool continuar = true;

        while(continuar){

            imprimirOpciones();
            std::cout << "Ingrese una opcion: ";
            std::getline(std::cin, ingresoUsuario);

            opcionElegida = ingresoUsuario[0];

            if(!validarOpcionRango(opcionElegida) || !validarOpcion(ingresoUsuario) || ingresoUsuario.empty()){
                std::cout << "ingreso incorrecto, por favor ingreso una opcion valida" << std::endl;
            }
            else{
                switch (opcionElegida)
                {
                case '1':
                    std::cout << "opcion 1" ;

                    break;

                case '2':

                	std::cout << "Ingrese coordenada x: ";
                	std::cin >> coordX;
                	std::cout << "Ingrese coordenada y: ";
                	std::cin >> coordY;
                    obtenerParadaMasCercana(coordX,coordY,barrios);
                    break;

                case '3':

                	std::cout << "Ingrese una linea de colectivo: ";
                	std::cin >> linea;
                	obtenerParadasDeLinea(linea,barrios);
                    break;

                case '4':

                    cantidadDeParadasPorLineaDeColectivo(barrios);
                    break;

                case '5':
                	std::cout << "Ingrese el nombre del barrio: ";
                	std::cin >> nombreBarrio;
                	std::cout << "Ingrese una linea de colectivo: ";
                	std::cin >> lineaColectivo;
                	std::cout << "Ingrese coordenada x: ";
                	std::cin >> usuarioCoordX;
                	std::cout << "Ingrese coordenada y: ";
                	std::cin >> usuarioCoordY;
                	paradasLineaBarrioOrdenadas(nombreBarrio, lineaColectivo, usuarioCoordX, usuarioCoordY, barrios);
                    break;

                case '6':

                    std::cout << "Gracias por utilizar nuestro programa" << std::endl;
                    continuar = false;
                    break;
                }
            }
        }


        return 0;

    //imprimirArchivoParadasDeColectivo(barrios);
}
