//jugador.cc
//Realizado por Rafael Carlos Díaz Mata
//Contiene la clase Persona 

#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona
{
private:
	
	std::string dni_;
	std::string nombre_;
	std::string apellidos_;
	int edad_;
	std::string direccion_;
	std::string localidad_;
	std::string provincia_;
	std::string pais_;


public:

	inline void setDNI(std::string const &dni){dni_=dni;}
	inline void setNombre(std::string const &nombre){nombre_=nombre;}
	inline void setApellidos(std::string const &apellidos){apellidos_ = apellidos;}
	bool setEdad(int const &edad);
	inline void setDireccion(std::string const &direccion){direccion_=direccion;}
	inline void setLocalidad(std::string const &localidad){localidad_=localidad;}
	inline void setProvincia(std::string const &provincia){provincia_=provincia;}
	inline void setPais(std::string const &pais){pais_=pais;}

	inline std::string getDNI() const {return dni_;}
	inline std::string getNombre() const {return nombre_;}
	inline std::string getApellidos() const {return apellidos_;}
	inline int getEdad() const {return edad_;}
	inline std::string getDireccion() const {return direccion_;}
	inline std::string getLocalidad() const {return localidad_;}
	inline std::string getProvincia() const {return provincia_;}
	inline std::string getPais() const {return pais_;}
	inline std::string getApellidosyNombre() const {return apellidos_ + "," + nombre_;}

	bool mayor() const;

	Persona(std::string dni, std::string nombre="", std::string apellidos="", int edad=0, std::string direccion="", std::string localidad ="", std::string provincia="", std::string pais= "");

};

#endif