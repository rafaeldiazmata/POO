//ruleta.cc
//Realizado por Rafael Carlos Díaz Mata

//Este archivo contiene el cuerpo de las funciones de la clase ruleta
/*En algunas funciones, se utiliza para iterar en una lista el tipo de variable auto, que equivaldria (en nuestro caso) a poner:
std::list<Jugador>::iterator i == auto i*/

#include "ruleta.h"
#include <fstream>
#include <ctime>

bool Ruleta::setBanca(int const &banca){


	if(banca){
		return false;
	}
	banca_=banca;
	return true;
}

bool Ruleta::setBola(int const &bola){

	if(bola<0 || bola>36){
		return false;
	}
	bola_=bola;
	return true;
}

bool Ruleta::addJugador(Jugador const &jugador){

	for(std::list<Jugador>::iterator i = jugadores_.begin(); i != ugadores.end(); i++){
		if(i->getDNI()==jugador.getDNI()){
			return false;
		}
	}


	jugadores_.push_back(jugador);
	std::fstream f;
	std::string nombrefichero= jugador.getDNI() + ".txt";

	f.open(nombrefichero, std::ios_base::app);
	fclose();
	return true;
}

int Ruleta::deleteJugador(std::string const &dni){
	if(jugadores_.empty()) return -1;

	for(std::list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); i++){
		if(i->getDNI()==dni){
			jugadores_.erase(i);
			return 1;
		}
	}
	return -2;
}

int Ruleta::deleteJugador(Jugador const &jugador){
	if(jugadores_.empty()) return -1;

	for(auto i=jugadores_.begin(); i!=jugadores_.end(); i++){
		if(i->getDNI()==jugador.getDNI()){
			jugadores_.erase(i);
			return 1;
		}
	}
	return -2;
}

void Ruleta::escribeJugadores(){
	std::fstream f;
	f.open("jugadores.txt", std::ios::out);
	for(auto i=jugadores_.begin(); i!=jugadores_.end(); i++){
		f<<i->getDNI()<<","<<
		i->getCodigo()<<","<<
        i->getNombre()<<","<<
        i->getApellidos()<<","<<
        i->getDireccion()<<","<<
        i->getLocalidad()<<","<<
        i->getProvincia()<<","<<
        i->getPais()<<","<<
        i->getDinero()<<","<<std::endl;
	}
	f.close();
}

void Ruleta::leeJugadores(){
	jugadores_.empty();
	std::fstream f;
	f.open("jugadores.txt", std::ios::in);

	char dni[255], codigo[255], nombre[255], apellidos[255];
	char direccion[255], localidad[255], provincia[255], pais[255], dinero[255];


	while(f.getline(dni,255,",")){

		f.getline(codigo, 255, ',');
        f.getline(nombre, 255, ',');
        f.getline(apellidos, 255, ',');
        f.getline(direccion, 255, ',');
        f.getline(localidad, 255, ',');
        f.getline(provincia, 255, ',');
        f.getline(pais, 255, ',');
        f.getline(dinero, 255, '\n');

        Jugador aux (dni, codigo, nombre, apellidos, 0, direccion, localidad, provincia, pais, atoi(dinero));
        jugadores_.push_back(aux);
	}
	f.close();
}


void Ruleta::getPremios(){
	for(auto i=jugadores_.begin(); i!=jugadores_.end(); i++){
		i->setApuestas();
		std::list<Apuesta> aux = i->getApuestas();
		for(auto j=aux.begin(); j!=aux.end(); j++){
			Apuesta apuesta= *j;
			switch(apuesta.tipo){

				case 1:

					if(bola_ == stoi(apuesta.valor)){
						setBanca(getBanca() - 35*apuesta.cantidad);
						i->setDinero(i->getDinero() + (apuesta.cantidad*35));
					}else{
						setBanca(getBanca() + apuesta.cantidad);
						i->setDinero(i->getDinero() - apuesta.cantidad);
					}
				break;

				case 2:

					if(bola_==0){
						setBanca(getBanca() + apuesta.cantidad);
						i->setDinero(i->getDinero() - apuesta.cantidad);
					}

					else if((apuesta.valor == "rojo"&& esRoka(bola_)) || (apuesta.valor=="negro" && !esRoja(bola_))){
						setBanca(getBanca() - apuesta.cantidad);
						i->setDinero(i->getDinero()+(apuesta.cantidad));						
					}

					else{
						setBanca(getBanca() + apuesta.cantidad);
						i->setDinero(i->getDinero() - apuesta.cantidad);
					}
				break;

				case 3:

					if(bola_==0){
						setBanca(getBanca() + apuesta.cantidad);
						i->setDinero(i->getDinero() - apuesta.cantidad);
					}
					else if( (apuesta.valor=="par"&& esPar(bola_)) || (apuesta.valor=="impar" && !esPar(bola_))){
						setBanca(getBanca() - apuesta.cantidad);
						i->setDinero(i->getDinero() + (apuesta.cantidad));
					}
					else{
						setBanca(getBanca() + apuesta.cantidad);
						i->setDinero(i->getDinero() - apuesta.cantidad);
					}
				break;

				case 4:

					 if (bola_==0){                                                                                          //Si la bola que sale es 0, gana la banca y pierde el jugador
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }

                    else if ( (apuesta.valor=="alto"&& esAlta(bola_)) || (apuesta.valor=="bajo" && !esAlta(bola_))){        //Si la bola y la apuesta son ambas alta o ambas baja, gana el jugador y pierde la banca
                        setBanca(getBanca() - apuesta.cantidad);
                        i->setDinero(i->getDinero()+(apuesta.cantidad));
                    }

                    else{                                                                                                   //Si la bola y la apuesta son una alta y una baja (o viceveersa), gana la banca y pierde el jugador
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                        
                    }

				break;
			}
		}
	}
}

bool Ruleta::esRoja(int const &valor){

	int rojos[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
	for (int i = 0; i < 18; ++i)
	{
		if(valor==rojos[i]){
			return true;
		}
	}
	return false;
}

bool Ruleta::esPar(int const &valor){

	if(valor%2==0){
		return true;
	}
	return false;
}

bool Ruleta::esAlta(int const &valor){
	if(valor>=1 && valor <=18){
		return false;
	}
	return true;
}