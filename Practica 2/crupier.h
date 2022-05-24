//crupier.h
//Realizado por Rafael Carlos Díaz Mata

//Este archivo contiene la clase crupier

#ifndef CRUPIER_H
#define CRUPIER_H
#include "persona.h"

class Crupier:public Persona{

	private:

			std::string codigo_;


	public:

			inline Crupier (std::string dni, std::string codigo, std::string nombre="", std::string apellido="", int edad=0, std::string direccion="", 
				std::string localidad="", std::string provincia="", std::string pais="" ):Persona(dni,nombre,apellidos,edad,direccion,localidad,provincia,pais){
				codigo_=codigo;
			};


			inline std::string getCodigo() const { return codigo_;}
			inline void setCodigo(std::string const &codigo) {codigo_=codigo;}
};

#endif