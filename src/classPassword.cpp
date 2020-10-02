#include "classPassword.h"
#include "classUser.h"

    #include <iostream>
    #include <conio.h>
    #include <string.h>
    #include <fstream>
    #include <stdlib.h>
    #include <time.h>
    #include <windows.h>

using namespace std;

void password::menuPrincpal_pass()
{
        int option;
        cout<<"___________________________________________________________________________"<<endl;
        cout<<"|MENU PRINCIPAL.                                                         ||"<<endl;
        cout<<"|                                                                        ||"<<endl;
        cout<<"|     XXXXXXXXXXXXXXXXXXXXXXXXXXXX        | SKEY INC.                    ||"<<endl;
        cout<<"|     X   SISTEMA DE GENERACION  X        |                              ||"<<endl;
        cout<<"|     X   CODIGOS 'SKEY'         X        |                              ||"<<endl;
        cout<<"|     XXXXXXXXXXXXXXXXXXXXXXXXXXXX        |                              ||"<<endl;
        cout<<"___________________________________________________________________________"<<endl;
        cout<<"|                                                                        ||"<<endl;
        cout<<"|     OPCIONES:                                                          ||"<<endl;
        cout<<"|                                                                        ||"<<endl;
        cout<<"|        1. Crear clave                   |                              ||"<<endl;
        cout<<"|        2. Mostrar detalles de claves    |                              ||"<<endl;
        cout<<"|        3. Borrar clave                  |                              ||"<<endl;
        cout<<"|        4. Modificar clave               |                              ||"<<endl;
        cout<<"|        5. Informacion                   |                              ||"<<endl;
        cout<<"|        6. Salir                         |                              ||"<<endl;
        cout<<"___________________________________________________________________________"<<endl;

        cout<<"Opcion: ";
        cin>>option;

        switch(option)
        {
            case 1: crearClave(); break;
            case 2: verClaves(); break;
            case 3: eliminarClave(); break;
            case 4: modificarClave(); break;
            case 5: info();break;
            case 6: system("cls"); cout<<"Cerrando sesion..."<<endl; Sleep(10); break;
        }
}

void password::crearClave()
{
    user u;
    password p;
    string user_name = u.name;
    string user_username = u.username;
    string user_access = u.access_p;

    int aux_opc_formation, cant_char, i=0;
    char pass_min[4], pass_max[8], digit[24], cadena[36] = {
    'A','B','C','D','E','F','G','H','I','J','K','L',
    'M','N','O','P','Q','R','S','T','U','V','W','X',
    'Y','Z','0','1','2','3','4','5','6','7','8','9'
    };
    ofstream write;
    ifstream see_user;
    ifstream cheker;
    string aux_code, aux_username;
    bool coincidence = false, control = false;
    cheker.open("passwords.txt", ios::in);
    write.open("passwords.txt", ios::app);

    if(write.is_open() && cheker.is_open())
    {
        p.show_menus(1);
        cout<<" - Nombre de usuario: ";
        getline(cin, aux_username);
        cout<<" - C\242digo de clave: ";
        getline(cin, aux_code);

        if(aux_code == "")
            do{
                ShowErrorInputs();
                getline(cin, aux_code);
            }while(aux_code == "");
        do{
            cheker.seekg(0);
            getline(cheker, p.codigo);
            while(!cheker.eof()){
                getline(cheker, uso);
                getline(cheker, contenido);

                if(codigo == aux_code){
                    coincidence = true;
                    p.show_menus(2);
                    cout<<" La clave con ese c\242digo es: "<<uso<<"\n\n";
                    cout<<" Ingresa un c\242digo v\240lido: ";
                    getline(cin, aux_code);
                    if(aux_code == "")
                        do{
                            ShowErrorInputs();
                            getline(cin, aux_code);
                        }while(aux_code == "");
                    break;
                }
                getline(cheker, codigo);
            }
            if(cheker.eof() && aux_code != codigo)
                coincidence = false;
        } while(coincidence == true);
        system("cls");

        codigo = aux_code;
        propietario = aux_username;
        p.show_menus(3);
        cout<<" - Nombre de usuario: ";
        cout<<propietario<<endl;
        cout<<" - C\242digo de la clave: ";
        cout<<codigo<<endl;
        fflush(stdin);
        cout<<" - Ingresa el uso de la clave: ";
        getline(cin, uso);
        fflush(stdin);
        cout<<endl;

        p.show_menus(4); ///formas de crear la clave.
        cin>>aux_opc_formation;

        if(aux_opc_formation == 1){
            cout<<" -Ingresa tu clave: ";
            cin>>contenido;
        }
        else
        {
            if(aux_opc_formation == 2){
                p.show_menus(5);
                cin>> cant_char;

                switch(cant_char){
                    case 1:
                        system("cls");
                        p.ShowGenerationPass();
                        srand(time(NULL));
                        for(i=0; i<= 4; i++)
                        {
                            digit[i] = cadena[rand() %35];
                            printf("%c", digit[i]);
                            pass_min[i] = digit[i];
                        } fflush(stdin);
                        cout<<" - Ingresa la clave generada";
                        getline(cin, contenido);
                    break;

                    case 2:
                        system("cls");
                        p.ShowGenerationPass();
                        cout<<" - Clave generada: ";
                        srand(time(NULL));
                        for(i=0; i<=8; i++)
                        {
                            digit[i] = cadena[rand() %35];
                            printf("%c", digit[i]);
                            pass_max[i]  = digit[i];
                        }
                        fflush(stdin);
                        cout<<" - Ingresa la clave que esta en pantalla: ";
                        getline(cin, contenido);
                    break;
                }
            }
        }
        cout<<"\n\n";
        write<<codigo<<"\n"<<propietario<<"\n"<<uso<<"\n"<<contenido<<"\n";
        system("cls");
        show_menus(6);
    }
    else{
        p.error();
    }
    write.close();
    cheker.close();
    p.pausa();
}

void password::eliminarClave()
{
    ifstream read; ofstream auxiliar; password p;
    bool encontrado = true; string aux_codigo; char answer[5];
    read.open("passwords.txt", ios::in); auxiliar.open("auxiliar.txt", ios::out); system("cls");
    p.ShowMenusEliminarClave(1);
    if(read.is_open() && auxiliar.is_open())
    {
        fflush(stdin);
        cout<<" -Codigo de clave a eliminar: ";
        getline(cin, aux_codigo);
        getline(read, codigo);
        while(!read.eof())
        {
            getline(read, propietario);
            getline(read, uso);
            getline(read, contenido);
            if(aux_codigo == codigo){
                encontrado = true; system("cls"); p.ShowMenusEliminarClave(2);
                cout<<" -Clave de: "<<propietario<<endl;
                cout<<" -Codigo de la clave: "<<codigo<<endl;
                cout<<" -Uso: "<<uso<<endl;
                cout<<" -Clave: "<<contenido<<endl;
                cout<<"\n\n"; cout<<"¿Realmente quiere dar de baja a la clave: "<<contenido<<" (s/n?";
                cin.getline(answer,5);
                if(strcmp(answer,"s")==0||strcmp(answer,"S")==0||strcmp(answer,"si")==0||strcmp(answer,"SI")==0||strcmp(answer,"Si")==0||strcmp(answer,"sI")==0)
                { system("cls"); p.ShowMenusEliminarClave(3);}
                else
                {
                    system("cls"); p.ShowMenusEliminarClave(4);
                    auxiliar<<propietario<<"\n"<<codigo<<"\n"<<uso<<"\n"<<contenido<<"\n";

                }
            }
            else
                auxiliar<<propietario<<"\n"<<codigo<<"\n"<<uso<<"\n"<<contenido<<"\n";
            getline(read, codigo);
        }
        if(encontrado == false) system("cls"); cout<<"\n\nNo se encontr\242 el c\242digo: "<<aux_codigo<<"\n\n";
    }
    else error();
    read.close(); auxiliar.close(); remove("passwords.txt"); rename("auxiliar.txt", "passwords.txt"); pausa();
}

void password::modificarClave()
{
    ifstream read, checker;
    ofstream auxiliar;
    string aux_codigo, new_code, aux_uso, aux_content, aux_propietario;
    bool encontrado =  false, coincidence = false, code_is_same = false;

    read.open("passwords.txt", ios::in);
    checker.open("passwords.txt", ios::in);
    auxiliar.open("auxiliar.txt", ios::out);

    ShowMenusModificarClaves(1);
    if(read.is_open() && checker.is_open())
    {
        fflush(stdin);
        cout<<" -Ingrese el c\242digo de la clave a modificar: ";
        getline(cin, aux_codigo);
        if(aux_codigo==""){
            do{
                ShowErrorInputs();
            }while(aux_codigo == "");
        }
        new_code = aux_codigo;
        getline(read, codigo);
        while(!read.eof())
        {
            getline(read, propietario);
            getline(read, uso);
            getline(read, contenido);
            if(aux_codigo == codigo)
            {
                encontrado = true;
                mostrarClave(new_code);
                system("cls");
                ShowMenusModificarClaves(2);
                getline(cin, aux_propietario);
                cout<<" - Ingresa el c\242digo de la clave: ";
                getline(cin, aux_codigo);
                if(aux_codigo == new_code)
                {
                    code_is_same = true;
                }
                if(code_is_same == false)
                {
                    do{
                        if(aux_codigo == new_code)
                        {
                            coincidence = false; break;
                        }
                        checker.seekg(0);
                        getline(checker, codigo);
                        while(!checker.eof())
                        {
                            getline(checker, propietario);
                            getline(checker, contenido);
                            if(aux_codigo == codigo){
                                coincidence = true;
                                system("cls");
                                ShowMenusModificarClaves(3); //-> linea 834 error showpass
                                cout<<"La clave con ese c\242digo es para: "<<uso<<"\n\n";
                                cout<<"Ingresa un c\242digo v\240lido!: ";
                                getline(cin, aux_codigo);
                                if(aux_codigo == ""){
                                    do{
                                        ShowErrorInputs();
                                        getline(cin, aux_codigo);
                                    } while(aux_codigo == "");
                                } break;
                            }
                            getline(checker, codigo);
                        }
                        if(checker.eof() && aux_codigo != codigo)
                            coincidence = false;
                    } while(coincidence == true);
                }
                system("cls");
                ShowMenusModificarClaves(4);/// linea 868
                cout<<new_code;
                mostrarClave(new_code);
                cout<<"\n\n";
                cout<<"Ingresa la nueva informacion para la clave."<<endl;
                cout<<" -Nombre de usuario: ";
                getline(cin, aux_propietario);
                fflush(stdin);
                cout<<" -Codigo de clave: ";
                cout<<aux_codigo;
                cout<<"\n"; fflush(stdin);
                cout<<" -Uso de la clave: ";
                getline(cin, aux_uso); fflush(stdin); cout<<"\n";
                cout<<" -Ingrese la clave (Manualmente): ";
                getline(cin, aux_content); cout<<"\n\n";
                auxiliar<<aux_propietario<<"\n"<<aux_codigo<<"\n"<<aux_uso<<"\n"<<aux_content<<"\n";
                system("cls"); ShowMenusModificarClaves(5); ///->linea 896
           }
           else{
            auxiliar<<propietario<<"\n"<<codigo<<"\n"<<uso<<"\n"<<contenido<<"\n";
           } getline(read, codigo);
        }
    }
    else{
        error();
    }

    if(encontrado == false)
        ShowMenusModificarClaves(6); ///show_menus_modificar -> line 920
    read.close();
    checker.close();
    auxiliar.close();
    remove("passwords.txt");
    rename("auxiliar.txt", "passwords.txt");
    pausa();
}

void password::verClaves()
{
    string auxCodigo; ifstream mostrar;
    bool encontrado=false;
    mostrar.open("passwords.txt",ios::in); system("cls");
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"______________________________________________________________________"<<endl;
        cout<<"| SKEY | CONSULTAR DETALLES DE MI CLAVE                             ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;
        cout<<" -Ingresa el codigo de tu clave: ";
        getline(cin,auxCodigo); getline(mostrar,codigo); system("cls");
        while(!mostrar.eof())
        {
            getline(mostrar,propietario);
            getline(mostrar,uso);
            getline(mostrar,contenido);

            if(auxCodigo==codigo)
            {
                encontrado=true;
                cout<<"______________________________________________________________________"<<endl;
                cout<<"|SKEY | Clave encontrada con exito.                                 ||"<<endl;
                cout<<"______________________________________________________________________"<<endl;
                cout<<"\n\n"<<endl;
                cout<<" -C\242digo: "<< codigo<<endl;
                cout<<" -Clave de: "<< propietario<<endl;
                cout<<" -Uso: "<< uso<<endl;
                cout<<" -Clave: "<< contenido<<endl;
                cout<<"\n\n";
            }
            getline(mostrar,codigo);
        }
        if(encontrado==false)
        {
            cout<<"________________________________________________________________________________"<<endl;
            cout<<"|ERROR: No se encontr\242 el c\242digo                                        ||"<<endl;
            cout<<"|"<<auxCodigo<<"                                                              ||";
            cout<<"________________________________________________________________________________"<<endl;
        }
    } else
        error();
    mostrar.close();
    pausa();
}

void password::mostrarClave(string param_code)
{
    ifstream show; show.open("passwords.txt", ios::in);
    getline(show, codigo);
    while(!show.eof())
    {
        getline(show, propietario);
        getline(show, uso);
        getline(show, contenido);

        if(param_code == codigo){
            cout<<"______________________________________________________________________"<<endl;
            cout<<"| SKEY | CLAVE ENCONTRADA                                           ||"<<endl;
            cout<<"______________________________________________________________________"<<endl;

            cout<<" * C\242digo: "<<codigo<<endl;
            cout<<" * Usuario: "<<propietario<<endl;
            cout<<" * Uso: "<<uso<<endl;
            cout<<" * Clave: "<<contenido<<endl;
            cout<<"\n\n";
        }

        getline(show,codigo);
    }

    show.close();
}

void password::show_menus(int option)
{
    switch(option)
    {
        case 1:
            system("cls");
            cout<<"______________________________________________________________________"<<endl;
            cout<<"| SKEY | CREAR CLAVE                                                 ||"<<endl;
            cout<<"______________________________________________________________________"<<endl;
            fflush(stdin);
        break;
        case 2:
        system("cls");
            cout<<"______________________________________________________________________"<<endl;
            cout<<"| SKEY |  UPS! HUBO UN PROBLEMA                                      |"<<endl;
            cout<<"|                                                                    |"<<endl;
            cout<<"| ERROR AL GENERAR LA CLAVE                                          |"<<endl;
            cout<<"______________________________________________________________________"<<endl;

            cout<<"\n\nYa existe una clave con ese c\242digo!\n\n";

        break;
        case 3:
        system("cls");
        cout<<"______________________________________________________________________"<<endl;
        cout<<"| SKEY | CREAR CLAVE                                                 ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;
        cout<<"\n\n";
        cout<<" Por favor, completa los siguientes datos. "<<endl;
        break;
        case 4:
            cout<<"Ingrese la forma en que desea que se genere la clave. "<<endl;
            cout<<" 1- Manual";
            cout<<" 2- Automatica." <<endl;
            cout<<"\n";
            cout<<" - Opcion: ";

        break;
        case 5:
            system("cls");
            cout<<"_______________________________________________________"<<endl;
            cout<<"| SKEY | GENERANDO CLAVE AUTOMATICA.                  |"<<endl;
            cout<<"| SELECCIONE LA CANT. DE CARACTERES DE LA CLAVE       |"<<endl;
            cout<<"|_____________________________________________________|"<<endl;
            cout<<"\n\n";
            cout<<" 1- 4 caracteres."<<endl;
            cout<<" 2- 8 caracteres."<<endl;
            cout<<"\n";
            cout<<" Opcion: ";

        break;

        case 6:
           system("cls");
        cout<<"______________________________________________________________________"<<endl;
        cout<<"| SKEY | ¡CLAVE GENERADA CON EXITO!                                 ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;

        break;
    }
}
void password::ShowMenusModificarClaves(int option)
{
    switch(option)
    {
        case 1:
            system("cls");
            cout<<"______________________________________________________________________"<<endl;
            cout<<"|    SKEY | MODIFICAR LOS DATOS DE CLAVE                            ||"<<endl;
            cout<<"______________________________________________________________________"<<endl;
            cout<<"|    COMPLETA LOS DATOS ESPECIFICADOS A CONTINUACION                ||"<<endl;
            cout<<"______________________________________________________________________"<<endl;
        break;
        case 2:
            system("cls");
            cout<<"______________________________________________________________________"<<endl;
            cout<<"|    SKEY | MODIFICAR LOS DATOS DE CLAVE                            ||"<<endl;
            cout<<"______________________________________________________________________"<<endl;

            cout<<" Ingresa la nueva informaci\242n para la clave\n\n";
            fflush(stdin);
            cout<<" *Ingresa tu nombre de usuario: ";
        break;
        case 3:
            system("cls");
            cout<<"______________________________________________________________________"<<endl;
            cout<<"|    SKEY | :( ERROR AL MODIFICAR LA CLAVE                          ||"<<endl;
            cout<<"______________________________________________________________________"<<endl;
            cout<<"\n\nYa existe una clave con ese c\242digo!\n\n";
        break;
        case 4:
        system("cls");
        cout<<"______________________________________________________________________"<<endl;
        cout<<"|    SKEY | MODIFICAR LOS DATOS DE CLAVE                            ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;

        cout<<"Ingresa el c\242digo del clave que deseas modificar: ";
        break;
        case 5:
        system("cls");
        cout<<"__________________________________________________________________________"<<endl;
        cout<<"|    SKEY | LA INFORMACION DE LA CLAVE SE HA MODIFICADO CORRECTAMENTE   ||"<<endl;
        cout<<"__________________________________________________________________________"<<endl;
        break;
        case 6:
        system("cls");
        cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";

        break;
    }
}
void password::ShowErrorInputs()
{
    cout<<"_______________________________________________________";
    cout<<"| SKEY |                                              |";
    cout<<"| ERROR EN INGRESO DE DATOS                           |";
    cout<<"_______________________________________________________";
    cout<<"|  C\242digo de clave no v\240lido, ingrese nuevamente|";
    cout<<" ";
}


void password::ShowGenerationPass()
{
     cout<<"______________________________________________________________________"<<endl;
    cout<<"| SKEY | ESTAMOS GENERANDO TU CLAVE...                              ||"<<endl;
    cout<<"| YA FALTA POCO...                                                  ||"<<endl;
    cout<<"______________________________________________________________________"<<endl;

}

void password::ShowMenusEliminarClave(int option)
{
    switch(option)
    {
        case 1:
        cout<<"______________________________________________________________________"<<endl;
        cout<<"| SKEY | ELIMINAR CLAVE                                             ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;
        break;
        case 2:
        cout<<"______________________________________________________________________"<<endl;
        cout<<"| SKEY | ELIMINAR CLAVE                                             ||"<<endl;
        cout<<"| INFORMACION DE LA CLAVE:                                          ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;
        break;
        case 3:
            cout<<"______________________________________________________________________"<<endl;
            cout<<"| SKEY | ELIMINAR CLAVE                                             ||"<<endl;
            cout<<"| LA CLAVE SE HA DADO DE BAJA CORRECTAMENTE.                        ||"<<endl;
            cout<<"______________________________________________________________________"<<endl;
        break;
        case 4:
        cout<<"______________________________________________________________________"<<endl;
        cout<<"| SKEY | ELIMINAR CLAVE                                             ||"<<endl;
        cout<<"| LA CLAVE NO SE HA DADO DE BAJA CORRECTAMENTE.                     ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;
        break;
    }
}

void password::error()
{
    cout<<"No se pudo abrir el archivo de claves, asegurate que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"passwords.txt, si el archivo tiene otro nombre renombralo al ya mencionado\n\n";
}

void password::pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system("cls");
    password p;
    p.gotomenu();
}

void password::gotomenu()
{
    password p;
    p.menuPrincpal_pass();
}

void password::info()
{
    system("cls");
    cout<<"________________________________________________________________________"<<endl;
    cout<<"|INFORMACION DE SKEY                                                  ||"<<endl;
    cout<<"|                                                                     ||"<<endl;
    cout<<"|        XXXXXXXXXXXXXXXXXXXXX         | SKEY INC.                    ||"<<endl;
    cout<<"|        SISTEMA DE GENERACION         |                              ||"<<endl;
    cout<<"|        CODIGOS 'SKEY'                |                              ||"<<endl;
    cout<<"|        XXXXXXXXXXXXXXXXXXXXX         |                              ||"<<endl;
    cout<<"_______________________________________________________________________ "<<endl;

    cout<<"Desarrollado por: governor17"<<endl;
    cout<<"Nombre oficial: SKey"<<endl;
    cout<<"Creado el 17/11/2019"<<endl;
    cout<<"Sitio oficial: SkeyProject.github.io"<<endl;

    cout<<"Saludos."<<endl;
    pausa();
}
