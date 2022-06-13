#include "../include/fabrica.h"

int main(){
    fabrica* f = fabrica::getInstance();
    IControladorUsuario* cu = (*f).getIControladorUsuario();
    IControladorHostal* ch = (*f).getIControladorHostal();
    huesped* h = new huesped("a","b","c",true);
    empleado* e = new empleado("aa","bb","cc",Limpieza);
    (*cu).agregarEmpleadoAMap(e);
    (*cu).agregarHuespedAMap(h);

    map<string,DTUsuario*> xd = (*cu).obtenerUsuarios();
    map<string,DTUsuario*>::iterator it;

    for (it=xd.begin() ; it!=xd.end() ; it++){
        cout << (*(*it).second).getNombre() << endl;
    }

    DTHostal* datos = (*ch).getDatosHostal(); //Esto iria en el main
    cout << datos->getNombre() << endl;
    cout << datos->getDireccion() << endl;
    cout << datos->getTelefono() << endl; 
    cout << datos->getCalificacionPromedio() << endl;

    //mostrarHabitacion()
    DTHabitacion* habitacion;
    /*De alguna forma que no voy a indagar aún
    se obtiene la habitacion asociada a la reserva elegida*/
    cout << habitacion->getNumero() << endl;
    cout << habitacion->getPrecio() << endl;
    cout << habitacion->getCapacidad() << endl;

    //mostrarReserva()
    DTReserva* dtr;
    /*De alguna forma que no voy a indagar aún
    se obtiene para toda reserva, del hostal en memoria*/
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