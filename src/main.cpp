#include "../include/fabrica.h"

int main(){
    Date d = Date(1,1,1);
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();

    calificacion* c1 = new calificacion(1,1,"a",d);
    calificacion* c2 = new calificacion(2,4,"a",d);
    calificacion* c3 = new calificacion(3,5,"a",d);
    calificacion* c4 = new calificacion(4,6,"a",d);
    calificacion* c5 = new calificacion(5,2,"a",d);
    calificacion* c6 = new calificacion(6,3,"a",d);
    calificacion* c7 = new calificacion(7,4,"a",d);
    calificacion* c8 = new calificacion(8,2,"a",d);
    calificacion* c9 = new calificacion(9,9,"a",d);

    hostal* h1 = new hostal("a","z","094897859");
    hostal* h4 = new hostal("d","z","z");

    (*h1).agregarCalificacionAMap(c4);
    (*h1).agregarCalificacionAMap(c5);
    (*h4).agregarCalificacionAMap(c8);
    
    (*ch).agregarHostalAMap(h1);
    (*ch).agregarHostalAMap(h4);

    map<string,DTHostal*> hostales = (*ch).obtenerTop3Hostales();
    map<string,DTHostal*>::iterator it;
    for (it=hostales.begin() ; it!=hostales.end() ; it++){
        cout << (*(*it).second).getNombre() << endl;
    }
    DTHostal* xd = (*hostales.find("a")).second;
    hostales.erase("a");
    cout << (*xd).getTelefono() << endl;
}