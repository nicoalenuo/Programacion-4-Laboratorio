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
        ~DTHostal();

        string getNombre();
        void setNombre(string);
        string getDireccion();
        void setDireccion(string);
        string getTelefono();
        void setTelefono(string);
        float getCalificacionPromedio();
        void setCalificacionPromedio(float);
    
};

#endif