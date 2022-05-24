//Persona.cc
//Realizado por Rafael Carlos Díaz Mata
//Contiene el cuerpo de las funciones de la clase persona

#include "persona.h"

Persona::Persona(std::string dni, std::string nombre, std::string apellidos, int edad, std::string direccion, std::string localidad, std::string provincia, std::string pais){
	dni_= dni;
	nombre_ = nombre;
	apellidos_ = apellidos;
	edad_ = edad;
	direccion_ = direccion;
	localidad_ = localidad;
	provincia_ = provincia;
	pais_ = pais;
}

	bool Persona::setEdad(int const &edad){
		if(edad>=0){
			edad_ = edad;
			return true;
		}
		return false;
	}

	bool Persona::mayor() const{
		if(edad_<18){
			return false;
		}
		return true;
	}