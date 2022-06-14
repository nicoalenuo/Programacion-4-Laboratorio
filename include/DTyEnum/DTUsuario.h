#ifndef DTUSUARIO
#define DTUSUARIO

#include "Cargo.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTUsuario{
    protected:
        string nombre;
        string email;
        string password;
    public:
        virtual ~DTUsuario()=0;
        virtual string getNombre()=0;
        virtual void setNombre(string nombre)=0;
        virtual string getEmail()=0;
        virtual void setEmail(string email)=0;
        virtual string getPassword()=0;
        virtual void setPassword(string password)=0;
};

#endif