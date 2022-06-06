#ifndef ESTADIA
#define ESTADIA

#include "DTyEnum/Date.h"
#include "calificacion.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class estadia{
    private:
        calificacion* calificacion;

        Date fechaEntrada;
        Date fechaSalida;
        int codigo;
        float totalConsumido;
    public:
        Date getFechaEntrada();
        Date getFechaSalida();
        int getCodigo();
        float getTotalConsumido();
        void setFechaEntrada(Date);
        void setFechaSalida(Date);
        void setCodigo(int);
        void setTotalConsumido(float);
};

#endif