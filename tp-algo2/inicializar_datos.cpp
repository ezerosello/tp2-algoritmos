#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "../includes/inicializar_datos.h"
#include "../includes/parada.h"

using namespace std;

void inicializarDatos(const string& archivo, Lista<Barrio*>* barrios) {
    ifstream file(archivo.c_str());
    string lineaCSV;

    getline(file, lineaCSV);

    while (getline(file, lineaCSV)) {
        stringstream ss(lineaCSV);
        string calle, alturaPlano, direccion, coordenadaX, coordenadaY, comuna, barrioNombre;
        string l1, l1_sen, l2, l2_sen, l3, l3_sen, l4, l4_sen, l5, l5_sen, l6, l6_sen;
        
        getline(ss, calle, ',');
        if (calle.size() > 0 && calle[0] == '"') {
            calle.erase(0, 1);
            if (calle[calle.size() - 1] == '"') {
                calle.erase(calle.size() - 1);
            } else {
                string resto;
                getline(ss, resto, '"');
                calle += "," + resto;
                getline(ss, resto, ',');
            }
        }
        
        getline(ss, alturaPlano, ',');
        if (alturaPlano.size() > 0 && alturaPlano[0] == '"') {
            alturaPlano.erase(0, 1);
            if (alturaPlano[alturaPlano.size() - 1] == '"') {
                alturaPlano.erase(alturaPlano.size() - 1);
            } else {
                string resto;
                getline(ss, resto, '"');
                alturaPlano += "," + resto;
                getline(ss, resto, ',');
            }
        }
        
        getline(ss, direccion, ',');
        if (direccion.size() > 0 && direccion[0] == '"') {
            direccion.erase(0, 1);
            if (direccion[direccion.size() - 1] == '"') {
                direccion.erase(direccion.size() - 1);
            } else {
                string resto;
                getline(ss, resto, '"');
                direccion += "," + resto;
                getline(ss, resto, ',');
            }
        }
        
        getline(ss, coordenadaX, ',');
        
        getline(ss, coordenadaY, ',');
        
        getline(ss, comuna, ',');
        
        getline(ss, barrioNombre, ',');
        
        getline(ss, l1, ',');
        if (l1.size() > 0 && l1[0] == '"') {
            l1.erase(0, 1);
            if (l1[l1.size() - 1] == '"') {
                l1.erase(l1.size() - 1);
            } else {
                string resto;
                getline(ss, resto, '"');
                l1 += "," + resto;
                getline(ss, resto, ',');
            }
        }
        
        getline(ss, l1_sen, ',');
        
        getline(ss, l2, ',');
        if (l2.size() > 0 && l2[0] == '"') {
            l2.erase(0, 1);
            if (l2[l2.size() - 1] == '"') {
                l2.erase(l2.size() - 1);
            } else {
                string resto;
                getline(ss, resto, '"');
                l2 += "," + resto;
                getline(ss, resto, ',');
            }
        }
        
        getline(ss, l2_sen, ',');
        
        getline(ss, l3, ',');
        if (l3.size() > 0 && l3[0] == '"') {
            l3.erase(0, 1);
            if (l3[l3.size() - 1] == '"') {
                l3.erase(l3.size() - 1);
            } else {
                string resto;
                getline(ss, resto, '"');
                l3 += "," + resto;
                getline(ss, resto, ',');
            }
        }
        
        getline(ss, l3_sen, ',');
        
        getline(ss, l4, ',');
        if (l4.size() > 0 && l4[0] == '"') {
            l4.erase(0, 1);
            if (l4[l4.size() - 1] == '"') {
                l4.erase(l4.size() - 1);
            } else {
                string resto;
                getline(ss, resto, '"');
                l4 += "," + resto;
                getline(ss, resto, ',');
            }
        }
        
        getline(ss, l4_sen, ',');
        
        getline(ss, l5, ',');
        if (l5.size() > 0 && l5[0] == '"') {
            l5.erase(0, 1);
            if (l5[l5.size() - 1] == '"') {
                l5.erase(l5.size() - 1);
            } else {
                string resto;
                getline(ss, resto, '"');
                l5 += "," + resto;
                getline(ss, resto, ',');
            }
        }
        
        getline(ss, l5_sen, ',');
        
        getline(ss, l6, ',');
        
        if (l6.size() > 0 && l6[0] == '"') {
            l6.erase(0, 1);
            if (l6[l6.size() - 1] == '"') {
                l6.erase(l6.size() - 1);
            } else {
                string resto;
                getline(ss, resto, '"');
                l6 += "," + resto;
                getline(ss, resto, ',');
            }
        }
        getline(ss, l6_sen, ',');
        
        double coordX = atof(coordenadaX.c_str());
        double coordY = atof(coordenadaY.c_str());

        int lineasAux[6] = {0};
        unsigned int cantidadDeLineas = 0;
        
        if (!l1.empty()) lineasAux[cantidadDeLineas++] = atoi(l1.c_str());
        if (!l2.empty()) lineasAux[cantidadDeLineas++] = atoi(l2.c_str());
        if (!l3.empty()) lineasAux[cantidadDeLineas++] = atoi(l3.c_str());
        if (!l4.empty()) lineasAux[cantidadDeLineas++] = atoi(l4.c_str());
        if (!l5.empty()) lineasAux[cantidadDeLineas++] = atoi(l5.c_str());
        if (!l6.empty()) lineasAux[cantidadDeLineas++] = atoi(l6.c_str());
        
        int *lineas = new int[cantidadDeLineas];
        for (unsigned int i = 0; i < cantidadDeLineas; ++i) {
            lineas[i] = lineasAux[i];
        }
        
        Parada* parada = new Parada(calle, direccion, coordX, coordY, cantidadDeLineas, lineas);
        
        Barrio* barrio = NULL;
        barrios->iniciarCursor();
        while (barrios->avanzarCursor()) {
            Barrio* currentBarrio = barrios->obtenerCursor();
            if (currentBarrio->getNombre() == barrioNombre) {
                barrio = currentBarrio;
                break;
            }
        }
        
        if (barrio == NULL) {
            Lista<Parada*>* paradas = new Lista<Parada*>();
            barrio = new Barrio(barrioNombre, paradas);
            barrios->agregar(barrio);
        }
        
        barrio->getParadas()->agregar(parada);
    }
    
    file.close();
}