//Ej2.cc
//Realizado por Rafael Carlos Díaz Mata

/*Programa con el cual aprendemos a usar los espacios de nombre --> namespace*/

#include <iostream>
using namespace std;

namespace ns1{

	int a;
	int b;

}

namespace ns2{

	int c;
	int b;
}

int main(){

	int b = 10;
	ns1::b = 20;
	ns2::b = 30;
	cout<<"b = "<<b<<"\n";
	cout<<"ns1::b = "<<ns1::b<<"\n";
	cout<<"ns2::b = "<<ns2::b<<"\n";


}