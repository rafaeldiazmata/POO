/*Archivo dados.h*/
//Realizado por Rafael Carlos Díaz Mata

/*La clase dados representa el lanzamiento de 2 dados*/

#ifndef DADOS_H
#define DADOS_H
#include <cstdlib>
#include <ctime>
#include <iostream>

class Dados{


private:
	int d1_;
	int d2_;
	int lanz1_;
	int lanz2_;
	int sum1_;
	int sum2_;
	int ultimos1 [5] = {0,0,0,0,0};
	int ultimos2 [5] = {0,0,0,0,0};


public:

	Dados();

	inline int getDado1() const{return d1_;}
	inline int getDado2() const{return d2_;}

	inline int getDiferencia() const { return (abs(d1_ - d2_)); }
	inline int getSuma() const { return d1_ + d2_; }

	inline int getLanzamientos1() const { return lanz1_; }
	inline int getLanzamientos2() const { return lanz2_; }

	void lanzamiento();

	bool setDado1(const int &n);
	bool setDado2(const int &n);

	float getMedia1() const;
	float getMedia2() const;

	void getUltimos1(int v[]);
	void getUltimos2(int v[]);

};

#endif

