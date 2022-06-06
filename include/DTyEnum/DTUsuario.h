#ifndef DTUSUARIO
#define DTUSUARIO

#include "Cargo.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTUsuario{
    protected:
    string Nombre;
    string Mail;
    string Password;

    public:
        ~DTUsuario();
        string getNombre() {
            return (*this).Nombre;
        }

        void setNombre(string Nombre) {
            (*this).Nombre = Nombre;
        }

        string getMail() {
            return (*this).Mail;
        }

        void setMail(string Mail) {
            (*this).Mail = Mail;
        }

        string getPassword() {
            return (*this).Password;
        }

        void setPassword(string Password) {
            (*this).Password = Password;
        }
};

#endif