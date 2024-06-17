#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "barrio.h"
#include "parada.h"
#include "lista.h"
#include "inicializar_datos.h"
#include "punto_3.h"
#include "punto_2.h"

using namespace std;

int main() {
    Lista<Barrio*>* barrios = new Lista<Barrio*>();
    inicializarDatos("paradas-de-colectivo.csv", barrios);

   int linea = 152;
   Lista<Parada*>* paradas = obtenerParadasDeLinea(linea, barrios);


   std::string ParadaMasCercana = obtenerParadaMasCercana(-59, -35, barrios); 


    paradas->iniciarCursor();
    while (paradas->avanzarCursor()) {
        Parada* parada = paradas->obtenerCursor();
        cout << "- Calle: " << parada->getCalle() << endl;
        cout << "- Dirección: " << parada->getDireccion() << endl;
        cout << "- Coordenada X: " << parada->getCoordenadaX() << endl;
        cout << "- Coordenada Y: " << parada->getCoordenadaY() << endl;
        cout << "- Cantidad de líneas: " << parada->getCantidadDeLineas() << endl;
        cout << "- paradaMasCercana: " << ParadaMasCercana << endl;
        unsigned int cantidadDeLineas = parada->getCantidadDeLineas();
        int* lineas = parada->getLineas();
        cout << "- Líneas: ";
        for (unsigned int i = 0; i < cantidadDeLineas; i++) {
            cout << lineas[i] << " ";
        }
        cout << endl;
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
    
    return 0;
}
