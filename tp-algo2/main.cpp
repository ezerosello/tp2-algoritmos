#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "../includes/barrio.h"
#include "../includes/parada.h"
#include "../includes/lista.h"
#include "../includes/inicializar_datos.h"

using namespace std;

int main() {
    Lista<Barrio*>* barrios = new Lista<Barrio*>();
    inicializarDatos("paradas-de-colectivo.csv", barrios);

    barrios->iniciarCursor();
    while (barrios->avanzarCursor()) {
        Barrio* barrio = barrios->obtenerCursor();
        cout << "Barrio: " << barrio->getNombre() << endl;
        Lista<Parada*>* paradas = barrio->getParadas();
        cout << endl;
        
        paradas->iniciarCursor();
        while (paradas->avanzarCursor()) {
            Parada* parada = paradas->obtenerCursor();
            cout << "- Calle: " << parada->getCalle() << endl;
            cout << "- Dirección: " << parada->getDireccion() << endl;
            cout << "- Coordenada X: " << parada->getCoordenadaX() << endl;
            cout << "- Coordenada Y: " << parada->getCoordenadaY() << endl;
            cout << "- Cantidad de líneas: " << parada->getCantidadDeLineas() << endl;
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
    }
    
    return 0;
}
