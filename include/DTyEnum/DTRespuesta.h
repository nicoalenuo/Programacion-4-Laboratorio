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
        
        string getNombre() {
            return (*this).nombre;
        }

        void setNombre(string nombre) {
            (*this).nombre = nombre;
        }

        string getEmail() {
            return (*this).email;
        }

        void setEmail(string email) {
            (*this).email = email;
        }

        string getPassword() {
            return (*this).password;
        }

        void setPassword(string password) {
            (*this).password = password;
        }

};

#endif