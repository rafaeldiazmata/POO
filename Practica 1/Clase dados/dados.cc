/*Archivo dados.cc*/
//Realizado por Rafael Carlos Díaz Mata

/*Este archivo contiene el cuerpo de las funciones de la clase dados*/

#include "dados.h"

Dados::Dados(){					//Constructor clase Dados

	srand(time(NULL));		
	d1_=1;
	d2_=1;

	lanz1_=0;
	lanz2_=0;

	sum1_=0;
	sum2_=0;			
}

void Dados::lanzamientos(){			//Funcion para realizar el lanzamiento aleatorio de los dados

	d1_=(srand()%6)+1;
	d2_=(srand()%6)+1;

	lanz1_++;
	lanz2_++;

	sum1_ += d1_;
	sum2_ += d2_;

	for (int i = 4; i >=0; i--)			//Con esto almacena los resultados obtenidos en un vector
	{
		ultimos1 [i] = ultimos1 [i-1];
	}

	ultimos1 [0] = d1_;

	for (int i = 4; i >=0; i--)
	{
		ultimos2 [i] = ultimos2 [i-2];
	}

	ultimos2 [0] = d2_;		
}


bool Dados::setDado1(const int &n){			//Funcion que proporciona un valor al dado 1

	if (n>=1 && n<=6){
		d1_=n;
		lanz1_++;
		sum1_+=d1_;

		for (int i = 4; i >=0; i--){
			
			ultimos1 [i] = ultimos1 [i-1];
		}
		ultimos1 [0] = d1_;
		return true;
	}
	return false;		
}



bool Dados::setDado2(const int &n){			//Funcion que proporciona un valor al dado 2

	if (n>=1 && n<=6){
		d2_=n;
		lanz2_++;
		sum2_+=d2_;

		for (int i = 4; i >=0; i--){
			
			ultimos2 [i] = ultimos2 [i-1];
		}
		ultimos2 [0] = d2_;
		return true;
	}
	return false;		
}


float Dados::getMedia1()const{				//Funcion que calcula la media de los valores obtenidos en el dado 1

	if(lanz1_ == 0){
		return 0:
	}
	return (float)sum1_/lanz1_;

}


float Dados::getMedia2()const{				//Funcion que calcula la media de los valores obtenidos en el dado 2

	if(lanz2_ == 0){
		return 0:
	}
	return (float)sum2_/lanz2_;

}

void Dados::getUltimos1(int v[5]){			//Funcion en la que se copia en un vector los ultimos 5 valores del dado 1
    for (int i=0; i<5; i++){
	for (int i = 0; i<5; ++i){
		v[i]=ultimos1[i];
	}
}


void Dados::getUltimos2(int v[5]){			//Funcion en la que se copia en un vector los ultimos 5 valores del dado 2
	for (int i = 0; i<5; ++i){
		v[i]=ultimos2[i];
	}
}
