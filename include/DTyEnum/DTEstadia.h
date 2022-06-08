#ifndef DTESTADIA
#define DTESTADIA

#include "Date.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTEstadia {
    private:
        Date fechaEntrada;
        Date fechaSalida;
        int codigo;
    public:
        DTEstadia(Date,Date,int);
        ~DTEstadia();
        
        Date getFechaEntrada(){
            return fechaEntrada;
        }
        Date getFechaSalida(){
            return fechaSalida;
        }
        int getCodigo(){
            return codigo;
        }
        void setFechaEntrada(Date fe){
            fechaEntrada=fe;
        }
        void setFechaSalida(Date fs){
            fechaSalida=fs;
        }
        void setCodigo(int c){
            codigo=c;
        }
};

#endif