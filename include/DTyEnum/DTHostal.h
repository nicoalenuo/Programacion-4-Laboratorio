#ifndef DTHOSTAL
#define DTHOSTAL

#include <iostream>
#include <stdio.h>
using namespace std;

class DTHostal{
    private:
        string nombre;
        string direccion;
        string telefono;
        float calificacionPromedio;
    public:
        DTHostal(string,string,string,float);

        string getNombre();
        string getDireccion();
        string getTelefono();
        float getCalificacionPromedio();
};

#endif