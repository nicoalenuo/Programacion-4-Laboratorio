#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>
#include <typeinfo>

#include "../include/fabrica.h"

//funcion auxiliar
DTHostal* ElegirHostal(){
	cout<< "Por favor, seleccione de la siguiente lista el número del hostal al que desea asignarle un nuevo empleado: \n";
	fabrica* f = fabrica::getInstance();
    IControladorHostal *ICH = (*f).getIControladorHostal();
    map<string,DTHostal*> listaHostales = (*ICH).obtenerHostales();
	map<string,DTHostal*>::iterator it;
    int cont = 1;
	for(it=listaHostales.begin(); it!=listaHostales.end(); it++){
		std::cout << cont <<". Nombre: " << ((*it).second)->getNombre() << std::endl;
        cont++;
	}
	bool existeH = false;
	int numHostal;	
	cin>>numHostal;
	while(numHostal>cont or numHostal==0){ //verificar que el nombre coincida con un hostal, si coincide existeH = true
		cout<<"El número ingresado no es correcto, por favor ingréselo nuevamente: \n";
        cont = 1;
	    for(it=listaHostales.begin(); it!=listaHostales.end(); it++){
		    std::cout << cont <<". Nombre: " << ((*it).second)->getNombre() << std::endl;
            cont++;
	    }
        cin>>numHostal;
    };
    cont = 1;
    it = listaHostales.begin();
    while(cont<numHostal){
        it++;
        cont++;
    };
    return (*it).second;	
};

int main(){
    //----Declaración de variables----//
    char OpcionAux, esFingerAux, confirmarAlta;
    int Opcion1, Opcion2, num, capacidad, dia1, mes1, anio1, dia2, mes2, anio2, CargoAux, ind;
    float precio;
    string hostalSel, NombreHos, DirHos, TelHos, Nombre, pass, email;
    Cargo cargo;
    bool existe, finalizar, esFinger, cargoCorrecto, aux;
    finalizar = false;
    //-----------------------//
    while (!finalizar){
            cout << "Seleccione la operación que desea realizar: \n";
            cout << "1. Administración de Hostales \n";
            cout << "2. Administración de Usuarios \n";
            cout << "3. Administración de Reservas \n";
            cout << "4. Calificaciones \n";
            cout << "5. Modificar Fecha de Sistema \n";
            cout << "6. Salir \n";
            cout << "-------------------------------\n";
            
            cin >> OpcionAux;
            Opcion1 = (int)OpcionAux - '0'; //Control en caso de que se ingrese char en vez de int

            switch(Opcion1){

                case 1: //Administración de Hostales
                    cout << "Seleccione la operación que desea realizar: \n";
                    cout << "1. Alta Hostal \n";
                    cout << "2. Alta Habitación \n";
                    cout << "3. Consultar Hostal \n";
                    cout << "4. Consultar Top 3 Hostales \n";
                    cout << "5. Volver \n";
                    cout << "-------------------------------\n";

                    cin >> OpcionAux;
                    Opcion2 = (int)OpcionAux - '0'; //Control en caso de que se ingrese char en vez de int
                    switch(Opcion2){
                        case 1: { //Alta Hostal
                            fabrica* f = fabrica::getInstance();
                            IControladorHostal *ICH = (*f).getIControladorHostal();
                            
                            cout << "Por favor, ingrese los siguientes datos: \n";
                            cout << "Nombre del hostal: ";
                            cin.ignore();
                            getline(cin, NombreHos);
                            cout << "Dirección del hostal: ";
                            cin.ignore();
                            getline(cin, DirHos);
                            cout << "Teléfono del hostal: ";
                            cin.ignore();
                            getline(cin, TelHos);
                            DTHostal dth(NombreHos,DirHos,TelHos,0);
                            DTHostal* pdth = &dth;
                            
                            try{
                                map<string, hostal*> hostales = (*ICH).getHostales();
                                map<string,hostal*>::iterator it;
                                existe = true;
                                while (it!=hostales.begin() && !existe){
                                    if (((*it).second)->getNombre() == NombreHos)
                                        throw std::invalid_argument("");
                                    it++;
                                    }
                                    if (it == hostales.end())
                                        (*ICH).IngresarDatosHostal(pdth);
                                }
                                catch(invalid_argument &e){
                                    
                                    (*ICH).liberarDatosHostal();
                                    cout << "Ya existe un hostal de nombre " << NombreHos << endl;
                                }
                        }//case 1 | Alta Hostal

                        case 2:{ //Alta Habitación
                            DTHostal* dth = ElegirHostal();
                            fabrica* f = fabrica::getInstance();
                            IControladorHostal *ICH = (*f).getIControladorHostal();
                            (*ICH).IngresarDatosHostal(dth);
                            cout << "Por favor, ingrese los siguientes datos: \n";
                            cout << "Numero de habitación: ";
                            cin >> num;
                            //controlo que no exista ese numero de habitacion en el hostal seleccionado
                            cout << "Precio de la habitación: ";
                            cin >> precio;
                            cout << "Capacidad de la habitación: ";
                            cin >> capacidad;
                            DTHabitacion dthab(num,precio,capacidad);
                            DTHabitacion* pdthab = &dthab;
                            (*ICH).IngresarDatosHab(pdthab);
                            confirmarAlta = 'A';
                            while((char) toupper(confirmarAlta) != 'S' && (char) toupper(confirmarAlta) != 'N'){
                                cout<<"¿Desea confirmar el alta? S / N \n";
                                cin >> confirmarAlta; 
                                if ((char) toupper(confirmarAlta) == 'S'){
                                    (*ICH).confirmarAltaHabitacion();
                                    
                                }else{
                                    if ((char) toupper(confirmarAlta) == 'N')
                                        (*ICH).cancelarAltaHabitacion();
                                    else
                                        cout << "La opción ingresada no es válida.\n";
                                };
                            };
                            (*ICH).liberarDatosHostal();
                            
                        }// case 2 | Alta Habitación

                        case 3:{ // Consultar Hostal
                            DTHostal* dth = ElegirHostal();
                            fabrica* f = fabrica::getInstance();
                            IControladorHostal *ICH = (*f).getIControladorHostal();
                            
                        }// case 3 | Consultar Hostal
                        /*case 4: {//Consultar Top 3 Hostales
                            int i;
                            fabrica * f = fabrica::getInstance();
                            IControladorHostal *CHostal = (*f).getIControladorHostal();
                            map<string,DTHostal*> top3 = (*CHostal).obtenerTop3Hostales();
                            map<string,DTHostal*>::iterator it;
                            for (it=top3.begin(); it!=top3.end(); it++){
                                i++;
                                std::cout << "No. " << i << ": \n" << std::endl;
                                std::cout << "Nombre : " << (*(*it).second).getNombre() << std::endl;
                                std::cout << "Dirección : " << (*(*it).second).getDireccion() << std::endl;
                                std::cout << "Teléfono : " << (*(*it).second).getTelefono() << std::endl;
                            }
                        }//case 4 | Consultar Top 3 Hostales

                        case 5:{} //Volver a menú 1
                        default:{
                            cout<< "Por favor, seleccione una opción entre 1 y 5. \n";
                        }
                    */
                    }; //switch(Opcion2)


                case 2: //Administración de Usuarios
                    cout << "Seleccione la operación que desea realizar: \n";
                    cout << "1. Alta Empleado \n";
                    cout << "2. Alta Huesped \n";
                    cout << "3. Asignar Empleado a Hostal \n";
                    cout << "4. Consultar Usuario \n";
                    cout << "5. Suscribir a Notificaciones \n";
                    cout << "6. Consultar Notificaciones \n";
                    cout << "7. Eliminar Suscripción \n";
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
                            while(!cargoCorrecto){
                                cout<<"1. Administración \n";                 
                                cout<<"2. Limpieza \n";
                                cout<<"3. Recepción \n";
                                cout<<"4. Infraestructura \n";      
                                cin>>CargoAux;                                
                                switch (CargoAux){
                                    case 1:{ 
                                        cargo = Administracion;
                                        cargoCorrecto = true;
                                    }
                                    case 2:{ 
                                        cargo = Limpieza;
                                        cargoCorrecto = true;
                                    }
                                    case 3:{ 
                                        cargo = Recepcion;
                                        cargoCorrecto = true;
                                    }
                                    case 4:{ 
                                        cargo = Infraestructura;
                                        cargoCorrecto = true;
                                    }
                                    default:{ 
                                        cout<<"Por favor, ingrese una opción válida: \n";
                                        cin>>CargoAux;
                                    }
                                }//switch (CargoAux)
                            }//while(!cargoCorrecto)
                          
                            cout<<"Mail: \n";
                            cin.ignore();
                            getline(cin, email);
                            fabrica* f = fabrica::getInstance();
                            IControladorUsuario *ICU = (*f).getIControladorUsuario();
                            existe=false;
                            
                            while(!existe){
                                existe = (*ICU).IngresarEmail(email);
                                if (!existe){
                                    cout<<"El email ingresado ya existe, por favor ingrese otro. \n" ;
                                    cin.ignore();
                                    getline(cin, email);
                                    
                                }
                            };
                            DTEmpleado e(Nombre,email,pass,cargo); 
                            DTEmpleado* dte = &e;
                            DTUsuario* dtu = dynamic_cast<DTUsuario*>(dte);
                            (*ICU).IngresarDatosUsuario(dtu);
                            (*ICU).confirmarAltaUsuario();
                            cout<<"Se confirmó el alta de Empleado.\n";
                        }
                        case 2: {//Alta Huesped
                            
                            cout<<"Por favor, ingrese los siguientes datos: \n";
                            cout<<"Nombre: \n";
                            cin.ignore();
                            getline(cin, Nombre);
                            cout<<"Contraseña: \n";
                            cin.ignore();
                            getline(cin, pass);
                            esFingerAux = 'A';
                            while((char) toupper(esFingerAux) != 'S' && (char) toupper(esFingerAux) != 'N'){
                                cout << "Si el huesped es Finger digite 'S', de lo contrario, digite 'N' \n";
                                cin >> esFingerAux; 
                                if ((char) toupper(esFingerAux) == 'S'){
                                    esFinger = true;
                                }else{
                                    if ((char) toupper(esFingerAux) == 'N')
                                        esFinger = false;
                                    else
                                        cout << "La opción ingresada no es válida.\n";
                                };
                            };
                            cout<<"Email:\n";
                            cin.ignore();
                            getline(cin, email);
                            fabrica* f = fabrica::getInstance();
                            IControladorUsuario *ICU = (*f).getIControladorUsuario();
                            existe=false;                            
                            while(!existe){
                                existe = (*ICU).IngresarEmail(email);
                                if (!existe){
                                    cout<<"El email ingresado ya existe, por favor ingrese otro. \n";
                                    cin.ignore();
                                    getline(cin, email);
                                }
                            };
                            DTHuesped hu(Nombre,email,pass,cargo);
                            DTHuesped* dth = &hu;
                            DTUsuario* dtu = dynamic_cast<DTUsuario*>(dth);
                            (*ICU).IngresarDatosUsuario(dtu);
                            (*ICU).confirmarAltaUsuario();
                            cout<<"Se confirmó el alta de Huesped.\n";

                        }//case 2 | Alta Huesped

                        case 3: {//Asignar Empleado a Hostal
                            DTHostal * dth = ElegirHostal();
                            fabrica* f = fabrica::getInstance();
                            IControladorHostal * ICH = (*f).getIControladorHostal();
                            (*ICH).IngresarDatosHostal(dth);
                            IControladorUsuario * ICU = (*f).getIControladorUsuario();
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
                                    std::cout<<ind<<". Nombre: "<<((*it).second)->getNombre() <<", Mail: "<<((*it).second)->getMail()<< std::endl;
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
                            (*ICU).AsignarEmpleadoAHostal((*it).second->getMail());
                            (*ICH).FinalizarAsignacionDeEmpleados();	
                        }
                        /*case 4:{ //Consultar Usuario
                            DTHostal * dth = ElegirHostal();
                            fabrica* f = fabrica::getInstance();
                            IControladorHostal * ICH = (*f).getIControladorHostal();
                            (*ICH).IngresarDatosHostal(dth);

                            IControladorUsuario *ICU = (*f).getIControladorUsuario();
                            map<string,DTUsuario*> us = (*ICU).obtenerUsuarios();
                            if(us.size()==0){
                                cout<<"No hay usuarios ingresados.";
                            }else{
                                map<string,DTUsuario*>::iterator it;
                                existe = false;
                                aux = false;
                                while(!existe){
                                    if(aux){
                                        cout<<"El número ingresado no es correcto. \n";
                                    }
                                    ind = 1;
                                    cout<<"Seleccione el número correspondiente al usuario que desea seleccionar de la siguiente lista: \n";
                                    for(it=us.begin(); it!=us.end(); it++){
                                        std::cout<<ind<<". Nombre: "<<((*it).second)->getNombre() <<", Mail: "<<((*it).second)->getMail()<< std::endl;
                                        ind++;
                                    }
                                    cin>>num;
                                    if(num>ind || num==0){
                                        existe = false;
                                        aux = true;
                                    };
                                };
                                ind = 1;
                                it = us.begin();
                                while(ind<num){
                                    it++;
                                    ind++;
                                };

                                
                                //obtenerNombreUsuario
                                //obtenerEmailUsuario
                                //obtenerHuespedConEmail (mostrar esFinger) / obtenerEmpleadoConEmail (mostrar cargo y hostal)
                                    
                            };// if(us.size()==0)
                                
                        }
                        case 5:{ //Suscribir a Notificaciones

                        }
                        case 6:{ //Consultar Notificaciones

                        }
                        case 7:{ //Eliminar Suscripción

                        }
                        case 8:{ //Volver

                        }
                        default:{

                        }*/

                    }

                /*case 3: //Administración de Reservas 
                    cout << "Seleccione la operación que desea realizar: \n";
                    cout << "1. Realizar Reserva \n";
                    cout << "2. Consultar Reserva \n";
                    cout << "3. Baja de Reserva \n";
                    cout << "4. Registrar Estadía \n";
                    cout << "5. Consultar Estadía \n";
                    cout << "6. Finalizar Estadía \n";
                    cout << "7. Volver \n";
                    cout << "-------------------------------\n";

                    cin >> OpcionAux;
                    Opcion2 = (int)OpcionAux - '0'; //Control en caso de que se ingrese char en vez de int

                    switch(Opcion2){

                        case 1:{ //Realizar Reserva
                            DTHostal * dth = ElegirHostal();
                            fabrica* f = fabrica::getInstance();
                            IControladorHostal * ICH = (*f).getIControladorHostal();
                            
                            cout<<"Por favor, ingrese la fecha de CheckIn: \n";
                            cout << "Día:";
                            cin >> dia1;
                            cout << "Mes:";
                            cin >> mes1;
                            cout << "Anio:";
                            cin >> anio1;
                            Date ChIn(dia1,mes1,anio1); //DTFecha CheckIn
                            cout<<"Por favor, ingrese la fecha de CheckOut: \n";
                            cout << "Día:";
                            cin >> dia2;
                            cout << "Mes:";
                            cin >> mes2;
                            cout << "Anio:";
                            cin >> anio2;
                            Date ChOut(dia2,mes2,anio2); //DTFecha CheckIn
                            IControladorReserva *CR = (*f).getIControladorReserva();
                            (*CR).ingresarDatosReserva(dth,ChIn,ChOut);
                            map<int,DTHabitacion*> habs = (*CR).obtenerHabitacionesDisponibles();
                            map<int,DTHabitacion*>::iterator j;
                            cout<<"Por favor, seleccione el número de la habitación que desea reservar: \n";
                            for(j=habs.begin(); j!=habs.end(); j++){
                                std::cout<<"Numero: " << ((*(*j).second)).getNumero() << std::endl;
                                std::cout<<"Precio: " << ((*(*j).second)).getPrecio() << std::endl;
                                std::cout<<"Capacidad: " << ((*(*j).second)).getCapacidad() << std::endl;
                                cout<<"...............................................";
                            };
                           
                            
                            cin>>num;
                            //controlar que sea un int
                            bool existe=false;
                            j = habs.begin();
                            while(j!=habs.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                if(((*j).second)->getNumero() == num){
                                    existe = true;
                                };
                                j++;
                            };
                            while(!existe){ //si se ingreso un numero incorrecto, muestro las hab y pido reingresar
                                cout<<"El número de habitación ingresado no corresponde a una habitación disponible.\n";
                                for(j=habs.begin(); j!=habs.end(); j++){
                                    std::cout<<"Numero: " << (*(*j).second).getNumero() <<std::endl;
                                    std::cout<<"Precio: " << (*(*j).second).getPrecio() <<std::endl;
                                    std::cout<<"Capacidad: " << (*(*j).second).getCapacidad() <<std::endl;
                                    cout<<"...............................................";
                                };
                                cout<< "Por favor, ingrese un número de habitación de la lista: \n";
                                
                                cin>>num;
                                //controlar que sea un int
                                
                                j = habs.begin();
                                while(j!=habs.end() && !existe){ //controlo que el numero ingresado corresponda a una habitacion disponible
                                    if((*(*j).second).getNumero() == num){
                                        existe = true;
                                    };
                                    j++;
                                };
                            };//while(!existe)
                            DTHabitacion *dthab; // Puntero al DTHabitacion con el numero elegido en el hostal elegido
                            IControladorReserva *ICR = (*f).getIControladorReserva();
                            (*ICR).EscogerHabitacion(dthab);

                        }
                        case 2:{ //Consultar Reserva

                        }
                        case 3:{ // Baja de Reserva
                    
                        }  
                        case 4:{ //Registrar Estadía

                        }
                        case 5:{ //Consultar Estadía

                        }
                        case 6:{ //Finalizar Estadía

                        }
                        case 7:{ //Volver

                        }
                        default:{

                        }
                    }
                                         

                case 4: //Calificaciones
                    cout << "Seleccione la operación que desea realizar: \n";
                    cout << "1. Calificar Estadía \n";
                    cout << "2. Comentar Calificación \n";
                    cout << "3. Registrar Estadía \n";
                    cout << "4. Consultar Estadía \n";
                    cout << "5. Volver \n";
                    cout << "-------------------------------\n";

                    cin >> OpcionAux;
                    Opcion2 = (int)OpcionAux - '0'; //Control en caso de que se ingrese char en vez de int

                    switch (Opcion2){
                        case 1:{ //Calificar Estadía

                        }
                        case 2:{ //Comentar Calificación

                        }
                        case 3:{ //Registrar Estadía

                        }
                        case 4:{ //Consultar Estadía

                        }
                        case 5:{ //Volver

                        }
                        default:{

                        }
                    }
                    

                case 5: //Modificar fecha del sistema

                case 6: //Salir
                    finalizar = true;
                    break;

                default:{
                cout << "Por favor, ingrese una opción entre 1 y 6.\n";
                break;
                }*/			
            }
      
    }; //while (!finalizar)
    return 0;
}//int main()
