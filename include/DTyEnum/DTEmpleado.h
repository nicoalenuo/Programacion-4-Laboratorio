#ifndef DTEMPLEADO
#define DTEMPLEADO

#include "DTUsuario.h"
#include "../DTyEnum/Cargo.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTEmpleado:public DTUsuario {
    private:
        Cargo TipoCargo;
    public:
        DTEmpleado(string,string,string,Cargo);
        ~DTEmpleado();
        string getNombre() {
            return (*this).nombre;
        }
        void setNombre(string nombre) {
            (*this).nombre = nombre;
        }

        string getMail() {
            return (*this).email;
        }

        void setMail(string email) {
            (*this).email = email;
        }

        string getPassword() {
            return (*this).password;
        }

        void setPassword(string password) {
            (*this).password = password;
        }
        int getTipoCargo(){
            return (*this).TipoCargo;
        }
        void setTipoCargo(Cargo c){
            (*this).TipoCargo=c;
        }
};

#endif