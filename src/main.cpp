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
    int cont = 1;
	for(it=listaHostales.begin(); it!=listaHostales.end(); it++){
		std::cout << cont <<". Nombre: " << ((*it).second)->getNombre() << std::endl;
        cont++;
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

#include <iostream>
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
                            cout<<"Se ingreso el nuevo hostal \n";
                            map<string,DTHostal*> listaHostales = (*ICH).obtenerHostales();
                            map<string,DTHostal*>::iterator it;
                            it=listaHostales.begin();
                            std::cout  <<". Nombre: " << ((*it).second)->getNombre() << std::endl;                                
	                        
                            /*try{
                                map<string, hostal*> hostales = (*ICH).getHostales();
                                map<string,hostal*>::iterator it;
                                existe = true;
                                while (it!=hostales.begin() && !existe){
                                    if (((*it).second)->getNombre() == NombreHos)
                                        existe = true;
                                        throw std::invalid_argument("");
                                    it++;
                                    }
                                    if (it == hostales.end())
                                        (*ICH).IngresarDatosHostal(pdth);
                                        (*ICH).confirmarAltaHostal();
                                        cout<<"Se ingreso el nuevo hostal";
                            }
                            catch(invalid_argument &e){
                                (*ICH).liberarDatosHostal();
                                cout << "Ya existe un hostal de nombre " << NombreHos << endl;
                            };*/
                            
                        
                        break;
                        };
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
                                        (*ICH).cancelarAltaHabitacion();
                                    else
                                        cout << "La opcion ingresada no es valida.\n";
                                };
                            };
                            (*ICH).liberarDatosHostal();
                            
                        };
                        break;
                        // case 2 | Alta Habitacion

                        case 3:{ /*// Consultar Hostal
                            DTHostal* dth = ElegirHostal();
                            fabrica* f = fabrica::getInstance();
                            IControladorHostal *ICH = (*f).getIControladorHostal();
                            (*ICH).mostrarHostal();
                         */   
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
                                        std::cout<<ind<<". Nombre: "<<((*it).second)->getNombre() <<", Mail: "<<((*it).second)->getMail()<< std::endl;
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
                            
                            (*ICR).EscogerHabitacion(dthab);
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

                        };
                        break;
                        case 2:{ //Comentar Calificacion

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
                    DTEmpleado e1("Emilia","emilia@mail.com","123",Recepcion); 
                    DTEmpleado* dte1 = &e1;
                    DTUsuario* dtu1 = dynamic_cast<DTUsuario*>(dte1);
                    (*ICU).IngresarDatosUsuario(dtu1);
                    (*ICU).confirmarAltaUsuario();

                    DTEmpleado e2("Leonardo","leo@mail.com","123",Recepcion); 
                    DTEmpleado* dte2 = &e2;
                    DTUsuario* dtu2 = dynamic_cast<DTUsuario*>(dte2);
                    (*ICU).IngresarDatosUsuario(dtu2);
                    (*ICU).confirmarAltaUsuario();

                    DTEmpleado e3("Alina","alina@mail.com","123",Administracion); 
                    DTEmpleado* dte3 = &e3;
                    DTUsuario* dtu3 = dynamic_cast<DTUsuario*>(dte3);
                    (*ICU).IngresarDatosUsuario(dtu3);
                    (*ICU).confirmarAltaUsuario();

                    DTEmpleado e4("Barliman","barli@mail.com","123",Recepcion); 
                    DTEmpleado* dte4 = &e4;
                    DTUsuario* dtu4 = dynamic_cast<DTUsuario*>(dte4);
                    (*ICU).IngresarDatosUsuario(dtu4);
                    (*ICU).confirmarAltaUsuario();

                    //Alta Huespedes
                    DTHuesped hue1("Sofia","sofia@mail.com","123",true); 
                    DTHuesped* Pdth1 = &hue1;
                    DTUsuario* dtuh1 = dynamic_cast<DTUsuario*>(Pdth1);
                    (*ICU).IngresarDatosUsuario(dtuh1);
                    (*ICU).confirmarAltaUsuario();

                    DTHuesped hue2("Frodo","frodo@mail.com","123",true); 
                    DTHuesped* Pdth2 = &hue2;
                    DTUsuario* dtuh2 = dynamic_cast<DTUsuario*>(Pdth2);
                    (*ICU).IngresarDatosUsuario(dtuh2);
                    (*ICU).confirmarAltaUsuario();

                    DTHuesped hue3("Sam","sam@mail.com","123",false); 
                    DTHuesped* Pdth3 = &hue3;
                    DTUsuario* dtuh3 = dynamic_cast<DTUsuario*>(Pdth3);
                    (*ICU).IngresarDatosUsuario(dtuh3);
                    (*ICU).confirmarAltaUsuario();

                    DTHuesped hue4("Merry","merry@mail.com","123",false); 
                    DTHuesped* Pdth4 = &hue4;
                    DTUsuario* dtuh4 = dynamic_cast<DTUsuario*>(Pdth4);
                    (*ICU).IngresarDatosUsuario(dtuh4);
                    (*ICU).confirmarAltaUsuario();

                    DTHuesped hue5("Pippin","pippin@mail.com","123",false); 
                    DTHuesped* Pdth5 = &hue5;
                    DTUsuario* dtuh5 = dynamic_cast<DTUsuario*>(Pdth5);
                    (*ICU).IngresarDatosUsuario(dtuh5);
                    (*ICU).confirmarAltaUsuario();

                    DTHuesped hue6("Seba","seba@mail.com","123",true); 
                    DTHuesped* Pdth6 = &hue6;
                    DTUsuario* dtuh6 = dynamic_cast<DTUsuario*>(Pdth6);
                    (*ICU).IngresarDatosUsuario(dtuh6);
                    (*ICU).confirmarAltaUsuario();

                    //HO1
                    
                    DTHostal dth1("La posada del finger","Av de la playa 123, Maldonado","099111111",0);
                    DTHostal* pdth1 = &dth1;
                    (*ICH).IngresarDatosHostal(pdth1);

                    //HO1 - Habitaciones
                    //HA1
                    DTHabitacion dthab1(1,40,2);
                    DTHabitacion* pdthab1 = &dthab1;
                    (*ICH).IngresarDatosHab(pdthab1);
                    (*ICH).confirmarAltaHabitacion();

                    //H01 - HA1 - Reserva R1
                    
                    Date ChIn1(01,05,22);
                    Date ChOut1(10,05,22);
                    (*ICR).ingresarDatosReserva(pdth1,ChIn1,ChOut1);
                    (*ICR).DesignarPropietarioDeReserva(Pdth1);                    
                    (*ICR).confirmarReserva();

                    //(*ICC).RegistrarEstadia(dth,"sofia@mail.com",res,est);

                    //HA2
                    DTHabitacion dthab2(2,10,7);
                    DTHabitacion* pdthab2 = &dthab2;
                    (*ICH).IngresarDatosHab(pdthab2);
                    (*ICH).confirmarAltaHabitacion();

                    //HA3
                    DTHabitacion dthab3(3,30,3);
                    DTHabitacion* pdthab3 = &dthab3;
                    (*ICH).IngresarDatosHab(pdthab3);
                    (*ICH).confirmarAltaHabitacion();

                    //HO1 - HA3 / Reserva R3

                    Date ChIn2(07,06,22);
                    Date ChOut2(30,06,22);
                    (*ICR).ingresarDatosReserva(pdth1,ChIn2,ChOut2);
                    (*ICR).DesignarPropietarioDeReserva(Pdth1);                    
                    (*ICR).confirmarReserva();

                    //HA4

                    DTHabitacion dthab4(4,5,12);
                    DTHabitacion* pdthab4 = &dthab4;
                    (*ICH).IngresarDatosHab(pdthab4);
                    (*ICH).confirmarAltaHabitacion();

                    //HO1 - Empleados

                    (*ICU).AsignarEmpleadoAHostal("emilia@mail.com");
                    (*ICH).FinalizarAsignacionDeEmpleados();

                    (*ICH).liberarDatosHostal();

                    //HO2
                    DTHostal dth2("Mochileros","Rambla Costanera 333, Rocha","42579512",0);
                    DTHostal* pdth2 = &dth2;
                    (*ICH).IngresarDatosHostal(pdth2);
                    (*ICH).liberarDatosHostal();

                    //HO2 - Empleados

                    (*ICU).AsignarEmpleadoAHostal("leo@mail.com");
                    (*ICH).FinalizarAsignacionDeEmpleados();

                    (*ICU).AsignarEmpleadoAHostal("alina@mail.com");
                    (*ICH).FinalizarAsignacionDeEmpleados();

                    //HO3
                    DTHostal dth3("El Pony Pisador","Bree (preguntar por Gandalf)","000",0);
                    DTHostal* pdth3 = &dth3;
                    (*ICH).IngresarDatosHostal(pdth3);

                    //HO3 - Habitaciones
                    //HA6
                    //DTHabitacion dthab3(1,9,5);
                    //DTHabitacion* 
                    pdthab3 = &dthab3;
                    (*ICH).IngresarDatosHab(pdthab3);
                    (*ICH).confirmarAltaHabitacion();
                    
                    //HO3 - HA6 - Reserva R2
                    Date ChIn3(04,01,01);
                    Date ChOut3(05,01,01);
                    (*ICR).ingresarDatosReserva(pdth3,ChIn3,ChOut3);
                    (*ICR).DesignarPropietarioDeReserva(Pdth2); 
                    (*ICR).IngresarHuespedEnReserva(Pdth3);
                    (*ICR).IngresarHuespedEnReserva(Pdth4);
                    (*ICR).IngresarHuespedEnReserva(Pdth5);                   
                    (*ICR).confirmarReserva();

                    //HO3 - Empleados

                    (*ICU).AsignarEmpleadoAHostal("barli@mail.com");
                    (*ICH).FinalizarAsignacionDeEmpleados();

                    (*ICH).liberarDatosHostal();

                    //HO4
                    DTHostal dth4("Altos de Fing","Av del Toro 1424","099892992",0);
                    DTHostal* pdth4 = &dth4;
                    (*ICH).IngresarDatosHostal(pdth4);
                    (*ICH).liberarDatosHostal();

                    //HO5
                    DTHostal dth5("Caverna Lujosa","Amaya 2515","233233235",0);
                    DTHostal* pdth5 = &dth5;
                    (*ICH).IngresarDatosHostal(pdth5);
                    
                    //HO5 - HA5

                    DTHabitacion dthab(1,3,2);
                    DTHabitacion* pdthab = &dthab;
                    (*ICH).IngresarDatosHab(pdthab);
                    (*ICH).confirmarAltaHabitacion();

                    //HO5 - HA5 - Reserva R4

                    Date ChIn4(10,06,22);
                    Date ChOut4(30,06,22);
                    (*ICR).ingresarDatosReserva(pdth5,ChIn4,ChOut4);
                    (*ICR).DesignarPropietarioDeReserva(Pdth6);                    
                    (*ICR).confirmarReserva();                    

                    (*ICH).liberarDatosHostal();
                    
                    //Estadías
                    //ES1
                    DTHostal * Pdth = &dth1;                    
                    map<int,DTReserva*> res = (*ICR).ListarReservasNoCanceladasDeHuesped(Pdth, "sofia@mail.com");
                    
                    itDTR = res.begin();
                    Date d1(01,05,22);
                    DTEstadia dtes1(d1, ((*itDTR).second)->getCheckOut(), codReserva++);
                    DTEstadia * Pdte1 = &dtes1;                  
                    (*ICC).RegistrarEstadia(Pdth,"sofia@mail.com", (*itDTR).second,Pdte1);

                    (*ICR).finalizarEstadiaActiva("sofia@mail.com", (*Pdth).getNombre());

                    //ES2
                    Pdth = &dth3;                    
                    res = (*ICR).ListarReservasNoCanceladasDeHuesped(Pdth, "frodo@mail.com");
                    
                    itDTR = res.begin();
                    Date d2(04,01,01);
                    DTEstadia dtes2(d2, (*itDTR).second->getCheckOut(), codReserva++);
                    DTEstadia* Pdte2 = &dtes2;
                    (*ICC).RegistrarEstadia(Pdth,"frodo@mail.com",(*itDTR).second,Pdte2);

                    (*ICR).finalizarEstadiaActiva("frodo@mail.com", (*Pdth).getNombre());

                    //ES3
                    Pdth = &dth3;                    
                    res = (*ICR).ListarReservasNoCanceladasDeHuesped(Pdth, "sam@mail.com");
                    itDTR = res.begin();
                    Date d3(04,01,01);
                    DTEstadia dtes3(d3, (*itDTR).second->getCheckOut(), codReserva++);
                    DTEstadia* Pdte3 = &dtes3;
                    (*ICC).RegistrarEstadia(Pdth,"sam@mail.com",(*itDTR).second,Pdte3);

                    //ES4
                    Pdth = &dth3;                    
                    res = (*ICR).ListarReservasNoCanceladasDeHuesped(Pdth, "merry@mail.com");
                    itDTR = res.begin();
                    Date d4(04,01,01);
                    DTEstadia dtes4(d4, (*itDTR).second->getCheckOut(), codReserva++);
                    DTEstadia* Pdte4= &dtes4;
                    (*ICC).RegistrarEstadia(Pdth,"merry@mail.com",(*itDTR).second,Pdte4);

                    //ES5
                    Pdth = &dth3;                    
                    res = (*ICR).ListarReservasNoCanceladasDeHuesped(Pdth, "pippin@mail.com");
                    itDTR = res.begin();
                    Date d5(04,01,01);
                    DTEstadia dtes5(d5, (*itDTR).second->getCheckOut(), codReserva++);
                    DTEstadia* Pdte5 = &dtes5;
                    (*ICC).RegistrarEstadia(Pdth,"pippin@mail.com",(*itDTR).second,Pdte5);

                    //ES6
                    Pdth = &dth5;                    
                    res = (*ICR).ListarReservasNoCanceladasDeHuesped(Pdth, "seba@mail.com");
                    itDTR = res.begin();
                    Date d6(07,06,22);
                    DTEstadia dtes6(d6, (*itDTR).second->getCheckOut(), codReserva++);
                    DTEstadia* Pdte6 = &dtes6;
                    (*ICC).RegistrarEstadia(Pdth,"seba@mail.com",(*itDTR).second,Pdte6);

                    (*ICR).finalizarEstadiaActiva("seba@mail.com", (*Pdth).getNombre());

                    //Calificar Estadia

                    //ES1
                    map<int,DTEstadia*> esHues = (*ICR).obtenerEstadiaHuesped("sofia@mail.com");
                    itDTEs = esHues.begin();
                    Comentario = "Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba,cayendo. No vuelvo";
                    nota = 3;
                    (*ICC).agregarCalificacion(Comentario, nota);

                    //ES2
                    esHues = (*ICR).obtenerEstadiaHuesped("frodo@mail.com");
                    itDTEs = esHues.begin();
                    Comentario = "Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos.";
                    nota = 2;
                    (*ICC).agregarCalificacion(Comentario, nota);

                    //ES6
                    esHues = (*ICR).obtenerEstadiaHuesped("seba@mail.com");
                    itDTEs = esHues.begin();
                    Comentario = "Había pulgas en la habitación. Que lugar más mamarracho!!";
                    nota = 1;
                    (*ICC).agregarCalificacion(Comentario, nota);

                    //Comentar Calificacion
                    map<int,DTCalificacion*> cals = (*ICC).obtenerCalificaciones("barli@mail.com");
                    Comentario = "Desapareció y se fue sin pagar.";
                    (*ICC).ingresarComentario(Comentario);

                };
                break;//case 6 | Cargar datos de prueba
            case 7:{ //Salir
                finalizar = true;
                break;
            }//case 7 | Salir
            default:{
                cout << "Por favor, ingrese una opcion entre 1 y 6.\n";
                break;
            }
        }//switch(Opcion1)
        cout<<"Fuera del menu principal";
    }//while (!finalizar)
}//int main()