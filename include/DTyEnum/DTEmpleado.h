#ifndef DTEMPLEADO
#define DTEMPLEADO

#include "DTUsuario.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTEmpleado:public DTUsuario {
    private:
        Cargo TipoCargo;
    public:
        DTEmpleado(string,string,string,Cargo);
        DTEmpleado();
};

#endif