//Ej3.cc
//Realizado por Rafael Carlos Díaz Mata

/*Programa con el cual un usuario intentara adivinar el nº aleatorio que se genero*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){

	srand(time(NULL));
	int n = 1 + rand() % (11-1);
	int a;

	std::cout<<"Bienvenido, introduzca un numero para intentar adivinar: ";
	std::cin>>a;
	std::cout<<"\n";

	while(a!=n){
		if(a>n){
			std::cout<<"Error, el numero introducido es menor. Pruebe de nuevo: ";
			std::cin>>a;
			std::cout<<"\n";
		}

		if(a<n){
			std::cout<<"Error, el numero introducido es mayor. Pruebe de nuevo: ";
			std::cin>>a;
			std::cout<<"\n";	
		}
	}

	std::cout<<"Felicidades usted ha acertado el numero"<<"\n";
	std::cout<<"El numero era: "<<a<<"\n";
}
