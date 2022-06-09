#include "../include/fabrica.h"

int main(){
    fabrica* f = fabrica::getInstance();
    IControladorUsuario* cu = (*f).getIControladorUsuario();
    huesped* h = new huesped("a","b","c",true);
    empleado* e = new empleado("aa","bb","cc",Limpieza);
    (*cu).agregarEmpleadoAMap(e);
    (*cu).agregarHuespedAMap(h);

    map<string,DTUsuario*> xd = (*cu).obtenerUsuarios();
    map<string,DTUsuario*>::iterator it;

    for (it=xd.begin() ; it!=xd.end() ; it++){
        cout << (*(*it).second).getNombre() << endl;
    }

}