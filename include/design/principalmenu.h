#ifndef PRINCIPALMENU_H_INCLUDED
#define PRINCIPALMENU_H_INCLUDED
    #include <stdio.h>
	#include <stdlib.h>
	#include <iostream>
    using namespace std;
	void menu_principal()
	{
			cout<<"________________________________________________________________________"<<endl;
	        cout<<"|BIENVENIDO A SKEY                                                    ||"<<endl;
	        cout<<"|                                                                     ||"<<endl;
	        cout<<"|        XXXXXXXXXXXXXXXXXXXXX         | SKEY INC.                    ||"<<endl;
	        cout<<"|        SISTEMA DE GENERACION         |                              ||"<<endl;
	        cout<<"|        CODIGOS 'SKEY'                |                              ||"<<endl;
	        cout<<"|        XXXXXXXXXXXXXXXXXXXXX         |                              ||"<<endl;
	        cout<<"_______________________________________________________________________ "<<endl;
	        cout<<"|PARA CONTINUAR, SELECCIONA ALGUNAS DE LAS OPCIONES                   ||"<<endl;
	        cout<<"|                                                                     ||"<<endl;
	        cout<<"|        1-Iniciar sesion                                             ||"<<endl;
	        cout<<"|        2-Crear cuenta                                               ||"<<endl;
	        cout<<"|        3-Salir                                                      ||"<<endl;
	        cout<<"________________________________________________________________________"<<endl;

	        cout<<"Opcion: ";
	}

	void showError()
	{
		cout<<endl;
		cout<<"______________________________________________________________________"<<endl;
		cout<<"| SKEY | FATAL ERROR                                                 ||"<<endl;
		cout<<"______________________________________________________________________"<<endl;
		cout<<"Ingresaste una opci\242n no valida!\n\n";
	}


#endif // PRINCIPALMENU_H_INCLUDED
