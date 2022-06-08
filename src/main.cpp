#include "../include/fabrica.h"

int main(){
    empleado* e = new empleado("a","b","c",Limpieza);
    hostal* h = new hostal("xd","aa","bb");
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    IControladorUsuario* cu = (*f).getIControladorUsuario();
    DTHostal* dth = new DTHostal("xd","aa","bb",0);
    (*ch).IngresarDatosHostal(dth);
    (*cu).agregarEmpleadoAMap(e);
    (*ch).agregarHostalAMap(h);
    map<string,DTEmpleado*> empleados=(*cu).obtenerEmpleados();
    map<string,DTEmpleado*>::iterator it;
    for (it=empleados.begin() ; it!=empleados.end() ; it++){
        cout << (*(*it).second).getMail() << endl;
    }
    (*cu).AsignarEmpleadoAHostal("b");
    cout << "FIJNIPDF" << endl;
    
}