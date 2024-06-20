#include <iostream>
#include <string>

void imprimirOpciones(){
    std::cout <<"\n----------------MENU PRINCIPAL-------------\n" << std::endl;
    std::cout << "1. Obtener cantidad de paradas por barrio\n" << std::endl;
    std::cout << "2. Obtener parada mas cercana segun una coordenada\n" << std::endl;
    std::cout << "3. Paradas de una linea de colectivo\n" << std::endl;
    std::cout << "4. Cantidad de paradas por linea de colectivo\n" << std::endl;
    std::cout << "5. Paradas ordenadas por distancia segun barrio, linea colectivo y coordenadas de origen\n" <<  std::endl;
    std::cout << "6. Salir\n" <<  std::endl;
    std::cout <<"-------------------------------------------\n" << std::endl;
}

bool validarOpcionRango(char opcion){
    if(opcion < '1' || opcion > '6'){
        return false;
    }
    return true;
}

bool validarOpcion(std::string opcion){
    if(opcion.length() != 1){
        return false;
    }
    return true;
}

int main() {

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
                std::cout << "Opcion 1" << std::endl;
                break;
            case '2':
                std::cout << "Opcion 2" << std::endl;
                break;
            case '3':
                std::cout << "Opcion 3" << std::endl;
                break;
            case '4':
                std::cout << "Opcion 4" << std::endl;
                break;
            case '5':
                std::cout << "Opcion 5" << std::endl;
                break;
            case '6':
                std::cout << "gracias por utilizar nuestro programa" << std::endl;
                continuar = false;
                break;
            }
        }
    }


    return 0;
}

