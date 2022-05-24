//jugador.cc
//Realizado por Rafael Carlos Díaz Mata
//Contiene la clase Jugador

#include <iostream>
#include "jugador.h"

int main(){

	std::string dni;
	std::string codigo;
	std::list<Apuesta> apuestas;

	std::cout<<"Programa para comprobar el funcionamiento de la clase Jugador"<<std::endl;
	std::cout<<"Bienvenido, introduzca los datos del jugador: "<<std::endl;

	std::cout<<"DNI: ";
	std::cin>>dni;
	std::cout<<"Codigo: ";
	std::cin>>codigo;
	std::cout<<std::endl;

	Jugador j(dni,codigo);

	j.setApuestas();
	apuestas = j.getApuestas();

	int n=1;
	for(auto i= apuestas.begin(); i!=apuestas.end(); i++){
		std::cout<<"Apuesta "<<n<<": "<<std::endl;
		std::cout<<"- Tipo:  "<<i->tipo<<": "<<std::endl;
		std::cout<<"- Valor:  "<<i->valor<<": "<<std::endl;
		std::cout<<"- Cantidad:  "<<i->cantidad<<": "<<std::endl;
		std::cout<<std::endl;
	}

	return 0;

}