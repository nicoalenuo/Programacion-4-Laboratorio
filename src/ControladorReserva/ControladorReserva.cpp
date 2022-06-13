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
int ControladorReserva::obtenerNumeroDeHabitacion(DTHabitacion*){return 4;}
map<string,string> ControladorReserva::obtenerNombresDeReserva(DTReservaGrupal*){
    map<string,string> a;
    return a;
}
map<int,DTEstadia*> ControladorReserva::obtenerEstadiaHuesped(string email){
    map<int,DTEstadia*> send;
    for(map<int,reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it){
        if(it->second->tieneEstadiaFinalizadaDeHuesped(email)){
            DTEstadia* aux = it->second->darEstadiaDeHuesped(email);
            send.insert(pair<int,DTEstadia*>(aux->getCodigo(),aux));
        }
    }
    return send;
}
map<string,string> ControladorReserva::mostrarReserva(DTReserva*){
    map<string,string> a;
    return a;
    }
        