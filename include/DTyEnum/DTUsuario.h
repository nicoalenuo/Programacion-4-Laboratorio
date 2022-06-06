#ifndef DTUSUARIO
#define DTUSUARIO

#include "Cargo.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTUsuario{
    protected:
    string nombre;
    string mail;
    string password;

    public:
        ~DTUsuario();
        string getNombre() {
            return (*this).nombre;
        }
        void setNombre(string nombre) {
            (*this).nombre = nombre;
        }

        string getMail() {
            return (*this).mail;
        }

        void setMail(string mail) {
            (*this).mail = mail;
        }

        string getPassword() {
            return (*this).password;
        }

        void setPassword(string password) {
            (*this).password = password;
        }
};

#endif