#ifndef HUESPEDINDIVIDUAL
#define HUESPEDINDIVIDUAL

#include "../usuario/huesped.h"
#include "../estadia.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class huespedIndividual{
    private:
        huesped* huesped;

        estadia* estadia;
    public:
        ~huespedIndividual();                                                                                                                                                                        
};

#endif