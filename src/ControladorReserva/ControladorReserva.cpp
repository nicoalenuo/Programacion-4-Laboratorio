#include "../../include/ControladorReserva/ControladorReserva.h"
#include "../../include/fabrica.h"

ControladorReserva* ControladorReserva::instancia = NULL;

ControladorReserva::~ControladorReserva(){
}

ControladorReserva::ControladorReserva(){
    reservas={};

    datosReserva=NULL;
    datosIndividual=NULL;
    datosGrupal=NULL;
}

ControladorReserva* ControladorReserva::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorReserva();
    return instancia; 
}

void ControladorReserva::finalizarEstadiaActiva(string emailHuesped, string nombreHostal){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    map<int,reserva*>::iterator it;

    for (it=reservas.begin() ; it!=reservas.end() ; it++)
        (*(*it).second).finalizarSiEsReservaBuscada(emailHuesped,nombreHostal);

     (*ch).liberarDatosHostal();
}

        void ControladorReserva::ingresarDatosReserva(DTHostal*, Date, Date){}
        map<int,DTHabitacion*> ControladorReserva::obtenerHabitacionesDisponibles(){
            map<int,DTHabitacion*> a;
            return a;
        }
        void ControladorReserva::EscogerHabitacion(DTHabitacion*){}
        DTHuesped* ControladorReserva::DesignarPropietarioDeReserva(DTHuesped*){return NULL;}
        void ControladorReserva::IngresarHuespedEnReserva(DTHuesped*){}
        void ControladorReserva::CancelarReserva(){}
        void ControladorReserva::confirmarReserva(){}  
        map<int,DTReserva*> ControladorReserva::ListarReservasNoCanceladasDeHuesped(DTHostal*, string){
            map<int,DTReserva*> a;
            return a;
        }
        void ControladorReserva::confirmarBaja(DTHostal*, int){}

int ControladorReserva::obtenerNumeroDeHabitacion(DTHabitacion* dth){ //dth es asociado a una reserva
    return dth->getNumero();
}

void ControladorReserva::obtenerNombresDeReserva(DTReservaGrupal* dtrg){
    map<int,reserva*>::iterator it= reservas.find(dtrg->getCodigo());
    //como siempre es grupal
    grupal* gru= static_cast<grupal*>((*it).second);
    gru->obtenerNombresDeReserva();
}

        map<int,DTEstadia*> ControladorReserva::obtenerEstadiaHuesped(string){
            map<int,DTEstadia*> a;
            return a;
        }        