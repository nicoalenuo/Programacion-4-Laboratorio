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
        int IDActualReserva =0;

        //Cosas "Recordadas por el sistema"
        DTReserva* datosReserva;
        DTReservaIndividual* datosIndividual;
        DTReservaGrupal* datosGrupal;
        Date CheckIn;
        Date CheckOut;
        DTHuesped * Propietario;
        map<string,DTHuesped*> SDTH;

        static ControladorReserva* instancia;
        ControladorReserva();
    public:
        static ControladorReserva* getInstance();
        ~ControladorReserva();
        
        void ingresarDatosReserva(DTHostal*, Date, Date);
        map<int,DTHabitacion*> obtenerHabitacionesDisponibles();
        void IngresarHuespedEnReserva(DTHuesped*);
        void confirmarReserva();  
        reserva* getReserva(DTReserva*);
        void DesignarPropietarioDeReserva(DTHuesped*);
        map<int,DTReserva*> ListarReservasNoCanceladasDeHuesped(DTHostal*, string);
        void confirmarBaja(DTHostal*, int);
        void finalizarEstadiaActiva(string, string);
        map<string,DTHuesped*> obtenerHuespedesDeReserva(DTReservaGrupal*); 
        map<int,DTEstadia*> obtenerEstadiaHuesped(string);
        DTDatosEstadia* obtenerDatosEstadia();
        reserva* obtenerReservaDeEstadia(DTEstadia*);
        DTReserva* obtenerDTReservaDeEstadia(DTEstadia*);
        DTHabitacion* obtenerHabitacionDeReserva(DTReserva*);
        void agregarReservaAMap(reserva * r){
            reservas.insert(pair<int,reserva*>((*r).getCodigo(),r));
        }
        void liberarMemoria();
};

#endif