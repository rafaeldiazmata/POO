//Archivo ruletamenu.cc
//Programa que sirve para utilizar las funciones de la ruleta con un menu

#include <iostream>
#include "ruleta.h"

int main(){

	Crupier c("1234568" , "crupier1");
	Ruleta r(c);

	Jugador j1("11XX", "jugador1");
	Jugador j2("22XX", "jugador2");
	Jugador j3("33xx", "jugador3");

	std::string dni;
	std::list<Jugador> jugadoresActivos_;

	int nJugadore, nLanzamiento, dineroMesa, gananciaBanca;

	std::cout<<"Bienvenido \n"<<std::endl;
	int opcion_=0;

	while(opcion_!=7){
		std::cout<<"------------------------------------------------------------"<<std::endl;
		std::cout<<"Introduzca una opcion: "<<std::endl;
		std::cout<<"1. Cargar los jugadores del fichero"<<std::endl;
		std::cout<<"2. Guardar los jugadores en el fichero"<<std::endl;
		std::cout<<"3. Ver el estado de la ruleta"<<std::endl;
		std::cout<<"4. Girar Ruleta"<<std::endl;
		std::cout<<"5. Eliminar Jugador de la mesa"<<std::endl;
		std::cout<<"6. Añadir jugador a la mesa "<<std::endl;
		std::cout<<"7. Salir"<<std::endl;
		std::cout<<"------------------------------------------------------------"<<std::endl;


		std>>cin>>opcion_;

		switch(opcion_){

			case 1:

				std::cout<<"Se van a cargar los jugadores en el fichero."<<std::endl;
				r.leeJugadores();
				std::cout<<"Jugadores cargados con exito"<<std::endl;

			break;

			case 2:

				std::cout<<"Se van a guardar los jugadores en el fichero."<<std::endl;
				r.escribirJugadores();
				std::cout<<"Jugadores guardados con exito"<<std::endl;

			break;

			case 3:

				r.getEstadoRuleta(nJugadores, dineroMesa ,nLanzamientos, ganaciaBanca);
				std::cout<<"Estado de la ruleta: "<<std::endl;
				std::cout<<"Numero de jugadores: "<<nJugadores<<std::endl;
				std::cout<<"Dinero en la mesa: "<<dineroMesa<<std::endl;
				std::cout<<"Numero de lanzamientos: "<<nLanzamientos<<std::endl;
				std::cout<<"Ganancia de la banca: "<<ganaciaBanca<<std::endl;

			break;

			case 4:

				std::cout<<"La ruleta va a girar: "<<std::endl;
				if(r.hayJugadores()==false){
					std::cout<<"No hay Jugadores."<<std::endl;
				}
				else{
					r.giraRuleta();
					std::cout<<"Valor de la bola: "<<r.getBola()<<std::endl;
					r.getPremios();
					jugadoresActivos_ = r.getJugadores();
					for(auto i = jugadoresActivos_.begin(); i != jugadoresActivos_.end(); i++){
						std::cout<<"Dinero obtenido tras el giro de la ruleta del jugador con dni: "<<(i->getDNI())<<": "<<(i->getDinero())<<std::endl;	
					}
					std::cout<<"Dinero banca: "<<r.getBanca()<<std::endl;
				}

			break;

			case 5:

				std::cout<<"Introduzca el DNI del jugador que quiere eliminar"<<std::endl;
                std::cin>>dni;

                if (r.deleteJugador(dni) == 1){
                    std::cout<<"Jugador eliminado con exito"<<std::endl;
                }
                else if (r.deleteJugador(dni) == -1){
                    std::cout<<"La lista esta vacia"<<std::endl;  
                }
                else if(r.deleteJugador(dni) == -2){
                    std::cout<<"Jugador no encontrado"<<std::endl;
                }

			break;

			case 6:

				std::cout<<"Añadiendo jugadores"<<std::endl;
                r.addJugador(j1);
                r.addJugador(j2);
                r.addJugador(j3);
                std::cout<<"Jugadores añadidos exitosamente"<<std::endl;

			break;

			case 7:

				std::cout<<"Saliendo del programa."<<std::endl;

			break;

			default:

			std::cout<<"Error, Introduzca un valor corrrecto:"<<std::endl;

			break;
		}
	}

	return 0;
}