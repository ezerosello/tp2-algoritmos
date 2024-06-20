#include "punto5.h"
#include "punto_2.h"

Lista<Parada*>* paradasLineaBarrioOrdenadas(std::string nombreBarrio, unsigned int lineaColectivo, double usuarioCoordX, double usuarioCoordY, Lista<Barrio*>* barrios){

    Lista<Parada*>* paradasLineaBarrioOrdenadas = new Lista<Parada*>(); //creo una lista de paradas
    paradasLineaBarrioOrdenadas->iniciarCursor(); 
    paradasLineaBarrioOrdenadas->avanzarCursor(); //inicio el cursor y lo apunto a la primera posicion de la lista de paradas

    barrios->iniciarCursor(); //recorre los barrios

    unsigned int contadorBarrios = 0;

    while (contadorBarrios < barrios->getTamanio()){
        Barrio *barrioActual = barrios->obtenerCursor(); //obtiene el barrio actual

        if (barrioActual->getNombre() == nombreBarrio){ //chequea si el barrio actual coincide con el que buscamos 
            Lista<Parada*>* listaParadas = barrioActual->getParadas(); //crea una lista de las paradas del barrio
            listaParadas->iniciarCursor(); //recorre las paradas del barrio
            unsigned int contadorParadas = 0;
            double distanciaParadaMasProxima = 0;

            while (contadorParadas < listaParadas->getTamanio()){
                Parada* paradaActual = listaParadas->obtenerCursor(); // obtiene la parada actual
                int* todasLasLineas = paradaActual->getLineas(); // arma un vector de enteros con todas las lineas de la parada

                for (unsigned int i=0; i < paradaActual->getCantidadDeLineas(); i++){ //recorre todas las lineas de una parada
                    if (todasLasLineas[i] == lineaColectivo && paradasLineaBarrioOrdenadas->obtenerCursor()==NULL){ //si la linea coincide y no existen elementos en la lista de paradas
                        paradasLineaBarrioOrdenadas->agregarAlInicio(paradaActual); //define el primer elemento de la lista de paradas
                        double distanciaX = usuarioCoordX - paradaActual->getCoordenadaX();
                        double distanciaY = usuarioCoordX - paradaActual->getCoordenadaY();

                        double distancia = distanciaX*distanciaX + distanciaY*distanciaY;
                        distanciaParadaMasProxima = distancia; //establece la distancia mas proxima como la de la primera parada
                    }
                    if (todasLasLineas[i] == lineaColectivo && paradasLineaBarrioOrdenadas->obtenerCursor()!=NULL){ //si coincide la linea y existe un elemento en la lista de paradas
                        for (unsigned int j=0; j < paradasLineaBarrioOrdenadas->getTamanio(); j++){
                            double distanciaX = usuarioCoordX - paradaActual->getCoordenadaX();
                            double distanciaY = usuarioCoordX - paradaActual->getCoordenadaY();

                            double distancia = distanciaX*distanciaX + distanciaY*distanciaY; //saca la distancia a la parada actual

                            if (distanciaParadaMasProxima == 0 || distancia < distanciaParadaMasProxima){ //si la distancia es menor o si no existen paradas, agrega la parada al inicio
                                paradasLineaBarrioOrdenadas->agregarAlInicio(paradaActual);
                                distanciaParadaMasProxima = distancia;
                            } else {
                                paradasLineaBarrioOrdenadas->agregar(paradaActual); //si la distancia no es menor, la agrega al final
                            }
                            
                        }
                    }
                }
                contadorParadas++;
                listaParadas->avanzarCursor(); //paso a la siguiente parada
            }

            contadorBarrios = barrios->getTamanio(); //salgo del primer while porque ya encontro el barrio
        } else {
            contadorBarrios++;
            barrios->avanzarCursor();
        }
    }

    return paradasLineaBarrioOrdenadas;
}