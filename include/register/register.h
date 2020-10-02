#ifndef REGISTER_H_INCLUDED
#define REGISTER_H_INCLUDED

	#include <iostream>
    #include <conio.h>
    #include <string.h>
    #include <fstream>
    #include <stdlib.h>
    #include <time.h>
    #include <windows.h>

	#define ENTER 13
	#define BACKSPACE 8

    using namespace std;
	void menuRegister()
	{
		cout<<"______________________________________________________________________"<<endl;
        cout<<"|UNITE. CREA TU CUETA SKEY                                            ||"<<endl;
        cout<<"|                                                                     ||"<<endl;
        cout<<"|        XXXXXXXXXXXXXXXXXXXXX         | SKEY INC.                    ||"<<endl;
        cout<<"|        SISTEMA DE GENERACION         |                              ||"<<endl;
        cout<<"|        CODIGOS 'SKEY'                |                              ||"<<endl;
        cout<<"|        XXXXXXXXXXXXXXXXXXXXX         |                              ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;


        fflush(stdin);
        cout<<" Por favor, completa los datos que te vamos a especificar a continuaci\242n: \n"<<endl;
        cout<<" *Nombre de usuario: ";
	}

	void error_register()
	{
		cout<<"\n Error al ingresar los datos!"<<endl;
		cout<<" * Ingresa tu nombre de usuario: ";
	}

	void Showcoincidence()
	{
		cout<<"\n\nYa existe una clave con ese c\242digo!\n\n";
		cout<<"Ingresa un nombre de usuario v\240lido!: ";

	}

	void  menuCreatingAnAcount()
	{
		  cout<<"______________________________________________________________________"<<endl;
        cout<<"|CREANDO TU CUENTA SKEY...                                           ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;

	}

	void ShowRegisterOK()
	{
		cout<<"______________________________________________________________________"<<endl;
        cout<<"| TU CUENTA SE HA CREADO CON EXITO                                    ||"<<endl;
        cout<<"| BIENVENIDO A SKEY.                                                  ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;
	}

	void ShowRegisterFatalError()
	{
		cout<<"______________________________________________________________________"<<endl;
        cout<<"|  SKEY | FATAL ERROR                                               ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;
        cout<<endl;
        cout<<"No se pudo abrir el archivo de claves, asegurate que el archivo se encuentre en";
        cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame:";
        cout<<"usuarios.txt, si el archivo tiene otro nombre renombralo al ya mencionado";
	}




#endif // REGISTER_H_INCLUDED
