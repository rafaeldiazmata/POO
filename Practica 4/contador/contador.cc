//Archivo contador.cc
//Realizado por Rafael Carlos Díaz Mata
//Contiene el cuerpo de las funciones de la clase Contador

#include "contador.h"

Contador::Contador(int valor, int min, int max){
if(min>max || valor < min || valor > max){      
        valor = 0;
        min = 0;
        max = 1000;
    }
    valor_ = valor;                                 
    min_ = min;                                     
    max_ = max;                                     
    lista_.push_back(*this);                        
}

void Contador::controlValor(){
    if (valor_>max_){                               
        valor_=max_;
    }
    else if(valor_<min_){                          
        valor_=min_;
    }
    lista_.push_back(*this);                       
}

Contador Contador::operator= (const int &n){
    valor_=n;                                      
    controlValor();
    return *this;
}

Contador Contador::operator=(const Contador &c){
    valor_=c.valor_;                               
    min_=c.min_;                                   
    max_=c.max_;                                   
    controlValor();
    return *this;
}

Contador Contador::operator++(void){
    ++valor_;                                      
    controlValor();
    return *this;
}

Contador Contador::operator++(int){
    Contador aux = *this;
    ++valor_;                                      
    controlValor();
    return aux;                                    
}

Contador Contador::operator--(void){
    --valor_;                                      
    controlValor();
    return *this;
}

Contador Contador::operator--(int){
    Contador aux = *this;
    --valor_;                                      
    controlValor();
    return aux;                                    
}

Contador Contador::operator+(const int &n){
    valor_ = valor_ + n;                           
    controlValor();
    return *this;
}

Contador operator+(const int &n, const Contador &c){
    Contador aux;
    aux.valor_ = n + c.valor_;                     
    aux.max_ = c.max_;                             
    aux.min_ = c.min_;                             
    aux.controlValor();
    return aux;
}

Contador Contador::operator-(const int &n){
    valor_ = valor_ - n;                           
    controlValor();
    return *this;
}

Contador operator-(const int &n, const Contador &c){
    Contador aux;
    aux.valor_ = n - c.valor_;                     
    aux.max_ = c.max_;                             
    aux.min_ = c.min_;                             
    aux.controlValor();
    return aux;
}

bool Contador::undo(const int &n){
    if (n>= (int)lista_.size() || n<1){            
        return false;
    }
    for(int i=0; i<n; i++){                        
        lista_.pop_back();
    }
    *this = lista_.back();                         
    return true;
}