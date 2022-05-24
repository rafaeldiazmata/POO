//ruleta.h
//Realizado por Rafael Carlos Díaz Mata

//Contiene la clase Ruleta

#ifndef RULETA_H
#define RULETA_H
#include <list>
#include <iostream>
#include "jugador.h"
#include "crupier.h"

class Ruleta{


private:

		int banca_;
		int bola_;
		std::list<Jugador> jugadores_;
		Crupier crupier_;

public:

		inline Ruleta(Crupier crupier):crupier_(crupier.getDNI(), crupier.getCodigo()){
			bola_=-1;
			banca_=1000000
		}

		inline void giraRuleta(){
			stand(time(NULL));
			bola_=rand()%(37);
		}

		inline int getBanca() const {return banca_;}
		inline int getBola() const {return bola_;}
		inline Crupier getCrupier() const {return crupier_;}
		inline std::list<Jugador> getJugadores() const {return jugadores_;}


		bool setBanca(int const &banca);
		bool setBola(int const &bola);
		inline void setCrupier(Crupier const &crupier){crupier_=crupier;}

		bool addJugador(Jugador const &jugador);

		int deleteJugador(std::string const &dni);
		int deleteJugador(Jugador const &jugador);

		void escribeJugadores();
		void leeJugadores();

		void getPremios();

		bool esRoja(int const &valor);
		bool esPar(int const &valor);
		bool esAlta(int const &valor);
};
#endif