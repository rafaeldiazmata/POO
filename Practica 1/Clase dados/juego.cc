/*Archivo dados.h*/
//Realizado por Rafael Carlos Díaz Mata

/*Programa principal que prueba el funcionamiento de la clase dados*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dados.h"
#define NULL__null

inf main()
{
	Dados d;
	int opt=0;

	std::cout<<"Menu para utilizar los Dados"<<std::endl;


while (opt!=10){


		std::cout<<"-------------------------------------------------------"<<std::endl;
		std::cout<<"1. Mostar el valor de los dados"<<std::endl;
		std::cout<<"2. Lanzar los dados"<<std::endl;
		std::cout<<"3. Media de los dados"<<std::endl;
		std::cout<<"4. Modificar el valor del dado 1"<<std::endl;
		std::cout<<"5. Modificar el valor del dado 2"<<std::endl;
		std::cout<<"6. Mostar la suma de los dados"<<std::endl;
		std::cout<<"7. Mostrar la diferencia de los dados"<<std::endl;
		std::cout<<"8. Mostra cuantos lanzamientos se realizaron"<<std::endl;
		std::cout<<"9. Mostrar los ultimos 5 valores de los 2 dados"<<std::endl;
		std::cout<<"10. Salir"<<std::endl;
		std::cout<<"-------------------------------------------------------"<<std::endl;

		//Introducir el valor para seleccionar que realizar
		std::cin>>opt;

		switch(opt){

			case 1:
				std::cout<<"El valor del primer dado es "<<d.getDado1()<<"\n";                  
	            std::cout<<"El valor del segundo dado es "<<d.getDado2()<<"\n";
	        break;

	        case 2:
		        d.lanzamiento();
		        std::cout<<"Lanzamiento de dados completado con éxito"<<"\n";
	        break;

	        case 3:
	        	std::cout<<"La media del dado 1 es "<<d.getMedia1()<<"\n";
                std::cout<<"La media del dado 2 es "<<d.getMedia2()<<"\n";
            break;

            case 4:
            	int a;
            	std::cout<<"Introduzca el nuevo valor del primer dado: ";
            	std::cin>>a;
            	if (d.setDado1(a)==true){
                    std::cout<<"Dado guardado correctamente \n";
                }
                else {
                    std::cout<<"ERROR. No se ha podido guardar el dado \n";
                }
            break;

            case 5:
            	int b;
            	std::cout<<"Introduzca el nuevo valor del segundo dado: ";
            	std::cin>>b;
            	if (d.setDado1(b)==true){
                    std::cout<<"Dado guardado correctamente \n";
                }
                else {
                    std::cout<<"ERROR. No se ha podido guardar el dado \n";
            break;

            case 6:
            	std::cout<<"El valor de la suma es "<<d.getSuma()<<"\n";
            break;
            
            case 7:
            	std::cout<<"El valor de la diferencia es "<<d.getDiferencia()<<"\n";
            break;

            case 8:
            	std::cout<<"El dado 1 se ha lanzado "<<d.getLanzamientos1()<<" veces \n";       
                std::cout<<"El dado 2 se ha lanzado "<<d.getLanzamientos2()<<" veces \n";
            break;

            case 9:
            	int v1[5];                                                                      //Creamos un vector donde copiaremos los ultimos 5 valores del dado 1  
                int v2[5];                                                                      //Creamos un vector donde copiaremos los ultimos 5 valores del dado 2

                d.getUltimos1(v1);                                                              //Llamamos a la funcion getUltimos1 y le pasamos v1 para que guarde ahi los ultimos 5 valores del dado 1
                d.getUltimos2(v2);                                                              //Llamamos a la funcion getUltimos2 y le pasamos v2 para que guarde ahi los ultimos 5 valores del dado 2

                std::cout<<"Los ultimos 5 valores obtenidos para el dado 1 son: "<<std::endl;   
                std::cout<<"|";
                for (int i=0; i<5; i++){                                                        //Imprimimos los ultimos 5 valores del dado 1
                    std::cout<<v1[i]<<"|";
                }
                std::cout<<std::endl;
                std::cout<<std::endl;

                std::cout<<"Los ultimos 5 valores obtenidos para el dado 2 son: "<<std::endl;   
                std::cout<<"|";
                for (int i=0; i<5; i++){                                                        //Imprimimos los ultimos 5 valores del dado 2
                    std::cout<<v2[i]<<"|";
                }
                std::cout<<std::endl;

            break;

            case 10:
            	std::cout<<"Cerrando el programa \n";
            break;

            default:
            	std::cout<<"Error, Introduzca una opcion valida"<<std::endl;
            break;
		}
	}
}