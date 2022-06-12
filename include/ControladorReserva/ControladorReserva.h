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
        ~ControladorReserva(); //AGREGADO


        //AQUI DECIA OTRA VEZ FINALIZAR ESTADIA ACTIVA
        void ingresarDatosReserva(DTHostal*, Date, Date);
        map<int,DTHabitacion*> obtenerHabitacionesDisponibles();
        void EscogerHabitacion(DTHabitacion*);
        DTHuesped* DesignarPropietarioDeReserva(DTHuesped*);
        void IngresarHuespedEnReserva(DTHuesped*);
        void CancelarReserva();
        void confirmarReserva();  
        map<int,DTReserva*> ListarReservasNoCanceladasDeHuesped(DTHostal*, string);
        void confirmarBaja(DTHostal*, int);
        void finalizarEstadiaActiva(string, string);
        void mostrarReserva(DTReserva*);
        int obtenerNumeroDeHabitacion(DTHabitacion*);
        void obtenerNombresDeReserva(DTReservaGrupal*); //////////////////////////////////////////////
        map<int,DTEstadia*> obtenerEstadiaHuesped(string);
        void agregarReservaAMap(reserva * r){
            reservas.insert(pair<int,reserva*>((*r).getCodigo(),r));
        }
};

#endif