principal: obj/main.o  obj/respuesta.o obj/notificacion.o obj/hostal.o obj/habitacion.o obj/FechaSistema.o obj/fabrica.o obj/estadia.o obj/calificacion.o obj/usuario.o obj/IObserver.o obj/huesped.o obj/empleado.o obj/grupal.o obj/individual.o obj/Huesped-Grupal.o obj/Huesped-Individual.o obj/Date.o obj/DTCalificacion.o obj/DTDatosEstadia.o obj/DTEmpleado.o obj/DTEstadia.o obj/DTHabitacion.o obj/DTHostal.o obj/DTHuesped.o obj/DTNotificacion.o obj/DTReserva.o obj/DTReservaGrupal.o obj/DTReservaIndividual.o obj/DTRespuesta.o obj/DTUsuario.o obj/ControladorUsuario.o obj/ControladorHostal.o obj/ControladorCalificacion.o obj/ControladorReserva.o obj/IControladorUsuario.o obj/IControladorHostal.o obj/IControladorCalificacion.o obj/IControladorReserva.o obj/reserva.o
	g++ obj/main.o  obj/respuesta.o obj/notificacion.o obj/hostal.o obj/habitacion.o obj/FechaSistema.o obj/fabrica.o obj/estadia.o obj/calificacion.o obj/usuario.o obj/IObserver.o obj/huesped.o obj/empleado.o obj/grupal.o obj/individual.o obj/Huesped-Grupal.o obj/Huesped-Individual.o obj/Date.o obj/DTCalificacion.o obj/DTDatosEstadia.o obj/DTEmpleado.o obj/DTEstadia.o obj/DTHabitacion.o obj/DTHostal.o obj/DTHuesped.o obj/DTNotificacion.o obj/DTReserva.o obj/DTReservaGrupal.o obj/DTReservaIndividual.o obj/DTRespuesta.o obj/DTUsuario.o obj/ControladorUsuario.o obj/ControladorHostal.o obj/ControladorCalificacion.o obj/ControladorReserva.o obj/IControladorUsuario.o obj/IControladorHostal.o obj/IControladorCalificacion.o obj/IControladorReserva.o obj/reserva.o -o principal

obj/main.o:
	g++ -c -Iinclude src/main.cpp -o obj/main.o
obj/respuesta.o:
	g++ -c -Iinclude src/respuesta.cpp -o obj/respuesta.o
obj/notificacion.o:
	g++ -c -Iinclude src/notificacion.cpp -o obj/notificacion.o
obj/hostal.o:
	g++ -c -Iinclude src/hostal.cpp -o obj/hostal.o
obj/habitacion.o:
	g++ -c -Iinclude src/habitacion.cpp -o obj/habitacion.o
obj/FechaSistema.o:
	g++ -c -Iinclude src/FechaSistema.cpp -o obj/FechaSistema.o
obj/fabrica.o:
	g++ -c -Iinclude src/fabrica.cpp -o obj/fabrica.o
obj/estadia.o:
	g++ -c -Iinclude src/estadia.cpp -o obj/estadia.o
obj/calificacion.o:
	g++ -c -Iinclude src/calificacion.cpp -o obj/calificacion.o
obj/usuario.o:
	g++ -c -Iinclude/usuario src/usuario/usuario.cpp -o obj/usuario.o
obj/IObserver.o:
	g++ -c -Iinclude/usuario src/usuario/IObserver.cpp -o obj/IObserver.o
obj/huesped.o:
	g++ -c -Iinclude/usuario src/usuario/huesped.cpp -o obj/huesped.o
obj/empleado.o:
	g++ -c -Iinclude/usuario src/usuario/empleado.cpp -o obj/empleado.o
obj/grupal.o:
	g++ -c -Iinclude/reserva src/reserva/grupal.cpp -o obj/grupal.o
obj/individual.o:
	g++ -c -Iinclude/reserva src/reserva/individual.cpp -o obj/individual.o
obj/Huesped-Grupal.o:
	g++ -c -Iinclude/reserva src/reserva/Huesped-Grupal.cpp -o obj/Huesped-Grupal.o
obj/Huesped-Individual.o:
	g++ -c -Iinclude/reserva src/reserva/Huesped-Individual.cpp -o obj/Huesped-Individual.o
obj/Date.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/Date.cpp -o obj/Date.o;
obj/DTCalificacion.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTCalificacion.cpp -o obj/DTCalificacion.o;
obj/DTDatosEstadia.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTDatosEstadia.cpp -o obj/DTDatosEstadia.o 
obj/DTEmpleado.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTEmpleado.cpp -o obj/DTEmpleado.o
obj/DTEstadia.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTEstadia.cpp -o obj/DTEstadia.o
obj/DTHabitacion.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTHabitacion.cpp -o obj/DTHabitacion.o
obj/DTHostal.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTHostal.cpp -o obj/DTHostal.o
obj/DTHuesped.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTHuesped.cpp -o obj/DTHuesped.o
obj/DTNotificacion.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTNotificacion.cpp -o obj/DTNotificacion.o
obj/DTReserva.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTReserva.cpp -o obj/DTReserva.o
obj/DTReservaGrupal.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTReservaGrupal.cpp -o obj/DTReservaGrupal.o
obj/DTReservaIndividual.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTReservaIndividual.cpp -o obj/DTReservaIndividual.o
obj/DTRespuesta.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTRespuesta.cpp -o obj/DTRespuesta.o
obj/DTUsuario.o:
	g++ -c -Iinclude/DTyEnum src/DTyEnum/DTUsuario.cpp -o obj/DTUsuario.o
obj/ControladorUsuario.o:
	g++ -c -Iinclude/ControladorUsuario src/ControladorUsuario/ControladorUsuario.cpp -o obj/ControladorUsuario.o
obj/ControladorHostal.o:
	g++ -c -Iinclude/ControladorHostal src/ControladorHostal/ControladorHostal.cpp -o obj/ControladorHostal.o
obj/ControladorCalificacion.o:
	g++ -c -Iinclude/ControladorCalificacion src/ControladorCalificacion/ControladorCalificacion.cpp -o obj/ControladorCalificacion.o
obj/ControladorReserva.o:
	g++ -c -Iinclude/ControladorReserva src/ControladorReserva/ControladorReserva.cpp -o obj/ControladorReserva.o
obj/IControladorUsuario.o:
	g++ -c -Iinclude/ControladorUsuario src/ControladorUsuario/IControladorUsuario.cpp -o obj/IControladorUsuario.o
obj/IControladorHostal.o:
	g++ -c -Iinclude/ControladorHostal src/ControladorHostal/IControladorHostal.cpp -o obj/IControladorHostal.o
obj/IControladorCalificacion.o:
	g++ -c -Iinclude/ControladorCalificacion src/ControladorCalificacion/IControladorCalificacion.cpp -o obj/IControladorCalificacion.o
obj/IControladorReserva.o:
	g++ -c -Iinclude/ControladorReserva src/ControladorReserva/IControladorReserva.cpp -o obj/IControladorReserva.o
obj/reserva.o:
	g++ -c -Iinclude/reserva src/reserva/reserva.cpp -o obj/reserva.o
clean: 
	rm -f obj/*.o principal