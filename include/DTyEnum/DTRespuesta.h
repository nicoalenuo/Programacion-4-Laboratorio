#ifndef DTRESPUESTA
#define DTRESPUESTA

#include <iostream>
#include <stdio.h>
using namespace std;

class DTRespuesta {
    private:
        string nombre;
        string email;
        string password;
    public:
     ~DTRespuesta();

};
    public getNombre(): undefined {
        return this.nombre;
    }

    public setNombre(nombre: undefined): void {
        this.nombre = nombre;
    }

    public getEmail(): undefined {
        return this.email;
    }

    public setEmail(email: undefined): void {
        this.email = email;
    }

    public getPassword(): undefined {
        return this.password;
    }

    public setPassword(password: undefined): void {
        this.password = password;
    }

#endif