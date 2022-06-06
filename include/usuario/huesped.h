#ifndef HUESPED
#define HUESPED

#include "usuario.h"

class huesped:public usuario {
    private:
        bool esFinger;
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
        bool getEsFinger(){
            return esFinger;
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
        void setEsFinger(bool ef){
            esFinger=ef;
        }
        ~huesped();

        DTHuesped* darDatos();
        multiset<int,DTEstadia*> obtenerEstadias();
};

#endif