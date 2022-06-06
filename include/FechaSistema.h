#ifndef FECHASISTEMA
#define FECHASISTEMA

#include "DTyEnum/Date.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class FechaSistema{
    private:
        Date FechaActual;

        static FechaSistema* instancia;
        FechaSistema();
    public:
        static FechaSistema* getInstance();
        Date getFechaActual();
        void setFechaActual(Date);
        ~FechaSistema();
};

#endif