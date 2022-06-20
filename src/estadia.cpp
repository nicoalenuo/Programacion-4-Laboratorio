#include "../include/estadia.h"
#include "../include/fabrica.h"
#include "../include/FechaSistema.h"

estadia::~estadia(){
    
}

estadia::estadia(int codigoAct){
    FechaSistema* fs = FechaSistema::getInstance();
    calificacionAsoc=NULL;

    this->fechaEntrada =(*fs).getFechaActual();
    fechaSalida = NULL;
    this->codigo = codigoAct;
}

calificacion* estadia::getCalificacion(){
    return calificacionAsoc;
}

Date estadia::getFechaEntrada(){
    return fechaEntrada;
}

Date* estadia::getFechaSalida(){
    return fechaSalida;
}

int estadia::getCodigo(){
    return codigo;
}

void estadia::setCalificacion(calificacion* c){
    calificacionAsoc=c;
}

void estadia::setFechaEntrada(Date fe){
    fechaEntrada=fe;
}

void estadia::setFechaSalida(Date* fs){
    fechaSalida=fs;
}

void estadia::setCodigo(int c){
    codigo=c;
}

bool estadia::estaActiva(){
    return fechaSalida==NULL;
}

void estadia::finalizarEstadiaActiva(){
    FechaSistema* fs=FechaSistema::getInstance();
    if (estaActiva()){
        Date* fechaActual = new Date(((*fs).getFechaActual()).getDia(),((*fs).getFechaActual()).getMes(),((*fs).getFechaActual()).getAnio(),((*fs).getFechaActual()).getHora());
        setFechaSalida(fechaActual);
    }
}

DTEstadia* estadia::darDatos(){
    Date* fs=NULL;
    if (fechaSalida!=NULL)
        fs = new Date((*fechaSalida).getDia(),(*fechaSalida).getMes(),(*fechaSalida).getAnio(),(*fechaSalida).getHora());

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
