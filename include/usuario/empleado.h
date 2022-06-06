#ifndef EMPLEADO
#define EMPLEADO

#include "usuario.h"
#include "../DTyEnum/Cargo.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <set>

class empleado:public usuario, public IObserver {
    private:
        Cargo TipoCargo;
        set<notificacion*> notificaciones;
        
    public:
        string getNombre(){
            return nombre;
        }
        string getEmail(){
            return email;
        }
        string getPassword(){
            return password;
        }
        Cargo getTipoCargo(){
            return TipoCargo;
        }
        void setNombre(string n){
            nombre=n;
        }
        void setEmail(string e){
            email=e;
        }
        void setPassword(string p){
            password=p;
        }
        void setTipoCargo(Cargo c){
            TipoCargo=c;
        }
        ~empleado();

        DTEmpleado* darDatos();
        bool estaAsignado();
        void suscribirse();
        void notificar(string,int,string);
};

#endif