#ifndef HUESPED
#define HUESPED

#include "usuario.h"

class huesped:public usuario {
    private:
        bool esFinger;
    public:
        ~huesped();
        huesped(string,string,string,bool);

        string getNombre();
        string getEmail();
        string getPassword();
        bool getEsFinger();
        void setNombre(string);
        void setEmail(string);
        void setPassword(string);
        void setEsFinger(bool);

        DTHuesped* darDatos();
        map<int,DTEstadia*> obtenerEstadias();
};

#endif