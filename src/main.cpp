#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>
#include <typeinfo>

#include "../include/fabrica.h"

//funcion auxiliar
DTHostal* ElegirHostal(){
	cout<< "Por favor, seleccione de la siguiente lista el numero del hostal al que desea asignarle un nuevo empleado: \n";
	fabrica* f = fabrica::getInstance();
    IControladorHostal *ICH = (*f).getIControladorHostal();
    map<string,DTHostal*> listaHostales = (*ICH).obtenerHostales();
	map<string,DTHostal*>::iterator it;
    int cont = 0;
	for(it=listaHostales.begin(); it!=listaHostales.end(); it++){
		cont++;
        std::cout << cont <<". Nombre: " << ((*it).second)->getNombre() << std::endl;
        
	}
	bool existeH = false;
	int numHostal;	
	cin>>numHostal;
	while(numHostal>cont or numHostal==0){ //verificar que el nombre coincida con un hostal, si coincide existeH = true
		cout<<"El número ingresado no es correcto, por favor ingreselo nuevamente: \n";
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
    //----Declaracion de variables----//
    char OpcionAux, esFingerAux, confirmarAlta;
    int nota, Opcion1, Opcion2, num, capacidad, dia1, mes1, anio1, dia2, mes2, anio2, CargoAux, ind, codReserva;
    float precio;
    string hostalSel, NombreHos, DirHos, TelHos, Nombre, pass, email, Comentario;
    Cargo cargo;
    bool existe, finalizar, finSubMenu, esFinger, cargoCorrecto, aux;
    map<int,DTReserva*>::iterator itDTR;
    map<int,DTEstadia*>::iterator itDTEs;
    finalizar = false;
    codReserva = 0;
    //-----------------------//
    while (!finalizar){
        finSubMenu = false;
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
                           cout<<"Caso alta hostal \n"; 
                            fabrica* f = fabrica::getInstance();
                            IControladorHostal *ICH = (*f).getIControladorHostal();
                            
                            cout << "Por favor, ingrese los siguientes datos: \n";
                            cout << "Nombre del hostal: ";
                            cin.ignore();
                            getline(cin, NombreHos);
                            cout << "Direccion del hostal: ";
                            cin.ignore();
                            getline(cin, DirHos);
                            cout << "Telefono del hostal: ";
                            cin.ignore();
                            getline(cin, TelHos);
                            DTHostal dth(NombreHos,DirHos,TelHos,0);
                            DTHostal* pdth = &dth;
                            (*ICH).IngresarDatosHostal(pdth);
                            (*ICH).confirmarAltaHostal();

                            (*ICH).liberarMemoria();              
                        };
                        break;
                        //case 1 | Alta Hostal
                        case 2:{ //Alta Habitacion
                            
                            DTHostal* dth = ElegirHostal();
                            fabrica* f = fabrica::getInstance();
                            IControladorHostal *ICH = (*f).getIControladorHostal();
                            (*ICH).IngresarDatosHostal(dth);
                            cout << "Por favor, ingrese los siguientes datos: \n";
                            cout << "Numero de habitacion: ";
                            cin >> num;
                            //controlo que no exista ese numero de habitacion en el hostal seleccionado
                            cout << "Precio de la habitacion: ";
                            cin >> precio;
                            cout << "Capacidad de la habitacion: ";
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
                                        (*ICH).liberarMemoria();
                                    else
                                        cout << "La opcion ingresada no es valida.\n";
                                };
                            };
                            (*ICH).liberarMemoria();
                            
                        };
                        break;
                        // case 2 | Alta Habitacion

                        case 3:{ /*// Consultar Hostal
                            DTHostal* dth = ElegirHostal();
                            fabrica* f = fabrica::getInstance();
                            IControladorHostal *ICH = (*f).getIControladorHostal();
                            (*ICH).mostrarHostal();
                         */
                        cout<<"Caso consultar hostal";
                        };
                        break;
                        // case 3 | Consultar Hostal

                        case 4: {//Consultar Top 3 Hostales
                            
                            fabrica * f = fabrica::getInstance();
                            IControladorHostal *CHostal = (*f).getIControladorHostal();
                            map<string,DTHostal*> top3 = (*CHostal).obtenerTop3Hostales();
                            if(top3.size()==0){
                                cout<<"No hay hostales registrados. \n";
                            }else{
                                ind = 1;
                                map<string,DTHostal*>::iterator it;
                                for (it=top3.begin(); it!=top3.end(); it++){
                                    ind++;
                                    std::cout << "No. " << ind << ": \n" << std::endl;
                                    std::cout << "Nombre : " << ((*it).second)->getNombre() << std::endl;
                                    std::cout << "Direccion : " << ((*it).second)->getDireccion() << std::endl;
                                    std::cout << "Telefono : " << ((*it).second)->getTelefono() << std::endl;
                                }
                            }
                        };
                        break;
                        //case 4 | Consultar Top 3 Hostales
                        
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
                            while(!cargoCorrecto){
                                cout<<"1. Administracion \n";                 
                                cout<<"2. Limpieza \n";
                                cout<<"3. Recepcion \n";
                                cout<<"4. Infraestructura \n";      
                                cin>>CargoAux;                                
                                switch (CargoAux){
                                    case 1:{ 
                                        cargo = Administracion;
                                        cargoCorrecto = true;
                                    };
                                    break;
                                    case 2:{ 
                                        cargo = Limpieza;
                                        cargoCorrecto = true;
                                    };
                                    break;
                                    case 3:{ 
                                        cargo = Recepcion;
                                        cargoCorrecto = true;
                                    };
                                    break;
                                    case 4:{ 
                                        cargo = Infraestructura;
                                        cargoCorrecto = true;
                                    };
                                    break;
                                    default:{ 
                                        cout<<"Por favor, ingrese una opcion valida: \n";
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
                            cout<<"Se confirmo el alta de Empleado.\n";
                            map<string,DTEmpleado*> empleados = (*ICU).obtenerEmpleados();
                            map<string,DTEmpleado*>::iterator j = empleados.begin();
                            std::cout<<((*j).second)->getNombre() <<std::endl;
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
                                        cout << "La opcion ingresada no es válida.\n";
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
                            cout<<"Se confirmo el alta de Huesped.\n";
                        };
                        break;
                        //case 2 | Alta Huesped

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
                                    std::cout<<ind<<". Nombre: "<<((*it).second)->getNombre() <<", Mail: "<<((*it).second)->getEmail()<< std::endl;
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
                                        std::cout<<ind<<". Nombre: "<<((*it).second)->getNombre() <<", Mail: "<<((*it).second)->getEmail()<< std::endl;
                                        ind++;
                                    }
                                    cin>>num;
                                    if(num>ind || num==0){
                                        existe = false;
                                        aux= true;
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
                                
                        };
                        break;
                        //case 4 | Consultar Usuario

                        case 5:{ //Suscribir a Notificaciones

                        }
                        case 6:{ //Consultar Notificaciones

                        }
                        case 7:{ //Eliminar Suscripcion

                        }
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
                            IControladorReserva *ICR = (*f).getIControladorReserva();
                            (*ICR).ingresarDatosReserva(dth,ChIn,ChOut);
                            map<int,DTHabitacion*> habs = (*ICR).obtenerHabitacionesDisponibles();
                            map<int,DTHabitacion*>::iterator j;
                            cout<<"Por favor, seleccione el número de la habitacion que desea reservar: \n";
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
                                cout<<"El número de habitacion ingresado no corresponde a una habitacion disponible.\n";
                                for(j=habs.begin(); j!=habs.end(); j++){
                                    std::cout<<"Numero: " << (*(*j).second).getNumero() <<std::endl;
                                    std::cout<<"Precio: " << (*(*j).second).getPrecio() <<std::endl;
                                    std::cout<<"Capacidad: " << (*(*j).second).getCapacidad() <<std::endl;
                                    cout<<"...............................................";
                                };
                                cout<< "Por favor, ingrese un número de habitacion de la lista: \n";
                            
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
                            
                        }//case 1 | Realizar Reserva

                        case 2:{//Consultar Reserva

                        }
                        case 3:{ //Baja de Reserva

                        }
                        case 4:{ //Registrar Estadía

                        }
                        case 5:{ //Consultar Estadia

                        }
                        case 6:{ //Finalizar Estadia

                        }
                        case 7:{ //Volver
                            finSubMenu = true;
                        }
                        default:{}
                    }//switch(Opcion2){
                }//while(!finSubMenu)
            }//case 3 | Administracion de Reservas

            case 4:{ //Administracion de Calificaciones
                while(!finSubMenu){
                    cout << "Seleccione la operacion que desea realizar: \n";
                    cout << "1. Calificar Estadía \n";
                    cout << "2. Comentar Calificacion \n";
                    cout << "3. Registrar Estadía \n";
                    cout << "4. Consultar Estadía \n";
                    cout << "5. Volver \n";
                    cout << "-------------------------------\n";

                    cin >> OpcionAux;
                    Opcion2 = (int)OpcionAux - '0'; //Control en caso de que se ingrese char en vez de int

                    switch (Opcion2){
                        case 1:{ //Calificar Estadía
                            string emaliHues;
                            string calif;
                            int nota;
                            int codigoEst;
                            cout << "selecciones unhostal \n";
                            DTHostal* selectedHost = ElegirHostal();
                            cout << "ingrese el email del huesped cuya estadia desea calificar \n";
                            cin >>emaliHues;
                            fabrica* f = fabrica::getInstance();
                            IControladorReserva *ICR = (*f).getIControladorReserva();
                            IControladorCalificacion *ICC = (*f).getIControladorCalificacion();
                            map<int,DTEstadia*> listaReservas = (*ICR).obtenerEstadiaHuesped(emaliHues);
	                        map<int,DTEstadia*>::iterator it;
                            int cont = 0;
                            cout << "elija la reserva que desee  \n";
	                        for(it=listaReservas.begin(); it!=listaReservas.end(); ++it){
	                        	cont++;
                                cout << cont <<". Codigo de estadia: " << ((*it).second)->getCodigo() << endl;
	                        }
                            cin>>codigoEst;//no validado
                            cout <<"ingrese su calificacion \n";
                            cin>>calif;
                            cout << " ingrese su nota \n";
                            cin>>nota;
                            (*ICC).agregarCalificacion(emaliHues,calif,nota);
                        };
                        break;
                        case 2:{ //Comentar Calificacion
                            fabrica* f = fabrica::getInstance();
                            IControladorCalificacion *ICC = (*f).getIControladorCalificacion();
                            map<int,DTCalificacion*> lisataCalifs;
                            map<int,DTCalificacion*>::iterator it;
                            int calif;
                            string resp;
                            string emailEmpleado;
                            cout <<"ingrese un email empleado que trabaje en el hostal deseado \n";
                            cin>>emailEmpleado;//sin validar
                            lisataCalifs = (*ICC).obtenerCalificaciones(emailEmpleado);
                            cout << "elija la calificacion que desee  \n";
                            for(it=lisataCalifs.begin(); it!=lisataCalifs.end(); ++it){
                                cout << ". Codio de calif" << ((*it).second)->getId() << endl;
                            }
                            cin >>calif;// sin validar
                            it = lisataCalifs.find(calif);
                            DTCalificacion* dtc = (*it).second;
                            cout << "ahora ingrese la respuesta que desee ingresar \n";
                            cin >>resp;// sin validar
                            (*ICC).ingresarRespuesta(resp,dtc);
                        };
                        break;
                        case 3:{ //Registrar Estadía

                        };
                        break;
                        case 4:{ //Consultar Estadía

                        };
                        break;
                        case 5:{ //Volver
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

            };
            break;
            //case 5 | Modificar Fecha de Sistema
            case 6:{ //Cargar datos de prueba
                    fabrica* f = fabrica::getInstance();
                    IControladorHostal *ICH = (*f).getIControladorHostal(); 
                    IControladorUsuario *ICU = (*f).getIControladorUsuario();
                    IControladorReserva *ICR = (*f).getIControladorReserva();
                    IControladorCalificacion *ICC = (*f).getIControladorCalificacion();
                    
                    //Alta Empleados

                    //E1
                    DTUsuario* dtu1 = new DTEmpleado("Emilia","emilia@mail.com","123",Recepcion); 
                    (*ICU).IngresarDatosUsuario(dtu1);
                    (*ICU).confirmarAltaUsuario();

                    //E2
                    DTUsuario* dtu2 = new DTEmpleado("Leonardo","leo@mail.com","123",Recepcion);
                    (*ICU).IngresarDatosUsuario(dtu2);
                    (*ICU).confirmarAltaUsuario();

                    //E3
                    DTUsuario* dtu3 = new DTEmpleado("Alina","alina@mail.com","123",Administracion);
                    (*ICU).IngresarDatosUsuario(dtu3);
                    (*ICU).confirmarAltaUsuario();

                    //E4
                    DTUsuario* dtu4 = new DTEmpleado("Barliman","barli@mail.com","123",Recepcion); 
                    (*ICU).IngresarDatosUsuario(dtu4);
                    (*ICU).confirmarAltaUsuario();

                    //Alta Huespedes
                    
                    //H1
                    DTUsuario* dthu1 = new DTHuesped("Sofia","sofia@mail.com","123",true); 
                    (*ICU).IngresarDatosUsuario(dthu1);
                    (*ICU).confirmarAltaUsuario();

                    //H2
                    DTUsuario* dthu2 = new DTHuesped("Frodo","frodo@mail.com","123",true);
                    (*ICU).IngresarDatosUsuario(dthu2);
                    (*ICU).confirmarAltaUsuario();

                    //H3
                    DTUsuario* dthu3 = new DTHuesped("Sam","sam@mail.com","123",false); 
                    (*ICU).IngresarDatosUsuario(dthu3);
                    (*ICU).confirmarAltaUsuario();

                    //H4
                    DTUsuario* dthu4 = new DTHuesped("Merry","merry@mail.com","123",false); 
                    (*ICU).IngresarDatosUsuario(dthu4);
                    (*ICU).confirmarAltaUsuario();

                    //H5
                    DTUsuario* dthu5 = new DTHuesped("Pippin","pippin@mail.com","123",false);
                    (*ICU).IngresarDatosUsuario(dthu5);
                    (*ICU).confirmarAltaUsuario();

                    //H6
                    DTUsuario* dthu6 = new DTHuesped("Seba","seba@mail.com","123",true); 
                    (*ICU).IngresarDatosUsuario(dthu6);
                    (*ICU).confirmarAltaUsuario();

                    //Alta Hostales
                    //HO1                    
                    
                    DTHostal* pdth1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111",0);
                    (*ICH).IngresarDatosHostal(pdth1);
                    (*ICH).confirmarAltaHostal();

                    //HO2
                    DTHostal* pdth2 = new DTHostal("Mochileros","Rambla Costanera 333, Rocha","42579512",0);
                    (*ICH).IngresarDatosHostal(pdth2);
                    (*ICH).confirmarAltaHostal();

                    //HO3                    
                    DTHostal* pdth3 = new DTHostal("El Pony Pisador","Bree (preguntar por Gandalf)","000",0);
                    (*ICH).IngresarDatosHostal(pdth3);
                    (*ICH).confirmarAltaHostal();

                    //HO4
                    DTHostal* pdth4 = new DTHostal("Altos de Fing","Av del Toro 1424","099892992",0);
                    (*ICH).IngresarDatosHostal(pdth4);
                    (*ICH).confirmarAltaHostal();

                    //HO5
                    DTHostal* pdth5 = new DTHostal("Caverna Lujosa","Amaya 2515","233233235",0);
                    (*ICH).IngresarDatosHostal(pdth5);
                    (*ICH).confirmarAltaHostal();

                    //HO1 - Habitaciones
                    //HA1
                    
                    (*ICH).IngresarDatosHostal(pdth1);

                    DTHabitacion* pdthab1 = new DTHabitacion(1,40,2);
                    (*ICH).IngresarDatosHab(pdthab1);
                    (*ICH).confirmarAltaHabitacion();

                    //HA2
                    DTHabitacion* pdthab2 = new DTHabitacion(2,10,7);
                    (*ICH).IngresarDatosHab(pdthab2);
                    (*ICH).confirmarAltaHabitacion();

                    //HA3
                    DTHabitacion* pdthab3 = new DTHabitacion(3,30,3);
                    (*ICH).IngresarDatosHab(pdthab3);
                    (*ICH).confirmarAltaHabitacion();

                    //HA4
                    DTHabitacion* pdthab4 = new DTHabitacion(4,5,12);
                    (*ICH).IngresarDatosHab(pdthab4);
                    (*ICH).confirmarAltaHabitacion();

                    (*ICH).liberarMemoria();

                    //HO3 - Habitaciones
                    //HA6
                    
                    (*ICH).IngresarDatosHostal(pdth3);

                    DTHabitacion* pdthab6 = new DTHabitacion(1,9,5);                   
                    (*ICH).IngresarDatosHab(pdthab6);
                    (*ICH).confirmarAltaHabitacion();

                    (*ICH).liberarMemoria();

                    //HO5 - Habitaciones
                    //HA5
                    
                    (*ICH).IngresarDatosHostal(pdth5);

                    DTHabitacion* pdthab5 = new DTHabitacion(1,3,2);
                    (*ICH).IngresarDatosHab(pdthab5);
                    (*ICH).confirmarAltaHabitacion();

                    (*ICH).liberarMemoria();
                    
                    //H01 - Reservas
                    //R1 - HA1
                    
                    Date ChIn1(01,05,22);
                    Date ChOut1(10,05,22);
                    (*ICR).ingresarDatosReserva(pdth1,ChIn1,ChOut1);
                    (*ICH).setDatosHabitacion(pdthab1);
                    DTHuesped* dthue1 = static_cast<DTHuesped*>(dthu1);
                    (*ICR).DesignarPropietarioDeReserva(dthue1);   
                    (*ICR).IngresarHuespedEnReserva(dthue1);                 
                    (*ICR).confirmarReserva();

                    //HO1 - Reservas
                    //R3 - HA3
                    
                    Date ChIn3(07,06,22);
                    Date ChOut3(30,06,22);
                    (*ICR).ingresarDatosReserva(pdth1,ChIn3,ChOut3);
                    (*ICH).setDatosHabitacion(pdthab3);
                    DTHuesped* pdthue1 = static_cast<DTHuesped*>(dthu1);
                    (*ICR).DesignarPropietarioDeReserva(pdthue1);   
                    (*ICR).IngresarHuespedEnReserva(pdthue1);                 
                    (*ICR).confirmarReserva();

                    //HO3 - Reservas
                    //R2 - HA6
                    
                    Date ChIn2(04,01,01);
                    Date ChOut2(05,01,01);
                    (*ICR).ingresarDatosReserva(pdth3,ChIn2,ChOut2);
                    (*ICH).setDatosHabitacion(pdthab6);
                    DTHuesped* pdthue2 = static_cast<DTHuesped*>(dthu2);
                    DTHuesped* pdthue3 = static_cast<DTHuesped*>(dthu3);
                    DTHuesped* pdthue4 = static_cast<DTHuesped*>(dthu4);
                    DTHuesped* pdthue5 = static_cast<DTHuesped*>(dthu5);
                    (*ICR).DesignarPropietarioDeReserva(pdthue2);   
                    (*ICR).IngresarHuespedEnReserva(pdthue2);
                    (*ICR).IngresarHuespedEnReserva(pdthue3);
                    (*ICR).IngresarHuespedEnReserva(pdthue4);
                    (*ICR).IngresarHuespedEnReserva(pdthue5);                                     
                    (*ICR).confirmarReserva(); 

                    //HO5 - Reserva
                    //R4
                    
                    Date ChIn4(10,06,22);
                    Date ChOut4(30,06,22);
                    (*ICR).ingresarDatosReserva(pdth5,ChIn4,ChOut4);
                    (*ICH).setDatosHabitacion(pdthab5);
                    DTHuesped* pdthue6 = static_cast<DTHuesped*>(dthu6);
                    (*ICR).DesignarPropietarioDeReserva(pdthue6);   
                    (*ICR).IngresarHuespedEnReserva(pdthue6);                 
                    (*ICR).confirmarReserva();

                    //HO1 - Empleados
                    
                    (*ICH).IngresarDatosHostal(pdth1);

                    (*ICU).AsignarEmpleadoAHostal("emilia@mail.com");
                    (*ICH).FinalizarAsignacionDeEmpleados();

                    (*ICH).liberarMemoria();
                    
                    //HO2 - Empleados
                   
                    (*ICH).IngresarDatosHostal(pdth2);

                    (*ICU).AsignarEmpleadoAHostal("leo@mail.com");
                    (*ICH).FinalizarAsignacionDeEmpleados();

                    (*ICU).AsignarEmpleadoAHostal("alina@mail.com");
                    (*ICH).FinalizarAsignacionDeEmpleados();

                    (*ICH).liberarMemoria(); 

                    //HO3 - Empleados
                    
                    (*ICH).IngresarDatosHostal(pdth3);

                    (*ICU).AsignarEmpleadoAHostal("barli@mail.com");
                    (*ICH).FinalizarAsignacionDeEmpleados();

                    (*ICH).liberarMemoria();                  
                  
                    //Estadías
                    //ES1
                                       
                    map<int,DTReserva*> res = (*ICR).ListarReservasNoCanceladasDeHuesped(pdth1, "sofia@mail.com");
                    itDTR = res.begin();
                    Date d1I(01,05,22);
                    Date * d1O = new Date((*itDTR).second->getCheckOut());
                    DTEstadia * Pdtes1 = new DTEstadia(d1I, d1O, ((*itDTR).second)->getCodigo());                 
                    (*ICC).RegistrarEstadia(pdth1,"sofia@mail.com", (*itDTR).second,Pdtes1);

                    (*ICR).finalizarEstadiaActiva("sofia@mail.com", (*pdth1).getNombre());

                    //ES2 
                    //R2 - HU2
                                        
                    res = (*ICR).ListarReservasNoCanceladasDeHuesped(pdth3, "frodo@mail.com");
                    itDTR = res.begin();
                    Date d2I(04,01,01);
                    Date * d2O = new Date((*itDTR).second->getCheckOut());
                    DTEstadia* Pdtes2 = new DTEstadia(d2I, d2O, ((*itDTR).second)->getCodigo());
                    (*ICC).RegistrarEstadia(pdth3,"frodo@mail.com",(*itDTR).second,Pdtes2);

                    (*ICR).finalizarEstadiaActiva("frodo@mail.com", (*pdth1).getNombre());

                    //ES3
                    //R2 - HU3
                                        
                    res = (*ICR).ListarReservasNoCanceladasDeHuesped(pdth3, "sam@mail.com");
                    itDTR = res.begin();
                    Date d3I(04,01,01);
                    Date * d3O = new Date((*itDTR).second->getCheckOut());
                    DTEstadia* Pdtes3 = new DTEstadia(d3I, d3O, ((*itDTR).second)->getCodigo());
                    (*ICC).RegistrarEstadia(pdth3,"sam@mail.com",(*itDTR).second,Pdtes3);

                    //ES4
                    //R2 - HU4
                                        
                    res = (*ICR).ListarReservasNoCanceladasDeHuesped(pdth3, "merry@mail.com");
                    itDTR = res.begin();
                    Date d4I(04,01,01);
                    Date * d4O = new Date((*itDTR).second->getCheckOut());
                    DTEstadia* Pdtes4 = new DTEstadia(d4I, d4O, ((*itDTR).second)->getCodigo());
                    (*ICC).RegistrarEstadia(pdth3,"merry@mail.com",(*itDTR).second,Pdtes4);

                    //ES5
                    //R2 - HUE5
                                      
                    res = (*ICR).ListarReservasNoCanceladasDeHuesped(pdth3, "pippin@mail.com");
                    itDTR = res.begin();
                    Date d5I(04,01,01);
                    Date * d5O = new Date((*itDTR).second->getCheckOut());
                    DTEstadia* Pdtes5 = new DTEstadia(d5I, d5O, ((*itDTR).second)->getCodigo());
                    (*ICC).RegistrarEstadia(pdth5,"pippin@mail.com",(*itDTR).second,Pdtes5);

                    //ES6
                    //R4 -HU6
                                       
                    res = (*ICR).ListarReservasNoCanceladasDeHuesped(pdth5, "seba@mail.com");
                    itDTR = res.begin();
                    Date d6I(07,06,22);
                    Date * d6O = new Date((*itDTR).second->getCheckOut());
                    DTEstadia* Pdtes6 = new DTEstadia(d6I ,d6O, ((*itDTR).second)->getCodigo());
                    (*ICC).RegistrarEstadia(pdth5,"seba@mail.com",(*itDTR).second,Pdtes6);

                    (*ICR).finalizarEstadiaActiva("seba@mail.com", (*pdth5).getNombre());

                    //Calificar Estadia

                    //C1
                    //ES1
                    map<int,DTEstadia*> esHues = (*ICR).obtenerEstadiaHuesped("sofia@mail.com");
                    itDTEs = esHues.begin();
                    Comentario = "Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba,cayendo. No vuelvo";
                    nota = 3;
                    (*ICC).agregarCalificacion("sofia@mail.com",Comentario, nota);
                    
                    //C2
                    //ES2
                    esHues = (*ICR).obtenerEstadiaHuesped("frodo@mail.com");
                    itDTEs = esHues.begin();
                    Comentario = "Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos.";
                    nota = 2;
                    (*ICC).agregarCalificacion("frodo@mail.com",Comentario, nota);

                    //C3
                    //ES6
                    esHues = (*ICR).obtenerEstadiaHuesped("seba@mail.com");
                    itDTEs = esHues.begin();
                    Comentario = "Había pulgas en la habitación. Que lugar más mamarracho!!";
                    nota = 1;
                    
                    (*ICC).agregarCalificacion("seba@mail.com",Comentario, nota);

                    //Comentar Calificacion
                    (*ICC).setDatosEstadia(Pdtes2);
                    DTCalificacion * dtcal = (*ICC).obtenerCalificacionDeEstadia();
                    Comentario = "Desapareció y se fue sin pagar.";
                    (*ICC).ingresarRespuesta(Comentario,dtcal);

                    (*ICC).liberarMemoria();

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
        cout<<"Gracias por operar con nosotros, vuelva pronto!";
    }//while (!finalizar)
}//int main()