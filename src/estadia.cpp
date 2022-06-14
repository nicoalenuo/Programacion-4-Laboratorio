#include "../include/estadia.h"
#include "../include/FechaSistema.h"

estadia::estadia(DTEstadia* est){
    this->fechaEntrada = est->getFechaEntrada();
    this->fechaSalida = est->getFechaSalida();
    this->codigo = est->getCodigo();
}

bool estadia::estaActiva(){
    return fechaSalida!=NULL;
}

void estadia::finalizarEstadiaActiva(){
    FechaSistema* fs=FechaSistema::getInstance();
    Date* fechaActual;
    (*fechaActual)=(*fs).getFechaActual();
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