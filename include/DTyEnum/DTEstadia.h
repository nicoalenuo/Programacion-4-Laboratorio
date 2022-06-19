#ifndef DTESTADIA
#define DTESTADIA

#include "Date.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTEstadia {
    private:
        Date fechaEntrada;
        Date* fechaSalida;
        int codigo;
    public:
        DTEstadia(Date,Date*,int);
        ~DTEstadia();
        
        Date getFechaEntrada();
        Date* getFechaSalida();
        int getCodigo();
        void setFechaEntrada(Date);
        void setFechaSalida(Date*);
        void setCodigo(int);
};

#endif