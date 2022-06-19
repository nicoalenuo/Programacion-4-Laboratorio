#ifndef DTEMPLEADO
#define DTEMPLEADO

#include "DTUsuario.h"
#include "../DTyEnum/Cargo.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTEmpleado:public DTUsuario {
    private:
        Cargo TipoCargo;
    public:
        DTEmpleado(string,string,string,Cargo);
        ~DTEmpleado();
        
        string getNombre();
        void setNombre(string);
        string getEmail();
        void setEmail(string);
        string getPassword();
        void setPassword(string);
        Cargo getTipoCargo();
        void setTipoCargo(Cargo);
};

#endif