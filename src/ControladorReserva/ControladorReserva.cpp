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
int ControladorReserva::obtenerNumeroDeHabitacion(DTHabitacion* dth){
    return dth->getNumero();
}
        map<string,string> ControladorReserva::obtenerNombresDeReserva(DTReservaGrupal*){
            map<string,string> a;
            return a;
        }
        map<int,DTEstadia*> ControladorReserva::obtenerEstadiaHuesped(string){
            map<int,DTEstadia*> a;
            return a;
        }

void ControladorReserva::mostrarReserva(DTReserva* dtr){
    //esto debería de estar en interfaz, pero lo pongo porque pinta
    cout << dtr->getCodigo() << endl;
    cout << dtr->getCheckIn().getDia() << endl;
    cout << dtr->getCheckIn().getMes() << endl;
    cout << dtr->getCheckIn().getAnio() << endl;
    cout << dtr->getCheckOut().getDia() << endl;
    cout << dtr->getCheckOut().getMes() << endl;
    cout << dtr->getCheckOut().getAnio() << endl;
    cout << dtr->getEstado() << endl;
    cout << dtr->getCosto() << endl;
}
        