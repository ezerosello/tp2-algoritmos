/*
 * lecturaDeArchivos.cpp
 *
 *  Created on: 14 jun. 2024
 *      Author: renzo
 */


/*
 * main.cpp
 *
 *  Created on: 13 jun. 2024
 *      Author: renzo
 */

/*
#include <iostream>
//Proporciona funcionalidades para trabajar con flujos de datos. (No lee ni escribe archivos)
#include <sstream>
//Permite la manipulacion de archivos desde el programa. (Lee y escribe archivos)
#include <fstream>

#define NOMBRE_ARCHIVO "paradas-de-colectivo.csv"

using namespace std;

int main(){

	ifstream archivo(NOMBRE_ARCHIVO); //Abrimos el archivo
	string linea;
	char delimitador = ',';

	//Leemos la primer linea del archivo para descartarla, ya que es el encabezado
	getline(archivo, linea);

	//Leemos todas las lineas
	while(getline(archivo,linea)){
		stringstream stream(linea); //Convierte la cadena en un stream
		string CALLE, ALT_PLANO, DIRECCION, coord_x, coord_y, COMUNA, BARRIO;

		//Extrae todos los valores de esa fila
		getline(stream, CALLE, delimitador);
		getline(stream, ALT_PLANO, delimitador);
		getline(stream, DIRECCION, delimitador);
		getline(stream, coord_x, delimitador);
		getline(stream, coord_y, delimitador);
		getline(stream, COMUNA, delimitador);
		getline(stream, BARRIO, delimitador);

		cout << "Calle: " << CALLE << endl;
		cout << "Altura: " << ALT_PLANO << endl;
		cout << "Direccion: " << DIRECCION << endl;
		cout << "Coordenada x: " << coord_x << endl;
		cout << "Cordenada y: " << coord_y << endl;
		cout << "Comuna: " << COMUNA << endl;
		cout << "Barrio: " << BARRIO << endl;


	}
	archivo.close();


	//cout << "Hola mundo" << endl;
	return 0;
}
*/

