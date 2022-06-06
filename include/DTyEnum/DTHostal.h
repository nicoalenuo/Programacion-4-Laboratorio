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
        ~DTHostal();
};
public getNombre(): string {
    return this.nombre;
}

public setNombre(nombre: string): void {
    this.nombre = nombre;
}

public getDireccion(): string {
    return this.direccion;
}

public setDireccion(direccion: string): void {
    this.direccion = direccion;
}

public getTelefono(): string {
    return this.telefono;
}

public setTelefono(telefono: string): void {
    this.telefono = telefono;
}

public getCalificacionPromedio(): float {
    return this.calificacionPromedio;
}

public setCalificacionPromedio(calificacionPromedio: float): void {
    this.calificacionPromedio = calificacionPromedio;
}
#endif