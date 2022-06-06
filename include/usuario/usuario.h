#ifndef USUARIO
#define USUARIO

#include "../DTyEnum/DTEstadia.h"
#include "../DTyEnum/DTEmpleado.h"
#include "../DTyEnum/DTHuesped.h"
#include "IObserver.h"
#include "../DTyEnum/Cargo.h"
#include "../notificacion.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class usuario{
    protected:
        string nombre;
        string email;
        string password;
    public:
        virtual string getNombre(){
            return nombre;
        };
        virtual string getEmail(){
            return email;
        };
        virtual string getPassword(){
            return password;
        };
        virtual void setNombre(string nomb){
            nombre=nomb;
        };
        virtual void setEmail(string ema){
            email=ema;
        };
        virtual void setPassword(string pass){
            password= pass;
        };
        virtual ~usuario()=0;
        DTUsuario* devolverDatos();
};

#endif