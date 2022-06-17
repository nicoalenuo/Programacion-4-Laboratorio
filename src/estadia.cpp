#include "../include/estadia.h"
#include "../include/fabrica.h"
#include "../include/FechaSistema.h"

estadia::estadia(int codigoAct){
    FechaSistema* fs = FechaSistema::getInstance();
    calificacionAsoc=NULL;

    this->fechaEntrada =(*fs).getFechaActual();
    fechaSalida = NULL;
    this->codigo = codigoAct;
}

bool estadia::estaActiva(){
    return fechaSalida==NULL;
}

void estadia::finalizarEstadiaActiva(){
    FechaSistema* fs=FechaSistema::getInstance();
    Date* fechaActual = new Date(((*fs).getFechaActual()).getDia(),((*fs).getFechaActual()).getMes(),((*fs).getFechaActual()).getAnio());
    if (estaActiva()){
        setFechaSalida(fechaActual);
    }
}

DTEstadia* estadia::darDatos(){
    Date* fs=NULL;
    if (fechaSalida!=NULL)
        fs = new Date((*fechaSalida).getDia(),(*fechaSalida).getMes(),(*fechaSalida).getAnio());

    DTEstadia* resultado = new DTEstadia(fechaEntrada,fs,codigo);
    return resultado;
}

void estadia::eliminarEstadia(){
    fabrica* f = fabrica::getInstance();
    IControladorCalificacion* icc = (*f).getIControladorCalificacion();
    calificacion* c = calificacionAsoc;
    if(c!= NULL){
        c->eliminarCalificacion();
        delete calificacionAsoc;
        c= NULL;
    }
    if (fechaSalida!=NULL)
        delete fechaSalida;
        
    (*icc).quitarEstadia(codigo);
}

estadia::~estadia(){
    
}