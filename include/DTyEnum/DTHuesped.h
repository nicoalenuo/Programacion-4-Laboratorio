#ifndef DTHUESPED
#define DTHUESPED

#include "DTUsuario.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTHuesped:public DTUsuario{
    private:
        bool esFinger;
    public:
        DTHuesped(string,string,string,bool);
        ~DTHuesped();
        
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
        bool getEsFinger() {
            return (*this).esFinger;
        }

        void setEsFinger(bool esFinger) {
            (*this).esFinger = esFinger;
        }

};

#endif