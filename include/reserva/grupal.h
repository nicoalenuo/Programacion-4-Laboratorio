#ifndef RESERVAGRUPAL
#define RESERVAGRUPAL

#include "reserva.h"
#include "Huesped-Grupal.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <set>

class grupal:public reserva{
    private:
        set<huespedGrupal*> huesGrup;

        int cantHuespedes;
    public:
        ~grupal();
         grupal(DTReservaGrupal*, habitacion*,map<string,DTHuesped*>,DTHuesped*);

        int getCodigo(){
            return codigo;
        }
        Date getCheckIn(){
            return checkIn;
        }
        Date getCheckOut(){
            return checkOut;
        }
        EstadoReserva getEstado(){
            return estado;
        }
        float getCosto(){
            return costo;
        }
        int getCantHuespedes(){
            return cantHuespedes;
        }
        void setCodigo(int c){
            codigo=c;
        }
        void setHabitacion(habitacion* h){
            habitacionAsoc=h;
        }
        void setCheckIn(Date d){
            checkIn=d;
        }
        void setCheckOut(Date d){
            checkOut=d;
        }
        void setEstado(EstadoReserva er){
            estado=er;
        }
        void setCosto(float c){
            costo=c;
        }
        void setCantHuespedes(int ch){
            cantHuespedes=ch;
        }
        habitacion* getHabitacion(){
            return habitacionAsoc;
        }

        DTReservaGrupal* darDatos();
        void finalizarSiEsReservaBuscada(string, string);
        bool perteneceHusped(string);
        void darBajaReserva();
        map<int, DTEstadia*> obtenerEstadias();
        map<string,DTHuesped*> obtenerHuespedesDeReserva();
        DTEstadia* obtenerEstadia();
        DTReserva* obtenerResrvaDeEst();
        bool tieneEstadiaFinalizadaDeHuesped(string);
        huespedGrupal* GetHuespedGrupalDeUsuario(string);
        DTEstadia* darEstadiaDeHuesped(string);
        void agregarHuespedGrupalASet(huespedGrupal * hg){
            huesGrup.insert(hg);
        }
        DTHostal* getDTHostal();
        DTReserva* getDTReserva();
        bool tieneEstadia(DTEstadia*);
        DTHuesped* darHuespedConEstadia(DTEstadia*);
        DTHabitacion* darDatosHabitacion();

        void imprimirHuespedes();
};

#endif