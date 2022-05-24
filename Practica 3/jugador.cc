//jugador.cc
//Realizado por Rafael Carlos Díaz Mata
//Contiene el cuerpo de las funciones de la clase Jugador

#include "jugador.h"

void Jugador::setApuestas(){
	apuestas_.clear();
	std::ifstream f((getDNI() + ".txt"));

	if(!f){
		EXIT_FAILURE;
	}

	Apuesta apuesta;
	std::string cadena;
	getline(f, cadena, ',');

	while(!f.eof()){


		apuesta.tipo = std::stoi(cadena);
		getline(f,cadena,',');

		apuesta.valor = cadena;
		getline(f,cadena,'\n');

		apuesta.cantidad = std::stoi(cadena);
		apuestas_.push_back(apuestas);

		getline(f,cadena,',');
	}

	f.close();
}