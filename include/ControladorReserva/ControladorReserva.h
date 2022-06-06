#ifndef CONTROLADORRESERVA
#define CONTROLADORRESERVA

#include "IControladorReserva.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>


class ControladorReserva:public IControladorReserva {
    private:
        map<int,reserva*> reservas;

        DTReserva* datosReserva;
        DTReservaIndividual* datosIndividual;
        DTReservaGrupal* datosGrupal;

        static ControladorReserva* instancia;
        ControladorReserva();
    public:
        static ControladorReserva* getInstance();

        void finalizarEstadiaActiva(string,string);
        void ingresarDatosReserva(DTHostal*, Date, Date);
        map<int,DTHabitacion*> obtenerHabitacionesDisponibles();
        void EscogerHabitacion(DTHabitacion*);
        DTHuesped* DesignarPropietarioDeReserva(DTHuesped*);
        void IngresarHuespedEnReserva(DTHuesped*);
        void CancelarReserva();
        DTIdentificador* confirmarReserva(); ////////////////////////////////////ARREGLAR AAAAAAAAAAAAAAAAAAAAAAAAAAAAA 
        map<int,DTReserva*> ListarReservasNoCanceladasDeHuesped(DTHostal*, string);
        void confirmarBaja(DTHostal*, int);
        void finalizarEstadiaActiva(string, string);
        map<string,string> mostrarReserva(DTReserva*); ////////////////////////////////////////
        int obtenerNumeroDeHabitacion(DTHabitacion*);
        map<string,string> obtenerNombresDeReserva(DTReservaGrupal*); //////////////////////////////////////////////
        map<int,DTEstadia*> obtenerEstadiaHuesped(string);
};

#endif