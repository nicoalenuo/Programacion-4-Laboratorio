#ifndef HOSTAL
#define HOSTAL

#include "calificacion.h"
#include "DTyEnum/DTHostal.h"
#include "DTyEnum/DTEmpleado.h"
#include "usuario/empleado.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>

class hostal{
    private:
        map<int,calificacion*> calificaciones;
        map<string,empleado*> empleados;

        string nombre;
        string direccion;
        string telefono;
    public:
        string getNombre();
        string getDireccion();
        string getTelefono();
        void setNombre(string);
        void setDireccion(string);
        void setTelefono(string);

        DTHostal darDatos();
        
        map<string,DTEmpleado*> quitarAsignados(map<string,DTEmpleado*>);
};

#endif