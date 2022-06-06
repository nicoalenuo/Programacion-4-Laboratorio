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
        float getCalificacionPromedio();
        ~DTHostal();
        
    string getNombre() {
        return (*this).nombre;
    }
	void setNombre(string nombre) {
		(*this).nombre = nombre;
	}

	string getDireccion() {
		return (*this).direccion;
	}

	void setDireccion(string direccion) {
		(*this).direccion = direccion;
	}

	string getTelefono() {
		return (*this).telefono;
	}

	void setTelefono(string telefono) {
		(*this).telefono = telefono;
	}

	float getCalificacionPromedio() {
		return (*this).calificacionPromedio;
	}

	void setCalificacionPromedio(float calificacionPromedio) {
		(*this).calificacionPromedio = calificacionPromedio;
	}
    
};

#endif