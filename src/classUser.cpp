#include "classUser.h"
#include "classPassword.h"
#include "passwordAuxiliar.h"
	#include <iostream>
    #include <conio.h>
    #include <string.h>
    #include <fstream>
    #include <stdlib.h>
    #include <time.h>
    #include <windows.h>


#define LONG_MIN 4
#define LONG_MAX 8

using namespace std;

void user::login()
{
	password p;
	string aux_username;
	ifstream query_user;
	int option_register;
	bool encontrado = false; //ver encontrado en ingles
	query_user.open("datesuser.txt", ios::in);
	system("cls");
	Sleep(10);

	if(encontrado == false)
	{
		getline(cin, username);
		getline(query_user, username); //clave user
		while(!query_user.eof())
		{
            getline(query_user, name);
            getline(query_user, access_p);
			if(aux_username != username)
			{
				system("cls");
				encontrado = false;
				user::loginMenu();
				getline(cin, aux_username);
			}
			if(aux_username == username)
                {
                    encontrado = true;
                    system("cls");
                    user::WelcomeMessageToSkey();///Mensaje de bienvenida
                }
            getline(query_user, username);
		}
		if(encontrado == false)
		{
			system("cls");
			user::error_login();
			cin>>option_register;
			if(option_register == 1)
                user::newUser();
            else
            {
                system("cls");
                user::login();
            }
		}
	}
	query_user.close();
	user::pauseU(); ///folder-> usuarios o libraries
}

void user::newUser()
{
	int opcion_formacion, cant_caracteres, i = 0;
	char aux_pass[LONG_MIN], aux_pass_long[LONG_MAX];

	ofstream write;
	ifstream checker;
	string aux_username;
	bool coincidence = false;
	checker.open("datesuser.txt", ios::in);
	write.open("datesuser.txt", ios::app);

	if(write.is_open() && checker.is_open())
	{
		system("cls");
		user::menuRegister(); ///register_h
        getline(cin,aux_username);
		if(aux_username == "")
			do{
				user::error_register();
				getline(cin, aux_username);
			}while(aux_username == "");
		do{
			checker.seekg(0);
			getline(checker, username);
			while(!checker.eof())
			{
				getline(checker, name);
				getline(checker, access_p);

				if(username == aux_username)
				{
					coincidence = true;
					user::Showcoincidence();
					getline(cin,aux_username);
					if(aux_username =="")
						do{
							user::error_register();
							getline(cin, aux_username);
						} while(aux_username == "");
					break;
				}
				getline(checker, username);
			}
			if(checker.eof() && aux_username !=username)
				coincidence = false;
		} while(coincidence == true);
		system("cls");
		username = aux_username;
		///show a message for creating an acount.
        user::menuCreatingAnAcount();

		cout<<" *Nombre de usuario: ";
        cout<<username;
        cout<<"\n\n";
        fflush(stdin);
        cout<<" *Nombre: ";
        getline(cin, name);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"\n\n";
        cout<<" *Contraseña:";
        cin>>access_p;
        fflush(stdin);
        cout<<"\n\n";

		///guardando datos en el archivo
		write<<username<<"\n"<<name<<"\n"<<access_p<<"\n";

		user::ShowRegisterOk();///register->ShowRegisterOK()

	}
	else
	{
		user::ShowRegisterFatalError(); ///register->ShowError()
	}

	write.close();
	checker.close();
	user::pauseU();

}

void user::error_login()
{
	system("cls");
	int opcion;
	cout<<"______________________________________________________________________"<<endl;
    cout<<"|  ERROR AL ACCEDER A SKEY                                          ||"<<endl;
    cout<<"______________________________________________________________________"<<endl;
    cout<<"|                                                                   ||"<<endl;
    cout<<"| Ups! No te tenemos registrado. ¿Queres registrate?                ||"<<endl;
    cout<<"|             1. Si                                                 ||"<<endl;
    cout<<"|             2. No                                                 ||"<<endl;
    cout<<"______________________________________________________________________"<<endl;

    cout<<"\n Opcion: ";
}

void user::pauseU()
{

    cout<<"Presiona Enter para continuar...";
    getch();
    system("cls");

}

void user::errorU()
{
    cout<<"No se pudo abrir el archivo de claves, asegurate que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre renombralo al ya mencionado\n\n";

}

void user::loginMenu()
{
    cout<<"______________________________________________________________________"<<endl;
    cout<<"| INICIANDO SESION EN  SKEY                                           ||"<<endl;
    cout<<"|                                                                     ||"<<endl;
    cout<<"|        XXXXXXXXXXXXXXXXXXXXX         | SKEY INC.                    ||"<<endl;
    cout<<"|        SISTEMA DE GENERACION         |                              ||"<<endl;
    cout<<"|        CODIGOS 'SKEY'                |                              ||"<<endl;
    cout<<"|        XXXXXXXXXXXXXXXXXXXXX         |                              ||"<<endl;
    cout<<"______________________________________________________________________"<<endl;
    cout<<" * Ingresa tu nombre de usuario:  ";
}
void user::WelcomeMessageToSkey()
{
    password p;
    system("cls");
    cout<<"Hola. Bienvenido a Skey. ";
    cout<<"\n\n";
    Sleep(30);
    system("cls");
    p.menuPrincpal_pass();
}



void user::menuRegister()
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

void user::error_register()
{
	cout<<"\n Error al ingresar los datos!"<<endl;
	cout<<" * Ingresa tu nombre de usuario: ";
}

void user::Showcoincidence()
{
	cout<<"\n\nYa existe una clave con ese c\242digo!\n\n";
	cout<<"Ingresa un nombre de usuario v\240lido!: ";

}

void user:: menuCreatingAnAcount()
{
	  cout<<"______________________________________________________________________"<<endl;
    cout<<"|CREANDO TU CUENTA SKEY...                                           ||"<<endl;
    cout<<"______________________________________________________________________"<<endl;

}

void user::ShowRegisterOk()
{
	cout<<"______________________________________________________________________"<<endl;
    cout<<"| TU CUENTA SE HA CREADO CON EXITO                                    ||"<<endl;
    cout<<"| BIENVENIDO A SKEY.                                                  ||"<<endl;
    cout<<"______________________________________________________________________"<<endl;
}

void user::ShowRegisterFatalError()
{
	cout<<"______________________________________________________________________"<<endl;
    cout<<"|  SKEY | FATAL ERROR                                               ||"<<endl;
    cout<<"______________________________________________________________________"<<endl;
    cout<<endl;
    cout<<"No se pudo abrir el archivo de claves, asegurate que el archivo se encuentre en";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame:";
    cout<<"usuarios.txt, si el archivo tiene otro nombre renombralo al ya mencionado";
}
