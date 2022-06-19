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

        int getCodigo();
        Date getCheckIn();
        Date getCheckOut();
        EstadoReserva getEstado();
        float getCosto();
        int getCantHuespedes();
        void setCodigo(int);
        void setHabitacion(habitacion*);
        void setCheckIn(Date);
        void setCheckOut(Date);
        void setEstado(EstadoReserva);
        void setCosto(float);
        void setCantHuespedes(int);
        habitacion* getHabitacion();
        DTReservaGrupal* darDatos();
        void finalizarSiEsReservaBuscada(string, string);
        bool perteneceHusped(string);
        void darBajaReserva();
        map<int, DTEstadia*> obtenerEstadias();
        map<string,DTHuesped*> obtenerHuespedesDeReserva();
        DTEstadia* obtenerEstadia();
        DTReserva* obtenerResrvaDeEst();
        bool tieneEstadiaFinalizadaDeHuespedEnHostal(string);
        huespedGrupal* GetHuespedGrupalDeUsuario(string);
        DTEstadia* darEstadiaDeHuesped(string);
        void agregarHuespedGrupalASet(huespedGrupal*);
        DTHostal* getDTHostal();
        DTReserva* getDTReserva();
        bool tieneEstadia(DTEstadia*);
        DTHuesped* darHuespedConEstadia(DTEstadia*);
        DTHabitacion* darDatosHabitacion();
};

#endif