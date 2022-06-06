#ifndef DTHUESPED
#define DTHUESPED

#include "DTUsuario.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTHuesped:public DTUsuario{
    private:
        bool esFinger;
    public:
        DTHuesped(string,string,string,bool);
        DTHuesped();
};

#endif