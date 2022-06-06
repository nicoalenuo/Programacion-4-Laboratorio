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
#include <map>

class usuario{
    protected:
        string nombre;
        string email;
        string password;
    public:
        virtual ~usuario()=0;
        virtual string getNombre()=0;
        virtual string getEmail()=0;
        virtual string getPassword()=0;
        virtual void setNombre(string)=0;
        virtual void setEmail(string)=0;
        virtual void setPassword(string)=0;
};

#endif