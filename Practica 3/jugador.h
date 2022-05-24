//jugador.cc
//Realizado por Rafael Carlos Díaz Mata
//Contiene la clase Jugador

#ifndef JUGADOR_H
#define JUGADOR_H
#include "persona.h"
#include <list>
#include <fstream>
#include <iostream>

struct Apuesta
{
	int tipo;
	std::string valor;
	int cantidad;
};

class Jugador: public Persona{

	private:

		int dinero_;
		std::string codigo_;
		std::list<Apuesta> apuestas_;


	public:

		inline Jugador(std::string dni, std::string codigo, std::string nombre="", std::string apellidos="", int edad=0, std::string direccion="", std::string localidad ="", std::string provincia="", std::string pais= "", int dinero= 1000):Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){
			codigo_ = codigo;
			dinero_ = dinero;
		};


		inline void setDinero(int const &dinero){dinero_=dinero;}
		inline void SetCodigo(std::string const &codigo){codigo_ = codigo;}
		void setApuestas();

		inline int getDinero() const {return dinero_;}
		inline std::string getCodigo() const {return codigo_;}
		inline std::list<Apuesta> getApuestas() const {return apuestas_;}
};

#endif