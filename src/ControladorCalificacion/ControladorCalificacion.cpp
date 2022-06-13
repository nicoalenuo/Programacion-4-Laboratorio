#include "../../include/ControladorCalificacion/ControladorCalificacion.h"

ControladorCalificacion* ControladorCalificacion::instancia = NULL;

ControladorCalificacion::~ControladorCalificacion(){
}

ControladorCalificacion::ControladorCalificacion(){
    calificaciones={};
    estadias={};
}

ControladorCalificacion* ControladorCalificacion::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorCalificacion();
    return instancia;
}

void ControladorCalificacion::agregarSuscripto(empleado* e){
    static_cast<IObserver*>(e);
    observers.insert(pair<string,IObserver*>((*e).getEmail(),e));
}

void ControladorCalificacion::eliminarSuscripto(empleado* e){
    observers.erase((*e).getEmail());
}

void ControladorCalificacion::notificarSuscriptos(string nombreAutor,int puntuacion,string comentario){
    map<string,IObserver*>::iterator it;
    for (it=observers.begin() ; it!=observers.end() ; it++){
        (*(*it).second).notificar(nombreAutor,puntuacion,comentario);
    }
}

        map<int,DTEstadia*> ControladorCalificacion::obtenerEstadiasHuesped(string){
            map<int,DTEstadia*> a;
            return a;
        }
        void ControladorCalificacion::agregarCalificacion(string,int){}
        map<int,DTCalificacion*> ControladorCalificacion::obtenerCalificaciones(string){
            map<int,DTCalificacion*> a;
            return a;
        }
void ControladorCalificacion::ingresarComentario(string coment){//repetida, se le cambio el nombre pero no se elimino

}
        void ControladorCalificacion::liberarEstadia(){};
        void ControladorCalificacion::eliminarCalificacion(){}
        void ControladorCalificacion::RegistrarEstadia(DTHostal*, string, DTReserva*, DTEstadia*){}
void ControladorCalificacion::ingresarRespuesta(string resp, DTCalificacion* tcl){
    map<int,calificacion*>::iterator aux = (*this).calificaciones.find(tcl->getId());
    calificacion* aux2 = (*aux).second;
    
}
        float ControladorCalificacion::obtenerPromocionDeEstadia(){return 1;}
        int ControladorCalificacion::obtenerCodigoDeEstadia(){return 1;}
        DTCalificacion* ControladorCalificacion::obtenerCalificacionDeEstadia(){return NULL;}
        DTRespuesta* ControladorCalificacion::obtenerRespuesta(DTCalificacion*){return NULL;}