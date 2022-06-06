#ifndef DTEMPLEADO
#define DTEMPLEADO

#include "DTUsuario.h"
#include "Cargo.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTEmpleado:public DTUsuario {
    private:
        Cargo TipoCargo;
    public:
        DTEmpleado(string,string,string,Cargo);
        DTEmpleado();
       ~DTEmpleado();
        int TipoCargo(){
            return (*this).TipoCargo;
        }
        void setTipoCargo(Cargo c){
            (*this).TipoCargo=c;
        }
};


#endif