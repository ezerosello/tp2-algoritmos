#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <climits>
#include "barrio.h"
#include "parada.h"
#include "lista.h"
#include "inicializar_datos.h"
#include "punto_4.h"
#include "menu.h"
#include "punto_1.h"
#include "punto_2.h"
#include "punto_3.h"
#include "punto_5.h"

int main() {
    Lista<Barrio*>* barrios = new Lista<Barrio*>();

    inicializarDatos("../paradas-de-colectivo.csv", barrios);

    std::string ingresoUsuario;
    char opcionElegida;
    bool continuar = true;

    while(continuar){

        imprimirOpciones();
        std::cout << "Ingrese una opcion: ";
        std::getline(std::cin, ingresoUsuario);

        opcionElegida = ingresoUsuario[0];

        if(!validarOpcionRango(opcionElegida) || !validarOpcion(ingresoUsuario) || ingresoUsuario.empty()){
            std::cout << "Ingreso incorrecto, por favor ingrese una opcion valida" << std::endl;
        }
        else {
            switch (opcionElegida)
            {
                case '1':
                {
                    std::string barrioPorBuscar;                   
                    std::cout << "~~~	Has elejido la opcion 1		~~~" << std::endl << std::endl;
                    std::cout<< "    Introduce el barrio que quieras buscar :: ";
                    getline(std::cin, barrioPorBuscar);
                    while(!verificarIngresoValido(barrioPorBuscar)) {
                        std::cout<< "    Introduce un nombre de barrio valido :: ";
                        getline(std::cin, barrioPorBuscar);
                    }

                    Barrio * barrio = mostrarPorBarrio(barrios, barrioPorBuscar);
                    if (!barrio) {
                        std::cout << "ººººººººººººººººººººººººººººººººº" << std::endl;
                        std::cout << "No se ha encontrado resultados." << std::endl;
                        std::cout << "ºººººººººººººººººººººººººººººººººº" << std::endl;
                        break;
                    }
                    std::cout << std::endl;

                    std::cout << "ºººººººº " << std::endl;
                    std::cout << "ºººººº	 ";
                    std::cout << barrio->getNombre() << " tiene " << barrio->getParadas()->getTamanio() << " parada(s)" << std::endl;
                    std::cout << "ºººººººº " << std::endl;
                    std::cout << std::endl;
                    break;
                }
                case '2':
                {
                    double coordX;
                    double coordY;
                    
                    std::cout << "Ingrese coordenada x: ";
                    std::cin >> coordX;
                    std::cin.ignore(INT_MAX,'\n');
                    std::cout << "Ingrese coordenada y: ";
                    std::cin >> coordY;
                    std::cin.ignore(INT_MAX,'\n');
                    std::string paradaCercana = obtenerParadaMasCercana(coordX,coordY,barrios);
                    std::cout << "La parada mas cercana es: " << paradaCercana << std::endl;
                    break;
                }
                case '3':
                {
                    int linea;
                    
                    std::cout << "Ingrese una linea de colectivo: ";
                    std::cin >> linea;
                    std::cin.ignore(INT_MAX,'\n');
                    Lista<Parada*>* paradas = obtenerParadasDeLinea(linea,barrios);
                    std::cout << "Las paradas de la línea son las siguientes:" << std::endl;
                    imprimirParadasDeLinea(paradas);
                    break;
                }
                case '4':
                {
                    cantidadDeParadasPorLineaDeColectivo(barrios);
                    break;
                }
                case '5':
                {
                    std::string nombreBarrio;
                    int lineaColectivo;
                    double usuarioCoordX;
                    double usuarioCoordY;

                    std::cout << "Ingrese el nombre del barrio: ";
                    getline(std::cin, nombreBarrio);
                    std::cout << "Ingrese una linea de colectivo: ";
                    std::cin >> lineaColectivo;
                    std::cin.ignore(INT_MAX,'\n');
                    std::cout << "Ingrese coordenada x: ";
                    std::cin >> usuarioCoordX;
                    std::cin.ignore(INT_MAX,'\n');
                    std::cout << "Ingrese coordenada y: ";
                    std::cin >> usuarioCoordY;
                    std::cin.ignore(INT_MAX,'\n');
                    paradasLineaBarrioOrdenadas(nombreBarrio, lineaColectivo, usuarioCoordX, usuarioCoordY, barrios);
                    break;
                }
                case '6':
                {
                    std::cout << "Gracias por utilizar nuestro programa" << std::endl;
                    continuar = false;
                    break;
                }
            }
        }
    }

    delete barrios;

    return 0;
}
