//Archivo contador.h
//Realizado por Rafael Carlos Díaz Mata
//Contiene la clase Contador

#ifndef CONTADOR_H
#define CONTADOR_H
#include <list>

class Contador{

private:
	int valor_;
	int min_;
	int max_;
	std::list<Contador> lista_;

	void controlValor();



public:

	contador(int valor = 0, int min = 0, int max = 1000);

	Contador operator=(const int &n);
	Contador operator=(const Contador %c);

	Contador operator++(void);
	Contador operator++(int);

	Contador operator--(void);
	Contador operator--(int);

	Contador operator+(const int &n);
	friend Contador operator+(const int &n, const Contador &c);

	Contador operator-(const int &n);
	friend Contador operator-(const int &n, const Contador &c);

	bool undo(const int &n=1);

	inline int get() const {return valor_;}
};

#endif