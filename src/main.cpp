#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>
#include <typeinfo>
using namespace std;

#include "../include/fabrica.h"
#include "../include/FechaSistema.h"

//funcion auxiliar
DTHostal* ElegirHostal(){
	cout<< "Por favor, seleccione un hostal de la siguiente lista: \n";
	fabrica* f = fabrica::getInstance();
    IControladorHostal *ICH = (*f).getIControladorHostal();
    map<string,DTHostal*> listaHostales = (*ICH).obtenerHostales();
	map<string,DTHostal*>::iterator it;
    DTHostal * aux;
    bool correcto;
	int cont;
    int numHostal;
    do{
        cont = 0;
        for(it=listaHostales.begin(); it!=listaHostales.end(); it++){
		    cont++;
            cout << cont <<". Nombre: " << ((*it).second)->getNombre() << endl;
        };
        cout<<"Eleccion: \n";
        cin>>numHostal;
        if(numHostal>cont || numHostal==0){
            cout<<"El valor ingresado no es correcto, por favor ingrese otro: \n";
            correcto = false;
        }else{
            correcto = true;
        }
    }while(!correcto);
    
    cont = 1;
    it = listaHostales.begin();
    while(cont<numHostal){
        it++;
        cont++;
    };
    aux = (*it).second;
    for (it=listaHostales.begin() ; it!=listaHostales.end() ; it++){
        if((*(*it).second).getNombre() != (*aux).getNombre()){
            delete (*it).second;
        }
    }
    listaHostales.clear();
    return aux;	
};

int main(){
    //----Declaracion de controladores----//
    fabrica* f = fabrica::getInstance();
    IControladorHostal *ICH = (*f).getIControladorHostal(); 
    IControladorUsuario *ICU = (*f).getIControladorUsuario();
    IControladorReserva *ICR = (*f).getIControladorReserva();
    IControladorCalificacion *ICC = (*f).getIControladorCalificacion();
    FechaSistema* fec = FechaSistema::getInstance();
    //----Declaracion de variables----//
    char OpcionAux, esFingerAux, confirmarAlta,CargoAux;
    int nota, Opcion1, Opcion2, num, capacidad, tipoR, dia1, mes1, anio1, dia2, mes2, anio2, hora1, hora2, ind, codReserva;
    float precio;
    string hostalSel, MailHuesped, NombreHos, DirHos, TelHos, Nombre, pass, email, Comentario;
    Cargo cargo;
    bool existe, finalizar, finSubMenu, esFinger, cargoCorrecto, aux;
    map<int,DTReserva*>::iterator itDTR;
    map<int,DTEstadia*>::iterator itDTEs;
    finalizar = false;
    codReserva = 0;
    //-----------------------//
    while (!finalizar){
        finSubMenu = false;
        cout << "-------------------------------\n";
        cout << "Seleccione la operacion que desea realizar: \n";
        cout << "1. Administracion de Hostales \n";
        cout << "2. Administracion de Usuarios \n";
        cout << "3. Administracion de Reservas \n";
        cout << "4. Administracion de Calificaciones \n";
        cout << "5. Modificar Fecha de Sistema \n";
        cout << "6. Cargar datos de prueba \n";
        cout << "7. Salir \n";
        cout << "-------------------------------\n";
            
        cin >> OpcionAux;
        Opcion1 = (int)OpcionAux - '0'; //Control en caso de que se ingrese char en vez de int

        switch(Opcion1){
            case 1:{ //Administracion de Hostales
                while(!finSubMenu){
                    cout << "-------------------------------\n";
                    cout << "Seleccione la operacion que desea realizar: \n";
                    cout << "1. Alta Hostal \n";
                    cout << "2. Alta Habitacion \n";
                    cout << "3. Consultar Hostal \n";
                    cout << "4. Consultar Top 3 Hostales \n";
                    cout << "5. Volver \n";
                    cout << "-------------------------------\n";

                    cin >> OpcionAux;
                    Opcion2 = (int)OpcionAux - '0'; //Control en caso de que se ingrese char en vez de int
                    switch(Opcion2){
                        case 1:{ //Alta Hostal
                            cout << "Por favor, ingrese los siguientes datos: \n";
                            map<string,DTHostal*> listaHost = (*ICH).obtenerHostales();
                            map<string,DTHostal*>::iterator k;
                            cin.ignore();
                            do{                                
                                cout << "Nombre del hostal: ";
                                
                                getline(cin, NombreHos);
                                k = listaHost.find(NombreHos);
                                if(k!=listaHost.end()){
                                    cout<< "Ya existe un hostal con el nombre ingresado. Por favor ingrese otro \n";
                                }
                                                            
                            }while(k!=listaHost.end());     
   
                            cout << "Direccion del hostal: ";
                            getline(cin, DirHos);
                            cout << "Telefono del hostal: ";
                            getline(cin, TelHos);
                            
                            DTHostal* pdth = new DTHostal(NombreHos,DirHos,TelHos,0);
                            (*ICH).IngresarDatosHostal(pdth);
                            do{  
                                cout<<"Desea confirmar el alta? S / N \n";
                                cin >> confirmarAlta; 
                                if ((char) toupper(confirmarAlta) == 'S'){
                                    (*ICH).confirmarAltaHostal();
                                    cout<<"Se confirmo el alta del hostal "<<(*pdth).getNombre()<<" \n";                          
                                }else{
                                    if ((char) toupper(confirmarAlta) == 'N')
                                        cout<<"Se cancelo el alta \n";
                                    else
                                        cout << "La opcion ingresada no es valida.\n";
                                };
                            }while((char) toupper(confirmarAlta) != 'S' && (char) toupper(confirmarAlta) != 'N');
                            for (k=listaHost.begin() ; k!=listaHost.end() ; k++){
                                delete (*k).second;
                            }
                            listaHost.clear();
                            (*ICH).liberarMemoria();                             
                        };
                        break;
                        //case 1 | Alta Hostal

                        case 2:{ //Alta Habitacion
                            
                            DTHostal* dth = ElegirHostal();
                            (*ICH).IngresarDatosHostal(dth);
                            cout << "Por favor, ingrese los siguientes datos: \n";
                            cout << "Numero de habitacion: ";
                            do{                                
                                cin >> num;
                                existe = (*ICH).existeHabConNumero(num, dth->getNombre());
                                if(existe){
                                    cout<<"Ya existe una habitación con el numero "<<num<< " en el hostal "<<dth->getNombre()<<endl;
                                    cout<<"Por favor ingrese otro numero: \n";
                                }                       
                                                         
                            }while(existe);
                            cout << "Precio de la habitacion: ";
                            cin>>precio;
                            cout << "Capacidad de la habitacion: ";
                            cin>>capacidad;
                                                       
                            DTHabitacion* pdthab = new DTHabitacion(num,precio,capacidad);
                            (*ICH).IngresarDatosHab(pdthab);
                            do{
                                cout<<"Desea confirmar el alta? S / N \n";
                                cin >> confirmarAlta; 
                                if ((char) toupper(confirmarAlta) == 'S'){
                                    (*ICH).confirmarAltaHabitacion();
                                    cout<<"Se confirmo el alta de la habitacion "<<num <<" en el hostal "<<(*dth).getNombre()<<" \n";
                                }else{
                                    if ((char) toupper(confirmarAlta) == 'N')
                                        cout<<"Se cancelo el alta \n";
                                    else
                                        cout << "La opcion ingresada no es valida.\n";
                                };
                            }while((char) toupper(confirmarAlta) != 'S' && (char) toupper(confirmarAlta) != 'N');

                            (*ICH).liberarMemoria();
                            
                        };
                        break;
                        // case 2 | Alta Habitacion

                        case 3:{  //Consultar Hostal

                            map<string,DTHostal*> dthostales= ICH->obtenerHostales();
                            map<string,DTHostal*>::iterator it;
                            if(dthostales.size()==0){
                                cout<<"No hay hostales ingresados.";
                            }else{
                                int cont=0;
                                for(it=dthostales.begin();it!=dthostales.end();it++){
                                    cont++;
                                    cout << cont << "- Hostal " << endl;
                                    cout << "   Nombre: " << (*it).second->getNombre() << endl;
                                    cout << "   Direccion: " << (*it).second->getDireccion() << endl;
                                    cout << "   Telefono: " << (*it).second->getTelefono() << endl;
                                    cout << endl;
                                }
                                int elegir;
                                do{
                                    cont = 1;
                                    it=dthostales.begin();
                                    cout << "Elija un hostal de acuerdo a su numero" << endl;
                                    cin >> elegir;
                                    if(elegir > dthostales.size() || elegir<=0){
                                        cout << "El numero elegido no pertenece a la lista" << endl;
                                    }else{
                                        while(cont<elegir){
                                            cont++;
                                            it++;
                                        }
                                    }
                                }while(elegir > dthostales.size() || elegir <=0);
                                //guarda DTHostal en memoria
                                (*ICH).setDatosHostal((*it).second);
                                //mostar el hostal
                                cout << "    Hostal" << endl;
                                cout << "Nombre: " << (*ICH).getDatosHostal()->getNombre() << endl;
                                cout << "Direccion: " << (*ICH).getDatosHostal()->getDireccion() << endl;
                                cout << "Telefono: " << (*ICH).getDatosHostal()->getTelefono() << endl;
                                //mostrar el promedio de calificaciones del hostal
                                if((*ICH).getDatosHostal()->getCalificacionPromedio()!=0){
                                    cout << "Promedio: " << (*ICH).getDatosHostal()->getCalificacionPromedio() << endl;
                                }else{
                                    cout << "Promedio: No existe." << endl;
                                }
                                cout << endl;
                                //mostrar las calificaciones del hostal
                                map<int,DTCalificacion*> dtcalificaciones= (*ICH).obtenerCalificacionesDeHostal();
                                map<int,DTCalificacion*>::iterator itcal;
                                DTCalificacion* dtcal;
                                cont=0;
                                if(dtcalificaciones.size()==0){
                                    cout << "No existen calificaciones para este hostal" << endl;
                                }else{
                                    for(itcal=dtcalificaciones.begin();itcal!=dtcalificaciones.end();itcal++){
                                        dtcal= (*itcal).second;
                                        cout << "    Calificacion " << endl;
                                        cout << "Comentario: " << dtcal->getComentario() << endl;
                                        cout << "Puntuacion: " << dtcal->getPuntuacion() << endl;
                                        cout << endl;
                                    }
                                }
                                //mostar habitaciones del hostal
                                map<int,DTHabitacion*> dthabitaciones= (*ICH).obtenerHabitacionesDeHostal();
                                map<int,DTHabitacion*>::iterator it1;
                                if(dthabitaciones.size()==0){
                                    cout << "No existen habitaciones en este hostal" << endl;
                                }else{
                                    for(it1=dthabitaciones.begin();it1!=dthabitaciones.end();it1++){
                                        cout << "    Habitacion " << endl;
                                        cout << "Numero: " << (*it1).second->getNumero() << endl;
                                        cout << "Precio: " << (*it1).second->getPrecio() << endl;
                                        cout << "Capacidad: " << (*it1).second->getCapacidad() << endl;
                                        cout << endl;
                                    }
                                }
                                //mostrar reservas del hostal
                                map<int,DTReserva*> dtreservas = (*ICH).obtenerReservasDeHostal();
                                map<int,DTReserva*>::iterator it2;
                                if(dtcalificaciones.size()==0){
                                    cout << "No existen reservas en este hostal" << endl;
                                }else{
                                    for(it2=dtreservas.begin();it2!=dtreservas.end();it2++){
                                        cout << "    Reserva " << endl;
                                        cout << "Fecha de Ingreso: " << (*it2).second->getCheckIn().getDia() << "/" << (*it2).second->getCheckIn().getMes() << "/" << (*it2).second->getCheckIn().getAnio() << " - " << (*it2).second->getCheckIn().getHora() << ":00" << endl;
                                        cout << "Fecha de Salida: " << (*it2).second->getCheckOut().getDia() << "/" << (*it2).second->getCheckOut().getMes() << "/" << (*it2).second->getCheckOut().getAnio() << " - " << (*it2).second->getCheckOut().getHora() << ":00" << endl;
                                        EstadoReserva aux =(*(*it2).second).getEstado();
                                        int aux2 = (int)aux;
                                        switch(aux2){
                                            case 0 :{
                                                cout << "Estado: Abierto"<< endl;
                                            };
                                            break;
                                            case 1 :{
                                                cout << "Estado: Cerrado"<< endl;
                                            };
                                            break;
                                            case 2 : {
                                                cout << "Estado: Cancelado"<< endl;
                                            };
                                            break;
                                        }
                                        cout << "Costo: " << (*it2).second->getCosto() << endl;
                                        cout << endl;
                                    }
                                }
                                /*for (it = dthostales.begin() ; it!=dthostales.end() ; it++)
                                    delete (*it).second;*/
                                for (it1 = dthabitaciones.begin() ; it1!=dthabitaciones.end() ; it1++)
                                    delete (*it1).second;
                                for (itcal = dtcalificaciones.begin() ; itcal!=dtcalificaciones.end() ; itcal++)
                                    delete (*itcal).second;
                                for (it2 = dtreservas.begin() ; it2!=dtreservas.end() ; it2++)
                                    delete (*it2).second;

                                dthostales.clear();
                                dthabitaciones.clear();
                                dtcalificaciones.clear();
                                dtreservas.clear();
                            }
                            //liberarMemoria del Hostal
                            (*ICH).liberarMemoria();

                        };
                        break;
                        // case 3 | Consultar Hostal

                        case 4: {//Consultar Top 3 Hostales
                            
                            map<string,DTHostal*> top3 = (*ICH).obtenerTop3Hostales();
                            if(top3.size()==0){
                                cout<<"No hay hostales registrados. \n";
                            }else{
                                ind = 0;
                                map<string,DTHostal*>::iterator it;
                                for (it=top3.begin(); it!=top3.end(); it++){
                                    ind++;
                                    cout << "No. " << ind << ": " << endl;
                                    cout << "Nombre : " << ((*it).second)->getNombre() << endl;
                                    cout << "Direccion : " << ((*it).second)->getDireccion() << endl;
                                    cout << "Telefono : " << ((*it).second)->getTelefono() << endl;
                                    cout << "Promedio : " << ((*it).second)->getCalificacionPromedio() << endl;
                                    cout << endl;
                                }
                            }
                        };
                        break;
                        
                        case 5:{
                            finSubMenu = true;
                        };
                        break;
                        //Volver a menú 1
                        default:{
                            cout<< "Por favor, seleccione una opcion entre 1 y 5. \n";
                        };
                        break;

                    }//switch(Opcion2)
                }//while(!finSubMenu)
            }//case 1 | Administracion de Hostales

            case 2:{ //Administracion de Usuarios
                while(!finSubMenu){
                    cout << "-------------------------------\n";
                    cout << "Seleccione la operacion que desea realizar: \n";
                    cout << "1. Alta Empleado \n";
                    cout << "2. Alta Huesped \n";
                    cout << "3. Asignar Empleado a Hostal \n";
                    cout << "4. Consultar Usuario \n";
                    cout << "5. Suscribir a Notificaciones \n";
                    cout << "6. Consultar Notificaciones \n";
                    cout << "7. Eliminar Suscripcion \n";
                    cout << "8. Volver \n";
                    cout << "-------------------------------\n";

                    cin >> OpcionAux;
                    Opcion2 = (int)OpcionAux - '0'; //Control en caso de que se ingrese char en vez de int
                    switch(Opcion2){
                        case 1:{ //Alta Empleado
                            cout<<"Por favor, ingrese los siguientes datos: \n";
                            cout<<"Nombre: \n";
                            cin.ignore();
                            getline(cin, Nombre);
                            cout<<"Contraseña: \n";
                            cin.ignore();
                            getline(cin, pass);
                            cargoCorrecto = false;
                            cout<<"Seleccione el cargo: \n";
                            do{
                                cout<<"1. Limpieza \n";                 
                                cout<<"2. Administracion \n";
                                cout<<"3. Recepcion \n";
                                cout<<"4. Infraestructura \n";      
                                cin>>CargoAux;                                
                                switch (CargoAux){
                                    case '1':{ 
                                        cargo = Limpieza;
                                        cargoCorrecto = true;
                                    };
                                    break;
                                    case '2':{ 
                                        cargo = Administracion;
                                        cargoCorrecto = true;
                                    };
                                    break;
                                    case '3':{ 
                                        cargo = Recepcion;
                                        cargoCorrecto = true;
                                    };
                                    break;
                                    case '4':{ 
                                        cargo = Infraestructura;
                                        cargoCorrecto = true;
                                    };
                                    break;
                                    default:{ 
                                        cout<<"Por favor, ingrese una opcion entre 1 y 4: \n";
                                        cin>>CargoAux;
                                    }
                                }//switch (CargoAux)
                            }while(!cargoCorrecto);
                            cout<<"Email: \n";
                            cin.ignore();
                            do{                                
                                getline(cin, email);
                                existe = (*ICU).IngresarEmail(email);
                                if (!existe){
                                    cout<<"El email ingresado ya existe, por favor ingrese otro. \n" ;
                                }
                                cin.clear();
                                cin.sync();
                            }while(!existe);
                            do{  
                                cout<<"Desea confirmar el alta? S / N \n";
                                cin >> confirmarAlta; 
                                if ((char) toupper(confirmarAlta) == 'S'){
                                    DTUsuario* dte = new DTEmpleado(Nombre,email,pass,cargo);
                                    (*ICU).IngresarDatosUsuario(dte);
                                    (*ICU).confirmarAltaUsuario();
                                    cout<<"Se confirmo el alta del empleado "<<(*dte).getNombre() <<", email: "<<(*dte).getEmail()<<endl;
                    
                                }else{
                                    if ((char) toupper(confirmarAlta) == 'N')
                                        cout<<"Se cancelo el alta \n";
                                    else
                                        cout << "La opcion ingresada no es valida.\n";
                                };
                            }while((char) toupper(confirmarAlta) != 'S' && (char) toupper(confirmarAlta) != 'N');
                                                      
                            (*ICU).liberarMemoria();
                        };
                        break;
                        //case 1 | Alta Empleado

                        case 2: {//Alta Huesped
                            cout<<"Por favor, ingrese los siguientes datos: \n";
                            cout<<"Nombre: \n";
                            cin.ignore();
                            getline(cin, Nombre);
                            cout<<"Contraseña: \n";
                            cin.ignore();
                            getline(cin, pass);
                            esFingerAux;
                            do{
                                cout << "Si el huesped es Finger digite 'S', de lo contrario, digite 'N' \n";
                                cin >> esFingerAux; 
                                if ((char) toupper(esFingerAux) == 'S'){
                                    esFinger = true;
                                }else{
                                    if ((char) toupper(esFingerAux) == 'N')
                                        esFinger = false;
                                    else
                                        cout << "La opcion ingresada no es válida.\n";
                                };
                            }while((char) toupper(esFingerAux) != 'S' && (char) toupper(esFingerAux) != 'N');
                            cout<<"Email: \n";
                            cin.ignore();
                            do{
                                getline(cin, email);
                                existe = (*ICU).IngresarEmail(email);
                                if (!existe){
                                    cout<<"El email ingresado ya existe, por favor ingrese otro: \n" ;
                                }
                                cin.clear();
                                cin.sync();
                                
                            }while(!existe);
                            do{  
                                cout<<"Desea confirmar el alta? S / N \n";
                                cin >> confirmarAlta; 
                                if ((char) toupper(confirmarAlta) == 'S'){
                                    DTUsuario* dth = new DTHuesped(Nombre,email,pass,cargo);
                                    (*ICU).IngresarDatosUsuario(dth);
                                    (*ICU).confirmarAltaUsuario();
                                    cout<<"Se confirmo el alta de Huesped "<<(*dth).getNombre() <<", email: "<< (*dth).getEmail()<<endl;
                    
                                }else{
                                    if ((char) toupper(confirmarAlta) == 'N')
                                        cout<<"Se cancelo el alta \n";
                                    else
                                        cout << "La opcion ingresada no es valida.\n";
                                };
                            }while((char) toupper(confirmarAlta) != 'S' && (char) toupper(confirmarAlta) != 'N');   
                                          
                            (*ICU).liberarMemoria();
                        };
                        break;
                        //case 2 | Alta Huesped

                        case 3: {//Asignar Empleado a Hostal
                            DTHostal * dth = ElegirHostal();
                            (*ICH).IngresarDatosHostal(dth);
                            map<string,DTEmpleado*> empsLibres = (*ICU).obtenerEmpleadosNoAsignados();
                            map<string,DTEmpleado*>::iterator it;
                            
                            existe = false;
                            aux = false;
                            while(!existe){
                                if(aux){
                                    cout<<"El número ingresado no es correcto. \n";
                                }
                                ind = 1;
                                cout<<"Seleccione el número correspondiente al empleado que desea asignar de la siguiente lista: \n";
                                for(it=empsLibres.begin(); it!=empsLibres.end(); it++){
                                    cout<<ind<<". Nombre: "<<((*it).second)->getNombre() <<", Email: "<<((*it).second)->getEmail()<< endl;
                                    ind++;
                                }
                                cin>>num;
                                if(num>ind || num==0){
                                    existe = false;
                                    aux = true;
                                };
                            };
                            ind = 1;
                            it = empsLibres.begin();
                            while(ind<num){
                                it++;
                                ind++;
                            };
                            (*ICU).AsignarEmpleadoAHostal((*it).second->getEmail());
                            (*ICH).FinalizarAsignacionDeEmpleados();	
                        };
                        break;
                        //case 3 | Asignar Empleado a Hostal

                        case 4:{ //Consultar Usuario
                            map<string,DTUsuario*> dtusuarios = (*ICU).obtenerUsuarios();
                            //elegir un usuario
                            if(dtusuarios.size()==0){
                                cout<<"No hay usuarios ingresados.";
                            }else{
                                map<string,DTUsuario*>::iterator it;
                                int cont=0;
                                //mostrarUsuarios
                                for(it=dtusuarios.begin();it!=dtusuarios.end();it++){
                                    cont++;
                                    cout << cont <<  "- Nombre: " << (*it).second->getNombre() << endl;
                                    cout << "   Email: " << (*it).second->getEmail() << endl;
                                    cout << endl;
                                }
                                cout << "Elija un usuario de acuerdo a su numero" << endl;
                                int elegir;
                                do{
                                    cont = 1;
                                    it=dtusuarios.begin();
                                    cin >> elegir;
                                    if(elegir > dtusuarios.size() || elegir<=0){
                                        cout << "El numero elegido no pertenece a la lista" << endl;
                                    }else{
                                        while(cont<elegir){
                                            cont++;
                                            it++;
                                        }
                                    }
                                }while(elegir > dtusuarios.size() || elegir <=0);
                                //guardar DTUsuario en memoria
                                (*ICU).IngresarDatosUsuario((*it).second);
                                //mostrar el usuario
                                cout << "    Usuario elegido" << endl;
                                cout << "Nombre: " << (*ICU).obtenerDatosUsuario()->getNombre() << endl;
                                cout << "Email: " << (*ICU).obtenerDatosUsuario()->getEmail() << endl;
                                if(dynamic_cast<DTHuesped*>((*ICU).obtenerDatosUsuario())!=NULL){
                                    DTHuesped* dth= (*ICU).obtenerHuespedConEmail((*ICU).obtenerDatosUsuario()->getEmail());
                                    if((*dth).getEsFinger()){
                                        cout << "Es finger." << endl;
                                    }else{
                                        cout << "No es finger." << endl;
                                    }
                                }else{
                                    DTEmpleado* dte= (*ICU).obtenerEmpleadoConEmail((*ICU).obtenerDatosUsuario()->getEmail());
                                    Cargo aux =(*dte).getTipoCargo();
                                    int aux2 = (int)aux;
                                        switch(aux2){
                                            case 0 :{
                                                cout << "Cargo: Limpieza"<< endl;
                                            };
                                            break;
                                            case 1 :{
                                                cout << "Cargo: Administracion"<< endl;
                                            };
                                            break;
                                            case 2 : {
                                                cout << "Cargo: Recepcion"<< endl;
                                            };
                                            break;
                                            case 3 :{
                                                cout << "Cargo: Infraestructura"<< endl;
                                            };
                                            break;
                                        }
                                    map<string,DTHostal*> hostales= (*ICH).obtenerHostales();
                                    map<string,DTHostal*>::iterator it1=hostales.begin();
                                    map<string,DTEmpleado*>::iterator it2;
                                    map<string,DTHostal*>::iterator it3;
                                    map<string,DTEmpleado*> emps;
                                    bool encontrado=false;
                                    DTHostal* dth;
                                    while(!encontrado && it1!=hostales.end()){
                                        emps = (*ICH).obtenerEmpleados((*(*it1).second).getNombre());
                                        it2= emps.begin();
                                        while(!encontrado && it2!=emps.end()){
                                            if((*it2).second->getEmail()== dte->getEmail()){
                                                dth= (*it1).second;
                                                encontrado= true;
                                                aux = (*it2).second->getTipoCargo();
                                            }else{
                                                it2++;
                                            }
                                        }
                                        for (it2=emps.begin () ; it2!=emps.end() ; it2++)
                                                delete (*it2).second;
                                        
                                        it1++;
                                    }
                                    if(it1!=hostales.end()){
                                        //mostar el hostal
                                        cout << endl;
                                        cout << "    Hostal " << endl;
                                        cout << "Nombre: " << dth->getNombre() << endl;
                                        cout << "Direccion: " << dth->getDireccion() << endl;
                                        cout << "Telefono: " << dth->getTelefono() << endl;
                                        
                                    }
                                    for (it3=hostales.begin () ; it3!=hostales.end() ; it3++)
                                        delete (*it3).second;
                                    hostales.clear();
                                }   
                                //Libera memoria del usuario
                                (*ICU).liberarMemoria();
                            };
                                
                        };
                        break;
                        //case 4 | Consultar Usuario

                        case 5:{ //Suscribir a Notificaciones
                            int i=1;
                            int eleccion;
                            map<string,DTEmpleado*> empleados = (*ICU).obtenerEmpleados();
                            map<string,DTEmpleado*>::iterator it;

                            cout << "Seleccione un empleado:" << endl;
                            for (it=empleados.begin() ; it!=empleados.end() ; it++){
                                cout << i << "- " << (*(*it).second).getNombre() << endl;
                                cout << "   " << (*(*it).second).getEmail() << endl;
                                cout << endl;
                                i++;
                            }
                            cout << "Eleccion: " << endl;
                            cin >> eleccion;
                            it = empleados.begin();
                            for (i=1 ; i<eleccion ; i++){
                                it++;
                            }

                            (*ICU).suscribirEmpleado((*(*it).second).getEmail());

                            for (it=empleados.begin() ; it!=empleados.end() ; it++){
                                delete (*it).second;
                            }
                        };
                        break;
                        case 6:{ //Consultar Notificaciones
                            int i=1;
                            int eleccion;
                            map<string,DTEmpleado*> empleados = (*ICU).obtenerEmpleados();
                            map<string,DTEmpleado*>::iterator it;
                            set<DTNotificacion*>::iterator it2;

                            cout << "Seleccione un empleado:" << endl;
                            for (it=empleados.begin() ; it!=empleados.end() ; it++){
                                cout << i << "- " << (*(*it).second).getNombre() << endl;
                                cout << "   " << (*(*it).second).getEmail() << endl;
                                cout << endl;
                                i++;
                            }
                            cout << "Eleccion: " << endl;
                            cin >> eleccion;
                            it = empleados.begin();
                            for (i=1 ; i<eleccion ; i++){
                                it++;
                            }

                            set<DTNotificacion*> notificaciones = (*ICU).consultarNotificaciones((*(*it).second).getEmail());

                            for (it2=notificaciones.begin() ; it2!=notificaciones.end() ; it2++){
                                cout << (*(*it2)).getNombreAutor() << endl;
                                cout << (*(*it2)).getPuntuacion() << endl;
                                cout << (*(*it2)).getComentario() << endl;
                                delete (*it2);
                            }
                            
                            for (it=empleados.begin() ; it!=empleados.end() ; it++){
                                delete (*it).second;
                            }
                        };
                        break;

                        case 7:{ //Eliminar Suscripcion
                            int i=1;
                            int eleccion;
                            map<string,DTEmpleado*> empleados = (*ICU).obtenerEmpleados();
                            map<string,DTEmpleado*>::iterator it;

                            cout << "Seleccione un empleado:" << endl;
                            for (it=empleados.begin() ; it!=empleados.end() ; it++){
                                cout << i << "- " << (*(*it).second).getNombre() << endl;
                                cout << "   " << (*(*it).second).getEmail() << endl;
                                cout << endl;
                                i++;
                            }
                            cout << "Eleccion: " << endl;
                            cin >> eleccion;
                            it = empleados.begin();
                            for (i=1 ; i<eleccion ; i++){
                                it++;
                            }

                            (*ICU).desuscribirEmpleado((*(*it).second).getEmail());

                            for (it=empleados.begin() ; it!=empleados.end() ; it++){
                                delete (*it).second;
                            }
                        };
                        break;
                        case 8:{ //Volver
                            finSubMenu = true;
                        }; 
                        break;

                        default:{

                        }

                    }//switch(Opcion2)
                }//while(!finSubMenu)
            }//case 2 | Administracion de Usuarios

            case 3:{ //Administracion de Reservas
                while(!finSubMenu){
                    cout << "-------------------------------\n";
                    cout << "Seleccione la operacion que desea realizar: \n";
                    cout << "1. Realizar Reserva \n";
                    cout << "2. Consultar Reserva \n";
                    cout << "3. Baja de Reserva \n";
                    cout << "4. Registrar Estadia \n";
                    cout << "5. Consultar Estadia \n";
                    cout << "6. Finalizar Estadia \n";
                    cout << "7. Volver \n";
                    cout << "-------------------------------\n";

                    cin>> OpcionAux;
                    Opcion2 = (int)OpcionAux - '0'; //Control en caso de que se ingrese char en vez de int

                    switch(Opcion2){
                        case 1:{ //Realizar Reserva
                            
                            DTHostal * dth = ElegirHostal();
                            DTHabitacion *dthab; // Puntero al DTHabitacion con el numero elegido en el hostal elegido
                            cout<<"Por favor, ingrese la fecha de CheckIn: \n";
                            cout << "Día:";
                            cin >> dia1;
                            cout << "Mes:";
                            cin >> mes1;
                            cout << "Anio:";
                            cin >> anio1;
                            cout << "Hora:";
                            cin >> hora1;
                            Date ChIn(dia1,mes1,anio1,hora1); //DTFecha CheckIn
                            cout<<"Por favor, ingrese la fecha de CheckOut: \n";
                            cout << "Día:";
                            cin >> dia2;
                            cout << "Mes:";
                            cin >> mes2;
                            cout << "Anio:";
                            cin >> anio2;
                            cout << "Hora:";
                            cin >> hora2;
                            Date ChOut(dia2,mes2,anio2,hora2); //DTFecha CheckIn
                            cout<<"Por favor, ingrese el tipo de reserva: \n";
                            cout<<"1- Individual \n";
                            cout<<"2- Grupal \n";
                            cin>>tipoR;
                            (*ICR).ingresarDatosReserva(dth,ChIn,ChOut);
                            map<int,DTHabitacion*>::iterator j;
                            map<int,DTHabitacion*> habs = (*ICR).obtenerHabitacionesDisponibles();
                            if(!habs.empty()){
                                
                                cout<<"Por favor, seleccione el número de la habitacion que desea reservar: \n";
                                for(j=habs.begin(); j!=habs.end(); j++){
                                    cout<<"Numero: " << ((*(*j).second)).getNumero() << endl;
                                    cout<<"Precio: " << ((*(*j).second)).getPrecio() << endl;
                                    cout<<"Capacidad: " << ((*(*j).second)).getCapacidad() << endl;
                                    cout<<"..............................................." << endl;
                                };
                
                                cin>>num;
                                //controlar que sea un int
                                bool existe=false;
                                j = habs.begin();
                                while(j!=habs.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                    if(((*j).second)->getNumero() == num){
                                        existe = true;
                                        dthab = (*j).second;
                                    };
                                    j++;
                                };
                                while(!existe){ //si se ingreso un numero incorrecto, muestro las hab y pido reingresar
                                    cout<<"El número de habitacion ingresado no corresponde a una habitacion disponible.\n";
                                    for(j=habs.begin(); j!=habs.end(); j++){
                                        cout<<"Numero: " << (*(*j).second).getNumero() <<endl;
                                        cout<<"Precio: " << (*(*j).second).getPrecio() <<endl;
                                        cout<<"Capacidad: " << (*(*j).second).getCapacidad() <<endl;
                                        cout<<"..............................................."<< endl;
                                    };
                                    cout<< "Por favor, ingrese un número de habitacion de la lista: \n";
                                
                                    cin>>num;
                                    //controlar que sea un int

                                    j = habs.begin();
                                    while(j!=habs.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                        if((*(*j).second).getNumero() == num){
                                            existe = true;
                                            dthab = (*j).second;
                                        };
                                        j++;
                                    };

                                };//while(!existe)
                                
                                ICH->IngresarDatosHab(dthab);
                                //LISTO HUESPEDES
                                map<string,DTHuesped*> HuespedesAListar = ICU->obtenerHuespedes();
                                map<string,DTHuesped*>::iterator itCU;
                                DTHuesped* Hues;
                                cout<< "Seleccione un huesped: "<< endl;
                                for(itCU = HuespedesAListar.begin();itCU != HuespedesAListar.end(); itCU++ ){
                                    cout << " Nombre: " << (*itCU).second->getNombre() << "|| Email: " <<(*itCU).second->getEmail() << endl;
                                    cout<<"..............................................."<< endl;
                                }
                                cout<< "Ingrese el mail de un huesped: " << endl;
                                cin >> MailHuesped;
                               
                                //CONTROLO QUE EL MAIL SEA CORRECTO
                                existe= false;
                                itCU = HuespedesAListar.begin();
                                while(itCU!=HuespedesAListar.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                    if((*(*itCU).second).getEmail() == MailHuesped){
                                        existe = true;
                                        Hues = (*itCU).second;
                                    };
                                    itCU++;
                                };
                                while(existe == false){
                                    cout<< "###ERROR### Ingrese un email correcto: "<< endl;
                                    cin >> MailHuesped;
                                    //CONTROLO QUE EL MAIL SEA CORRECTO
                                    existe= false;
                                    itCU = HuespedesAListar.begin();
                                    while(itCU!=HuespedesAListar.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                        if((*(*itCU).second).getEmail() == MailHuesped){
                                            existe = true;
                                            Hues = (*itCU).second;
                                        };
                                        itCU++;
                                    };
                                }
                               
                                ICR->DesignarPropietarioDeReserva(Hues);
                                if(tipoR == 2){//GRUPAL
                                    existe= false;
                                        cout<< "---Usted está ingresando una reserva Grupal---- "<< endl;
                                        cout<< "Si desea dejar de ingresar huespedes inserte S "<< endl;
                                    while(MailHuesped != "S"){
                                        cout<< "Ingrese el mail del próximo huesped: "<< endl;
                                        cin >> MailHuesped;
                                        //CONTROLO QUE EL MAIL SEA CORRECTO
                                        existe= false;
                                        itCU = HuespedesAListar.begin();
                                        while(itCU!=HuespedesAListar.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                            if((*(*itCU).second).getEmail() == MailHuesped){
                                                existe = true;
                                                Hues = (*itCU).second;
                                            };
                                            itCU++;
                                        };
                                        while(existe == false && MailHuesped != "S"){
                                            cout<< "###ERROR### Ingrese un email correcto: "<< endl;
                                            cin >> MailHuesped;
                                            //CONTROLO QUE EL MAIL SEA CORRECTO
                                            existe= false;
                                            itCU = HuespedesAListar.begin();
                                            while(itCU!=HuespedesAListar.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                                if((*(*itCU).second).getEmail() == MailHuesped){
                                                    existe = true;
                                                    Hues = (*itCU).second;
                                                };
                                                itCU++;
                                            }
                                        }
                                        if(MailHuesped !="S"){//insertar el huesped
                                            ICR->IngresarHuespedEnReserva(Hues);
                                        }
                                    }
                                }
                                cout<< "¿Desea confirmar la reserva? : "<< endl;
                                cout<< "S/N: "<< endl;
                                cin >> MailHuesped;
                                if(MailHuesped == "S"){
                                    ICR->confirmarReserva();
                                }else if(MailHuesped == "N"){
                                    ICR->liberarMemoria();
                                }else{
                                    bool Finalizado = false;
                                    while(Finalizado == false){
                                        cout<< "###ERROR###"<< endl;
                                        cout<< "¿Desea confirmar la reserva? : "<< endl;
                                        cout<< "S/N: "<< endl;
                                        cin >> MailHuesped;
                                        Finalizado = (MailHuesped == "S" || MailHuesped == "S");
                                    }
                                    if(MailHuesped == "S"){
                                        ICR->confirmarReserva();
                                    }if(MailHuesped == "N"){
                                        ICR->liberarMemoria();
                                    }
                                }
                            
                            }else
                                cout<< "El hostal no posee habitaciones" << endl;
                            break;

                        };//case 1 | Realizar Reserva
                        
                        case 2:{//Consultar Reserva
                            map<string,DTHostal*> dthostales= (*ICH).obtenerHostales();
                            //elegir un hostal
                            map<string,DTHostal*>::iterator it;
                            if(dthostales.size()==0){
                                cout<<"No hay hostales ingresados.";
                            }else{
                                int cont=0;
                                for(it=dthostales.begin();it!=dthostales.end();it++){
                                    cont++;
                                    cout << cont << "- Hostal " << endl;
                                    cout << "   Nombre: " << (*it).second->getNombre() << endl;
                                    cout << "   Direccion: " << (*it).second->getDireccion() << endl;
                                    cout << "   Telefono: " << (*it).second->getTelefono() << endl;
                                    cout << endl;
                                }
                                int elegir;
                                do{
                                    cont = 1;
                                    it=dthostales.begin();
                                    cout << "Elija un hostal de acuerdo a su numero" << endl;
                                    cin >> elegir;
                                    if(elegir > dthostales.size() || elegir<=0){
                                        cout << "El numero elegido no pertenece a la lista" << endl;
                                    }else{
                                        while(cont<elegir){
                                            cont++;
                                            it++;
                                        }
                                    }
                                }while(elegir > dthostales.size() || elegir <=0);
                                //guarda DTHostal en memoria
                                (*ICH).setDatosHostal((*it).second);
                                //mostrar reservas del hostal
                                map<int,DTReserva*> dtreservas = (*ICH).obtenerReservasDeHostal();
                                map<int,DTReserva*>::iterator it2;
                                //Para toda reserva del DTHostal
                                //mostrarReserva
                                cout<< endl;
                                for(it2=dtreservas.begin();it2!=dtreservas.end();it2++){
                                    cout << "    Reserva" << endl;
                                    cout << "Fecha de Ingreso: " << (*it2).second->getCheckIn().getDia() << "/" << (*it2).second->getCheckIn().getMes() << "/" << (*it2).second->getCheckIn().getAnio() << " - " << (*it2).second->getCheckIn().getHora() <<":00" << endl;
                                    cout << "Fecha de Salida: " << (*it2).second->getCheckOut().getDia() << "/" << (*it2).second->getCheckOut().getMes() << "/" << (*it2).second->getCheckOut().getAnio() << " - " << (*it2).second->getCheckOut().getHora() <<":00" << endl;
                                     int aux2 = (int)(*(*it2).second).getEstado();
                                        switch(aux2){
                                            case 0 :{
                                                cout << "Estado: Abierto"<< endl;
                                            };
                                            break;
                                            case 1 :{
                                                cout << "Estado: Cerrado"<< endl;
                                            };
                                            break;
                                            case 2 : {
                                                cout << "Estado: Cancelado"<< endl;
                                            };
                                            break;
                                        }
                                    cout << "Costo: " << (*it2).second->getCosto() << endl;
                                    //obtener habitacion de la reserva
                                    DTHabitacion* dthab= (*ICR).obtenerHabitacionDeReserva((*it2).second);
                                    //obtenerNumeroDeHabitacion(habitacion)
                                    cout << "Numero de habitacion: " << dthab->getNumero() << endl;
                                    cout << endl;
                                    //Si la reserva es Grupal
                                    if(dynamic_cast<DTReservaGrupal*>((*it2).second)!=NULL){
                                        DTReservaGrupal* dtrg= static_cast<DTReservaGrupal*>((*it2).second);
                                        map<string,DTHuesped*> dthuespedes = (*ICR).obtenerHuespedesDeReserva(dtrg);
                                        map<string,DTHuesped*>::iterator it3;
                                        cont=0;
                                        for(it3=dthuespedes.begin();it3!=dthuespedes.end();it3++){
                                            cont++;
                                            cout << cont << "- Huesped: " << (*it3).second->getNombre() << endl;
                                        }
                                        //eliminar memoria map dthuesped
                                        for (it3=dthuespedes.begin () ; it3!=dthuespedes.end() ; it3++)
                                            delete (*it3).second;
                                        dthuespedes.clear();
                                    }
                                }
                                //eliminar memoria map dtreserva
                                for (it2=dtreservas.begin () ; it2!=dtreservas.end() ; it2++)
                                    delete (*it2).second;
                                dtreservas.clear();
                            }
                            //eliminar memoria map dthostal
                            /*for (it=dthostales.begin () ; it!=dthostales.end() ; it++)
                                delete (*it).second;*/
                            dthostales.clear();
                            //liberarMemoria del Hostal
                            //funciona comentado ¿perdera memoria? Si comento liberarMemoria de hostal o el for, el error se arregla
                            (*ICH).liberarMemoria();


                        }break;

                        case 3:{ //Baja de Reserva

                            DTHostal * dth = ElegirHostal();
                            DTHabitacion *dthab; // Puntero al DTHabitacion con el numero elegido en el hostal elegido
                            DTReserva* dtres;
                            int CodigoReserva;
                            existe= false;
                            ICH->setDatosHostal(dth);
                            map<int,DTReserva*> SDTReservas = (*ICH).obtenerReservasDeHostal();
                            if(!SDTReservas.empty()){
                                cout<<"-----------------Reservas-----------------"<< endl;
                                for(itDTR = SDTReservas.begin(); itDTR != SDTReservas.end(); itDTR++){
                                    cout << " Código: " << (*itDTR).second->getCodigo() << endl;
                                    cout << " Check In: " <<(*itDTR).second->getCheckIn().getDia() <<"/" <<(*itDTR).second->getCheckIn().getMes() <<"/"<<(*itDTR).second->getCheckIn().getAnio() << " - " << (*itDTR).second->getCheckIn().getHora() <<":00" << endl;
                                    cout << " Check Out: " <<(*itDTR).second->getCheckOut().getDia() <<"/" <<(*itDTR).second->getCheckOut().getMes() <<"/"<<(*itDTR).second->getCheckOut().getAnio() << " - " << (*itDTR).second->getCheckOut().getHora() <<":00" << endl;
                                    cout<<"........................................................"<< endl;
                                }
                                cout<<"Ingrese el código de la reserva : \n";
                                cin >> CodigoReserva;
                                existe =false;
                                itDTR = SDTReservas.begin();
                                while(itDTR!=SDTReservas.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                    if((*(*itDTR).second).getCodigo() == CodigoReserva){
                                        existe = true;
                                        dtres = (*itDTR).second;
                                    };
                                    itDTR++;
                                };
                                while(existe == false){
                                    cout<< "###ERROR### Ingrese un codigo correcto: "<< endl;
                                    cin >> CodigoReserva;
                                    //CONTROLO QUE EL CODIGO SEA CORRECTO
                                    existe= false;
                                    itDTR = SDTReservas.begin();
                                    while(itDTR!=SDTReservas.end() && !existe){ //controlo que el numero ingresado corresponda al codigo
                                        if((*(*itDTR).second).getCodigo() == CodigoReserva){
                                            existe = true;
                                            dtres = (*itDTR).second;
                                        };
                                        itDTR++;
                                    };
                                }
                                cout<< "Confirmar? : "<< endl;
                                cout<< "S/N: "<< endl;
                                cin >> MailHuesped;
                                if(MailHuesped == "S"){
                                    ICR->confirmarBaja(dth,CodigoReserva);
                                }else if(MailHuesped == "N"){
                                    ICH->setDatosHostal(NULL);
                                }else{
                                    bool Finalizado = false;
                                    while(Finalizado == false){
                                        cout<< "###ERROR###"<< endl;
                                        cout<< "¿Desea confirmar? : "<< endl;
                                        cout<< "S/N: "<< endl;
                                        cin >> MailHuesped;
                                        Finalizado = (MailHuesped == "S" || MailHuesped == "S");
                                    }
                                    if(MailHuesped == "S"){
                                        ICR->confirmarBaja(dth,CodigoReserva);
                                    }if(MailHuesped == "N"){
                                        ICH->setDatosHostal(NULL);
                                    }
                                }
                                break;
                            }else{
                                cout<< "El hostal no posee reservas" << endl;
                            }
                            break;

                        }
                        case 4:{ //Registrar Estadía

                            DTHostal * dth = ElegirHostal();
                            DTReserva *dtres;
                            map<string,DTHuesped*> HuespedesAListar = ICU->obtenerHuespedes();
                            map<string,DTHuesped*>::iterator itCU;
                            map<int,DTReserva*> SDTReservas;
                            int CodigoReserva;
                            existe= false;
                            cout<<"Ingrese el mail del huesped: \n";
                            cin >> MailHuesped;
                            itCU = HuespedesAListar.begin();
                            while(itCU!=HuespedesAListar.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                if((*(*itCU).second).getEmail() == MailHuesped){
                                    existe = true;
                                };
                                itCU++;
                            };
                            while(existe == false){
                                cout<< "###ERROR### Ingrese un email correcto: "<< endl;
                                cin >> MailHuesped;
                                //CONTROLO QUE EL MAIL SEA CORRECTO
                                existe= false;
                                itCU = HuespedesAListar.begin();
                                while(itCU!=HuespedesAListar.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                    if((*(*itCU).second).getEmail() == MailHuesped){
                                        existe = true;
                                    };
                                    itCU++;
                                };
                            }
                            SDTReservas = ICR->ListarReservasNoCanceladasDeHuesped(dth, MailHuesped);
                            cout<<"-----------------Reservas no canceladas-----------------"<< endl;
                            for(itDTR = SDTReservas.begin(); itDTR != SDTReservas.end(); itDTR++){
                                cout << " Código: " << (*itDTR).second->getCodigo() << endl;
                                cout << " Check In: " <<(*itDTR).second->getCheckIn().getDia() <<"/" <<(*itDTR).second->getCheckIn().getMes() <<"/"<<(*itDTR).second->getCheckIn().getAnio() << " - " << (*itDTR).second->getCheckIn().getHora() << endl;
                                cout << " Check Out: " <<(*itDTR).second->getCheckOut().getDia() <<"/" <<(*itDTR).second->getCheckOut().getMes() <<"/"<<(*itDTR).second->getCheckOut().getAnio() << " - " << (*itDTR).second->getCheckOut().getHora() << endl;
                                cout<<"........................................................"<< endl;
                            }
                            cout<<"Ingrese el código de reserva sobre la que se realizará la estadía: \n";
                            cin >> CodigoReserva;
                            existe =false;
                            itDTR = SDTReservas.begin();
                            while(itDTR!=SDTReservas.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                if((*(*itDTR).second).getCodigo() == CodigoReserva){
                                    existe = true;
                                    dtres = (*itDTR).second;
                                };
                                itDTR++;
                            };
                            while(existe == false){
                                cout<< "###ERROR### Ingrese un codigo correcto: "<< endl;
                                cin >> CodigoReserva;
                                //CONTROLO QUE EL CODIGO SEA CORRECTO
                                existe= false;
                                itDTR = SDTReservas.begin();
                                while(itDTR!=SDTReservas.end() && !existe){ //controlo que el numero ingresado corresponda al codigo
                                    if((*(*itDTR).second).getCodigo() == CodigoReserva){
                                        existe = true;
                                        dtres = (*itDTR).second;
                                    };
                                    itDTR++;
                                };
                            }
                            ICC->RegistrarEstadia(MailHuesped,CodigoReserva);
                            break;

                        }
                        case 5:{ //Consultar Estadia
                            map<string,DTHostal*> dthostales= (*ICH).obtenerHostales();
                            //elegir un hostal
                            map<string,DTHostal*>::iterator it = dthostales.begin();
                            if(dthostales.size()==0){
                                cout<<"No hay hostales ingresados.";
                            }else{
                                int cont=0;
                                for(it=dthostales.begin();it!=dthostales.end();it++){
                                    cont++;
                                    cout <<  "Hostal No. " << cont << endl;
                                    cout << "Nombre: " << (*it).second->getNombre() << endl;
                                    cout << "Direccion: " << (*it).second->getDireccion() << endl;
                                    cout << "Telefono: " << (*it).second->getTelefono() << endl;
                                    cout<< endl;
                                }
                                int elegir;
                                do{
                                    cont = 1;
                                    it=dthostales.begin();
                                    cout << "Elija un hostal de acuerdo a su numero" << endl;
                                    cin >> elegir;
                                    if(elegir > dthostales.size() || elegir<=0){
                                        cout << "El numero elegido no pertenece a la lista" << endl;
                                    }else{
                                        while(cont<elegir){
                                            cont++;
                                            it++;
                                        }
                                    }
                                }while(elegir > dthostales.size() || elegir <=0);
                                //guarda DTHostal en memoria
                                (*ICH).setDatosHostal((*it).second);
                                //obtenerEstadiasDeHostal
                                map<int,DTEstadia*> dtestadias=(*ICH).obtenerEstadiasDeHostal();
                                map<int,DTEstadia*>::iterator it1;
                                if(dtestadias.size()==0){
                                    cout<<"No hay estadias ingresadas." << endl;
                                }else{
                                    int cont=0;
                                    for(it1=dtestadias.begin();it1!=dtestadias.end();it1++){
                                        cont++;
                                        cout << "Estadia No. "<< cont << endl;
                                        cout << "Fecha de Ingreso: " << (*it1).second->getFechaEntrada().getDia() << "/" << (*it1).second->getFechaEntrada().getMes() << "/" << (*it1).second->getFechaEntrada().getAnio() << " - " << (*it1).second->getFechaEntrada().getHora() << ":00" << endl;
                                        if((*it1).second->getFechaSalida()!=NULL){
                                            cout << "Fecha de Salida: " << (*it1).second->getFechaSalida()->getDia() << "/" << (*it1).second->getFechaSalida()->getMes() << "/" << (*it1).second->getFechaSalida()->getAnio() <<  " - " << (*it1).second->getFechaSalida()->getHora() << ":00" << endl;
                                        }else{
                                            cout << "Aun esta sin finalizar." << endl;
                                        }
                                        cout << "Codigo: " << (*it1).second->getCodigo() << endl;
                                        cout << "Calificacion" << endl;
                                        DTCalificacion* dtc= (*ICC).obtenerCalificacion((*it1).second);
                                        if (dtc!=NULL){
                                            cout << "Comentario : " << dtc->getComentario() << endl;
                                            cout << "Puntaje : " << dtc->getPuntuacion() << endl;
                                        }
                                        else
                                            cout<< "La estadia no tiene calificacion" << endl;

                                        cout << endl;
                                        
                                    }
                                    //elegir la estadia
                                    do{
                                        cont = 1;
                                        it1=dtestadias.begin();
                                        cout << "Elija una estadia de acuerdo a su numero" << endl;
                                        cin >> elegir;
                                        if(elegir > dtestadias.size() || elegir<=0){
                                            cout << "El numero elegido no pertenece a la lista" << endl;
                                        }else{
                                            while(cont<elegir){
                                                cont++;
                                                it1++;
                                            }
                                        }
                                    }while(elegir > dtestadias.size() || elegir <=0);
                                    //Guardar en memoria una DTEstadia
                                    (*ICC).setDatosEstadia((*it1).second);
                                    //obtenerDatosEstadia
                                    DTDatosEstadia* dtde= (*ICR).obtenerDatosEstadia();
                                    //mostar el hostal
                                    cout << "Hostal " << endl;
                                    cout << "Nombre: " << (*ICH).getDatosHostal()->getNombre() << endl;
                                    cout << "Direccion: " << (*ICH).getDatosHostal()->getDireccion() << endl;
                                    cout << "Telefono: " << (*ICH).getDatosHostal()->getTelefono() << endl;
                                    //mostrar Huesped
                                    cout << "Huesped" << endl;
                                    cout << "Nombre : " << dtde->getHuespedDeEstadia()->getNombre() << endl;
                                    cout << "Email : " << dtde->getHuespedDeEstadia()->getEmail() << endl;
                                    if(dtde->getHuespedDeEstadia()->getEsFinger()==true){
                                        cout << "Es Finger." << endl;
                                    }else{
                                        cout << "No es Finger." << endl;
                                    }
                                    //mostrar Habitacion
                                    cout << "Habitacion " << endl;
                                    cout << "Numero: " << dtde->getHabitacionDeEstadia()->getNumero() << endl;
                                    cout << "Precio: " << dtde->getHabitacionDeEstadia()->getPrecio() << endl;
                                    cout << "Capacidad:" << dtde->getHabitacionDeEstadia()->getCapacidad() << endl;
                                    //mostrar chechIn
                                    cout << "Fecha de Ingreso: " << dtde->getFechaEntradaDeEstadia().getDia() << "/" << dtde->getFechaEntradaDeEstadia().getMes() << "/" << dtde->getFechaEntradaDeEstadia().getAnio() << " - " << dtde->getFechaEntradaDeEstadia().getHora() << ":00" << endl;
                                    //mostrar chechOut
                                    if ( dtde->getFechaSalidaDeEstadia() != NULL )
                                        cout << "Fecha de Salida: " << dtde->getFechaSalidaDeEstadia()->getDia() << "/" << dtde->getFechaSalidaDeEstadia()->getMes() << "/" << dtde->getFechaSalidaDeEstadia()->getAnio() << " - " << dtde->getFechaSalidaDeEstadia()->getHora() << ":00" << endl;
                                    else
                                        cout << "Aun esta sin finalizar" << endl;
                                    //Obtener Reserva de la estadia
                                    DTReserva* dtr= (*ICR).obtenerDTReservaDeEstadia((*ICC).getDatosEstadia());
                                    if(dynamic_cast<DTReservaGrupal*>(dtr)!=NULL){
                                        DTReservaGrupal* dtrg= static_cast<DTReservaGrupal*>(dtr);
                                        map<string,DTHuesped*> dthuespedes= (*ICR).obtenerHuespedesDeReserva(dtrg);
                                        map<string,DTHuesped*>::iterator it2= dthuespedes.begin();
                                        cont=0;
                                        do{
                                            if((*it2).second->getEsFinger()==true){
                                                cont++;
                                            }
                                            it2++;
                                        }while(cont<2 || it2!=dthuespedes.end());
                                        if(cont>=2){
                                            cout << "Tiene promocion." << endl;
                                        }else{
                                            cout << "No tiene promocion." << endl;
                                        }
                                    }else{
                                        cout << "No tiene promocion." << endl;
                                    }
                                    //obtenerCodigoDeEstadia
                                    cout << "Codigo: " << (*ICC).obtenerCodigoDeEstadia() << endl;
                                    //obtenerCalificacionDeEstadia
                                    DTCalificacion* dtc= (*ICC).obtenerCalificacionDeEstadia();
                                    //Si existe calificacion y el usuario quiere verla
                                    char confirmar;
                                    if(dtc!=NULL){
                                        cout << "Desea ver la calificacion? S/N" << endl;
                                        cin >> confirmar;
                                        //mostrar Calificacion
                                        if((char)toupper(confirmar) == 'S'){
                                            cout << "    Calificacion " << endl;
                                            cout << "Comentario: " << dtc->getComentario() << endl;
                                            cout << "Puntuacion: " << dtc->getPuntuacion() << endl;
                                            cout << endl;
                                        }
                                        DTRespuesta* dtr= (*ICC).obtenerRespuesta(dtc);
                                        if(dtr!=NULL){
                                            cout << "Desea ver la respuesta? S/N" << endl;
                                            cin >> confirmar;
                                            //mostrar Respuesta
                                            if((char)toupper(confirmar) == 'S'){
                                                cout << "    Respuesta " << endl;
                                                cout << "Comentario: " << dtr->getComentario() << endl;
                                                cout << endl;
                                            }
                                        }
                                    }
                                    cout << "Desea ver la reserva? S/N" << endl;
                                    cin >> confirmar;
                                    //mostar Reserva
                                    if((char)toupper(confirmar) == 'S'){
                                        DTReserva* dtres= (*ICR).obtenerDTReservaDeEstadia((*ICC).getDatosEstadia());
                                        cout << "Reserva: " << endl;
                                        cout << "Fecha de Ingreso: " << dtres->getCheckIn().getDia() << "/" << dtres->getCheckIn().getMes() << "/" << dtres->getCheckIn().getAnio() << " - " << dtres->getCheckIn().getHora() << ":00" << endl;
                                        cout << "Fecha de Salida: " << dtres->getCheckOut().getDia() << "/" << dtres->getCheckOut().getMes() << "/" << dtres->getCheckOut().getAnio() << " - " << dtres->getCheckOut().getHora() << ":00" << endl;
                                        cout << "Estado:" << dtres->getEstado() << endl;
                                        cout << "Costo:" << dtres->getCosto() << endl;
                                    }
                                }
                                //eliminar memoria map dtestadia
                                for (it1=dtestadias.begin () ; it1!=dtestadias.end() ; it1++)
                                    delete (*it1).second;
                                dtestadias.clear();
                            }
                            //eliminar memoria map dthostal
                            for (it=dthostales.begin () ; it!=dthostales.end() ; it++)
                                delete (*it).second;
                            dthostales.clear();
                            //liberarEstadia
                            (*ICC).liberarMemoria();
                            //liberarHostal
                            (*ICH).liberarMemoria();

                        }break;
                        case 6:{ //Finalizar Estadia
                            map<string,DTHostal*> hostales = (*ICH).obtenerHostales();

                            int i=1;
                            int eleccion;
                            string email;
                            map<string,DTHostal*>::iterator it;

                            cout << "Seleccione un hostal:" << endl;
                            for (it=hostales.begin() ; it!=hostales.end() ; it++){
                                cout << i << "- " << (*(*it).second).getNombre() << endl;
                                cout << "   " << (*(*it).second).getDireccion() << endl;
                                cout << "   " << (*(*it).second).getTelefono() << endl;
                                cout << endl;
                                i++;
                            }
                            cout << "Eleccion: " << endl;
                            cin >> eleccion;
                            it = hostales.begin();
                            for (i=1 ; i<eleccion ; i++){
                                it++;
                            }

                            cout << "Ingrese el email del huesped a finalizar la estadia:" << endl;
                            cin >> email;

                            (*ICR).finalizarEstadiaActiva(email, (*(*it).second).getNombre());

                            for (it=hostales.begin() ; it!=hostales.end() ; it++){
                                delete (*it).second;
                            }
                            hostales.clear();
                            
                        };
                        break;
                        case 7:{ //Volver
                            finSubMenu = true;
                        }break;
                        default:{}
                    }//switch(Opcion2){
                }//while(!finSubMenu)
            }//case 3 | Administracion de Reservas

            case 4:{ //Administracion de Calificaciones
                while(!finSubMenu){
                    cout << "Seleccione la operacion que desea realizar: \n";
                    cout << "1. Calificar Estadía \n";
                    cout << "2. Comentar Calificacion \n";
                    cout << "3. Volver \n";
                    cout << "-------------------------------\n";

                    cin >> OpcionAux;
                    Opcion2 = (int)OpcionAux - '0'; //Control en caso de que se ingrese char en vez de int

                    switch (Opcion2){
                        case 1:{ //Calificar Estadía

                        };
                        break;
                        case 2:{ //Comentar Calificacion

                        };
                        break;
                        case 3:{ //Volver
                            finSubMenu = true;
                        };
                        break;
                        default:{

                        }   

                    }; //switch (Opcion2)                    
                }//while(!finSubMenu)

            };
            break;
            //case 4 | Administracion de Calificaciones

            case 5:{ //Modificar Fecha de Sistema

                cout<<"Por favor, ingrese la fecha actual: \n";
                cout << "Día:" << endl;
                cin >> dia1;
                cout << "Mes:" << endl;
                cin >> mes1;
                cout << "Anio:" << endl;
                cin >> anio1;
                cout << "Hora:" << endl;
                cin >> hora1;

                Date fecha = Date(dia1,mes1,anio1,hora1); 

                (*fec).setFechaActual(fecha); 

                cout << "Fecha modificada a: " << dia1 << "/" << mes1 << "/" << anio1 << " - " << hora1 << ":00" << endl;
            };
            break;
            //case 5 | Modificar Fecha de Sistema
            case 6:{ //Cargar datos de prueba
                    
                    //Alta Empleados
                    
                    //E1
                    DTUsuario* dtu1 = new DTEmpleado("Emilia","emilia@mail.com","123",Recepcion); 
                    (*ICU).IngresarDatosUsuario(dtu1);
                    (*ICU).confirmarAltaUsuario();
                    (*ICU).liberarMemoria();

                    //E2
                    DTUsuario* dtu2 = new DTEmpleado("Leonardo","leo@mail.com","123",Recepcion);
                    (*ICU).IngresarDatosUsuario(dtu2);
                    (*ICU).confirmarAltaUsuario();
                    (*ICU).liberarMemoria();

                    //E3
                    DTUsuario* dtu3 = new DTEmpleado("Alina","alina@mail.com","123",Administracion);
                    (*ICU).IngresarDatosUsuario(dtu3);
                    (*ICU).confirmarAltaUsuario();
                    (*ICU).liberarMemoria();

                    //E4
                    DTUsuario* dtu4 = new DTEmpleado("Barliman","barli@mail.com","123",Recepcion); 
                    (*ICU).IngresarDatosUsuario(dtu4);
                    (*ICU).confirmarAltaUsuario();
                    (*ICU).liberarMemoria();

                    //Alta Huespedes
                    
                    //H1
                    DTUsuario* dthu1 = new DTHuesped("Sofia","sofia@mail.com","123",true); 
                    (*ICU).IngresarDatosUsuario(dthu1);
                    (*ICU).confirmarAltaUsuario();
                    (*ICU).liberarMemoria();

                    //H2
                    DTUsuario* dthu2 = new DTHuesped("Frodo","frodo@mail.com","123",true);
                    (*ICU).IngresarDatosUsuario(dthu2);
                    (*ICU).confirmarAltaUsuario();
                    (*ICU).liberarMemoria();

                    //H3
                    DTUsuario* dthu3 = new DTHuesped("Sam","sam@mail.com","123",false); 
                    (*ICU).IngresarDatosUsuario(dthu3);
                    (*ICU).confirmarAltaUsuario();
                    (*ICU).liberarMemoria();

                    //H4
                    DTUsuario* dthu4 = new DTHuesped("Merry","merry@mail.com","123",false); 
                    (*ICU).IngresarDatosUsuario(dthu4);
                    (*ICU).confirmarAltaUsuario();
                    (*ICU).liberarMemoria();

                    //H5
                    DTUsuario* dthu5 = new DTHuesped("Pippin","pippin@mail.com","123",false);
                    (*ICU).IngresarDatosUsuario(dthu5);
                    (*ICU).confirmarAltaUsuario();
                    (*ICU).liberarMemoria();

                    //H6
                    DTUsuario* dthu6 = new DTHuesped("Seba","seba@mail.com","123",true); 
                    (*ICU).IngresarDatosUsuario(dthu6);
                    (*ICU).confirmarAltaUsuario();
                    (*ICU).liberarMemoria();

                    //Alta Hostales
                    //HO1                    
                    
                    DTHostal* pdth1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111",0);
                    (*ICH).IngresarDatosHostal(pdth1);
                    (*ICH).confirmarAltaHostal();
                    (*ICH).liberarMemoria();

                    //HO2
                    DTHostal* pdth2 = new DTHostal("Mochileros","Rambla Costanera 333, Rocha","42579512",0);
                    (*ICH).IngresarDatosHostal(pdth2);
                    (*ICH).confirmarAltaHostal();
                    (*ICH).liberarMemoria();

                    //HO3                    
                    DTHostal* pdth3 = new DTHostal("El Pony Pisador","Bree (preguntar por Gandalf)","000",0);
                    (*ICH).IngresarDatosHostal(pdth3);
                    (*ICH).confirmarAltaHostal();
                    (*ICH).liberarMemoria();

                    //HO4
                    DTHostal* pdth4 = new DTHostal("Altos de Fing","Av del Toro 1424","099892992",0);
                    (*ICH).IngresarDatosHostal(pdth4);
                    (*ICH).confirmarAltaHostal();
                    (*ICH).liberarMemoria();

                    //HO5
                    DTHostal* pdth5 = new DTHostal("Caverna Lujosa","Amaya 2515","233233235",0);
                    (*ICH).IngresarDatosHostal(pdth5);
                    (*ICH).confirmarAltaHostal();
                    (*ICH).liberarMemoria();

                    //HO1 - Habitaciones
                    //HA1
                    
                    pdth1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111",0);
                    (*ICH).IngresarDatosHostal(pdth1);

                    DTHabitacion* pdthab1 = new DTHabitacion(1,40,2);
                    (*ICH).IngresarDatosHab(pdthab1);
                    (*ICH).confirmarAltaHabitacion(); 
                    (*ICH).liberarMemoria();

                    //HA2

                    pdth1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111",0);
                    (*ICH).IngresarDatosHostal(pdth1);

                    DTHabitacion* pdthab2 = new DTHabitacion(2,10,7);
                    (*ICH).IngresarDatosHab(pdthab2);
                    (*ICH).confirmarAltaHabitacion();
                    (*ICH).liberarMemoria();

                    //HA3

                    pdth1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111",0);
                    (*ICH).IngresarDatosHostal(pdth1);

                    DTHabitacion* pdthab3 = new DTHabitacion(3,30,3);
                    (*ICH).IngresarDatosHab(pdthab3);
                    (*ICH).confirmarAltaHabitacion();
                    (*ICH).liberarMemoria();


                    //HA4

                    pdth1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111",0);
                    (*ICH).IngresarDatosHostal(pdth1);

                    DTHabitacion* pdthab4 = new DTHabitacion(4,5,12);
                    (*ICH).IngresarDatosHab(pdthab4);
                    (*ICH).confirmarAltaHabitacion();
                    (*ICH).liberarMemoria();

                    //H55
                    
                    pdth5 = new DTHostal("Caverna Lujosa","Amaya 2515","233233235",0);
                    (*ICH).IngresarDatosHostal(pdth5);

                    DTHabitacion* pdthab5 = new DTHabitacion(1,3,2);
                    (*ICH).IngresarDatosHab(pdthab5);
                    (*ICH).confirmarAltaHabitacion();
                    (*ICH).liberarMemoria();

                
                    //HA6

                    pdth3 = new DTHostal("El Pony Pisador","Bree (preguntar por Gandalf)","000",0);
                    (*ICH).IngresarDatosHostal(pdth3);

                    DTHabitacion* pdthab6 = new DTHabitacion(1,9,5);                   
                    (*ICH).IngresarDatosHab(pdthab6);
                    (*ICH).confirmarAltaHabitacion();
                    (*ICH).liberarMemoria();

                    //H01 - Reservas
                    //R1 - HA1

                    dthu1 = new DTHuesped("Sofia","sofia@mail.com","123",true); 
                    DTHuesped* dthue1 = static_cast<DTHuesped*>(dthu1);
                    (*ICR).DesignarPropietarioDeReserva(dthue1);

                    pdthab1 = new DTHabitacion(1,40,2);
                    (*ICH).IngresarDatosHab(pdthab1);

                    pdth1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111",0);

                    Date ChIn1(01,05,22,14);
                    Date ChOut1(10,05,22,10); 
                    (*ICR).ingresarDatosReserva(pdth1,ChIn1,ChOut1);
                    (*ICH).setDatosHabitacion(pdthab1);
                    (*ICR).confirmarReserva();

                    //HO1 - Reservas
                    //R3 - HA3F
                    
                    dthu2 = new DTHuesped("Frodo","frodo@mail.com","123",true);
                    DTHuesped* dthue2 = static_cast<DTHuesped*>(dthu2);
                    (*ICR).DesignarPropietarioDeReserva(dthue2);

                    dthu3 = new DTHuesped("Sam","sam@mail.com","123",false); 
                    DTHuesped* dthue3 = static_cast<DTHuesped*>(dthu3);
                    (*ICR).IngresarHuespedEnReserva(dthue3);

                    dthu4 = new DTHuesped("Merry","merry@mail.com","123",false);
                    DTHuesped* dthue4 = static_cast<DTHuesped*>(dthu4);
                    (*ICR).IngresarHuespedEnReserva(dthue4);

                    dthu5 = new DTHuesped("Pippin","pippin@mail.com","123",false);
                    DTHuesped* dthue5 = static_cast<DTHuesped*>(dthu5);
                    (*ICR).IngresarHuespedEnReserva(dthue5);

                    pdthab6 = new DTHabitacion(1,9,5);                   
                    (*ICH).IngresarDatosHab(pdthab6);

                    pdth3 = new DTHostal("El Pony Pisador","Bree (preguntar por Gandalf)","000",0);

                    
                    Date ChIn2(04,01,01,20);
                    Date ChOut2(05,01,01,2);

                    (*ICR).ingresarDatosReserva(pdth3,ChIn2,ChOut2);
                    (*ICH).setDatosHabitacion(pdthab6);                 
                    (*ICR).confirmarReserva();

                    //HO3 - Reservas
                    //R2 - HA6

                    dthu1 = new DTHuesped("Sofia","sofia@mail.com","123",true); 
                    dthue1 = static_cast<DTHuesped*>(dthu1);
                    (*ICR).DesignarPropietarioDeReserva(dthue1);

                    pdthab3 = new DTHabitacion(3,30,3);
                    (*ICH).IngresarDatosHab(pdthab3);

                    pdth1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111",0);

                    Date ChIn3(07,06,22,14);
                    Date ChOut3(30,06,22,11);
                    (*ICR).ingresarDatosReserva(pdth1,ChIn3,ChOut3);                                  
                    (*ICR).confirmarReserva(); 

                    //HO5 - Reserva
                    //R4
                    
                    dthu6 = new DTHuesped("Seba","seba@mail.com","123",true); 
                    DTHuesped* dthue6 = static_cast<DTHuesped*>(dthu6);
                    (*ICR).DesignarPropietarioDeReserva(dthue6);
                    
                    pdthab5 = new DTHabitacion(1,3,2);
                    (*ICH).IngresarDatosHab(pdthab5);

                    pdth5 = new DTHostal("Caverna Lujosa","Amaya 2515","233233235",0);

                    Date ChIn4(10,06,22,14);
                    Date ChOut4(30,06,22,11);
                    (*ICR).ingresarDatosReserva(pdth5,ChIn4,ChOut4);           
                    (*ICR).confirmarReserva();

                    //HO1 - Empleados

                    pdth1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111",0);
                    (*ICH).IngresarDatosHostal(pdth1);

                    (*ICU).AsignarEmpleadoAHostal("emilia@mail.com");

                    (*ICH).liberarMemoria();
                    
                    //HO2 - Empleados

                    pdth2 = new DTHostal("Mochileros","Rambla Costanera 333, Rocha","42579512",0);
                    (*ICH).IngresarDatosHostal(pdth2);

                    (*ICU).AsignarEmpleadoAHostal("leo@mail.com");
                    (*ICU).AsignarEmpleadoAHostal("alina@mail.com");

                    (*ICH).liberarMemoria(); 

                    //HO3 - Empleados

                    pdth3 = new DTHostal("El Pony Pisador","Bree (preguntar por Gandalf)","000",0);
                    (*ICH).IngresarDatosHostal(pdth3);

                    (*ICU).AsignarEmpleadoAHostal("barli@mail.com");

                    (*ICH).liberarMemoria();  

                    

                    //Estadías
                    //ES1

                    Date d1I = Date(01,05,22,18);
                    Date d1O = Date(10,05,22,9);

                    string nmbrHstl1="La posada del finger";
                    int codRsv1 = 1;      

                    (*fec).setFechaActual(d1I);
                    (*ICC).RegistrarEstadia("sofia@mail.com", codRsv1);

                    (*fec).setFechaActual(d1O);
                    (*ICR).finalizarEstadiaActiva("sofia@mail.com", nmbrHstl1);
                    
                    //ES2 
                    //R2 - HU2

     
                    Date d2I = Date(04,01,01,21);
                    Date d2O = Date(05,01,01,2);

                    string nmbrHstl2 = "El Pony Pisador";
                    int codRsv2=2;
                    
                    (*fec).setFechaActual(d2I);
                    (*ICC).RegistrarEstadia("frodo@mail.com",codRsv2);
                    (*ICC).RegistrarEstadia("sam@mail.com",codRsv2);
                    (*ICC).RegistrarEstadia("merry@mail.com",codRsv2);
                    (*ICC).RegistrarEstadia("pippin@mail.com",codRsv2);

                    (*fec).setFechaActual(d2O);
                    (*ICR).finalizarEstadiaActiva("frodo@mail.com", nmbrHstl2);  


                    //ES3
                    //R2 - HU3
                                       
                    Date d3I = Date(07,06,22,18);
                    Date d3O = Date(15,06,22,22);

                    string nmbrHstl3 = "Caverna Lujosa";
                    int codRsv3=4;
                    
                    (*fec).setFechaActual(d3I);
                    (*ICC).RegistrarEstadia("seba@mail.com",codRsv3);

                    (*fec).setFechaActual(d3O);
                    (*ICR).finalizarEstadiaActiva("seba@mail.com", nmbrHstl3);  


                    //Calificar Estadia

                    //C1
                    //ES1

                    Date fechaCal1 = Date(11,05,22,18);
                    (*fec).setFechaActual(fechaCal1);

                    pdth1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111",0);
                    (*ICH).IngresarDatosHostal(pdth1);

                    Comentario = "Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba,cayendo. No vuelvo";
                    nota = 3;

                    (*ICC).agregarCalificacion("sofia@mail.com",Comentario, nota,1);
                    
                    (*ICH).liberarMemoria();

                    //C2
                    //ES2

                    Date fechaCal2 = Date(5,01,01,3);
                    (*fec).setFechaActual(fechaCal2);

                    pdth3 = new DTHostal("El Pony Pisador","Bree (preguntar por Gandalf)","000",0);
                    (*ICH).IngresarDatosHostal(pdth3);

                    Comentario = "Se pone peligroso de noche, no recomiendo. Ademas no hay caja fuerte para guardar anillos.";
                    nota = 2;

                    (*ICC).agregarCalificacion("frodo@mail.com",Comentario, nota,2);

                    (*ICH).liberarMemoria();

                    //C3
                    //ES6

                    Date fechaCal3 = Date(15,06,22,23);
                    (*fec).setFechaActual(fechaCal3);

                    pdth5 = new DTHostal("Caverna Lujosa","Amaya 2515","233233235",0);
                    (*ICH).IngresarDatosHostal(pdth5);

                    Comentario = "Habia pulgas en la habitación.Que lugar más mamarracho!!";
                    nota = 1;

                    (*ICC).agregarCalificacion("seba@mail.com",Comentario, nota,6);

                    (*ICH).liberarMemoria();

                    //Comentar Calificacion
                   
                    Comentario = "Desapareció y se fue sin pagar.";
                    (*ICC).ingresarRespuesta(Comentario,2);
                    
                };
                break;
                //case 6 | Cargar datos de prueba
            case 7:{ //Salir
                finalizar = true;
                break;
            }
            //case 7 | Salir
            default:{
                cout << "Por favor, ingrese una opcion entre 1 y 6.\n";
                break;
            }
        }//switch(Opcion1)
    }//while (!finalizar)
    cout<<"Gracias por operar con nosotros, vuelva pronto! \n";
}//int main()