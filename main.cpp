#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include<time.h>
#include <windows.h>

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;
class menu
{
    private:
        string nombre;
        string FechaPago;
        int opc_FechaPago;
        string codigoCliente;
        string username_user;

    public:
        void crearClave();
        void eliminarClave();
        void modificarClave();
        void menuPrincipal();
        void verClaves();
        void mostrarClave(string codigo);
        void ayuda();
        void info();
        void huevo_boca();
        void huevo_1();
};

class User{

    public:
        string nombreU;
        string username;
        string password;


    public:
        void login();
        void registro();
        void errorU();
        void pauseU();


};


void User::login(){


    string auxCodigo;
    ifstream mostrar;
    int opcion;
    bool encontrado=false;
    mostrar.open("usuarios.txt",ios::in);
    system("cls");
    Sleep(10);
    if(encontrado == false)
    {

        getline(cin,auxCodigo);
        getline(mostrar,username);
        while(!mostrar.eof())
        {
            getline(mostrar,nombreU);
            getline(mostrar,password);

            if(auxCodigo != username)
            {
                system("cls");
                encontrado = false;
                cout<<"______________________________________________________________________"<<endl;
                cout<<"| INICIANDO SESION EN  SKEY                                           ||"<<endl;
                cout<<"|                                                                     ||"<<endl;
                cout<<"|        XXXXXXXXXXXXXXXXXXXXX         | SKEY INC.                    ||"<<endl;
                cout<<"|        SISTEMA DE GENERACION         |                              ||"<<endl;
                cout<<"|        CODIGOS 'SKEY'                |                              ||"<<endl;
                cout<<"|        XXXXXXXXXXXXXXXXXXXXX         |                              ||"<<endl;
                cout<<"______________________________________________________________________"<<endl;


                cout<<" * Ingresa tu nombre de usuario:  ";
                getline(cin,auxCodigo);
            }

            
            if(auxCodigo == username)
            {

                encontrado=true;
                system("cls");
                cout<<"\n\nTodo OK!\n\n";
                cout<<"Hola  "<<nombreU;
                cout<<" Bienvenido a SKEY"<<endl;
                cout<<"\n\n";
                Sleep(10);
                menu claves;
                claves.menuPrincipal();
            }

            getline(mostrar,username);


        }



        if(encontrado == false)
        {
                system("cls");
                cout<<"______________________________________________________________________"<<endl;
                cout<<"|  ERROR AL ACCEDER A SKEY                                          ||"<<endl;
                cout<<"______________________________________________________________________"<<endl;
                cout<<endl;
                cout<<" Ups! No te tenemos registrado. ¿Queres registrate?"<<endl;
                cout<<" 1. Si"<<endl;
                cout<<" 2. No"<<endl;
                cout<<"\n Opcion: ";
                cin>>opcion;

                Sleep(10);

                if(opcion == 1){
                    registro();

                }
        }




    }
    mostrar.close();
    pauseU();
    errorU();




}

void User::registro(){

    int opc_FechaPago, cant_caracteres, i=0;
    char mi_clave4[4], mi_clave8[8];

    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("usuarios.txt",ios::in);
    escritura.open("usuarios.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        system("cls");
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
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                //pantalla de error. limpiar pantalla
                cout<<" *Ingresa tu nombre de usuario: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,username);
            while(!verificador.eof())
            {
                getline(verificador,nombreU);
                getline(verificador,password);

                if(username==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe una clave con ese c\242digo!\n\n";
                    cout<<"Ingresa un nombre de usuario v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"Nombre de usuario no valido, intenta nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,username);
            }

            if(verificador.eof()&&auxCodigo!=username)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        username = auxCodigo;

        cout<<"______________________________________________________________________"<<endl;
        cout<<"|CREANDO TU CUENTA SKEY...                                           ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;


        cout<<" *Nombre de usuario: ";
        cout<<username;
        cout<<"\n\n";
        fflush(stdin);
        cout<<" *Nombre: ";
        getline(cin,nombreU);
        cout<<"\n\n";
        fflush(stdin);


        cout<<"\n\n";
        cout<<" *Contraseña:";
        cin>>password;
        fflush(stdin);
        cout<<"\n\n";

        escritura<<username<<"\n"<<nombreU<<"\n"<<password<<"\n";

        cout<<"______________________________________________________________________"<<endl;
        cout<<"| TU CUENTA SE HA CREADO CON EXITO                                    ||"<<endl;
        cout<<"| BIENVENIDO A SKEY.                                                  ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;

    }

    else
    {
        cout<<"______________________________________________________________________"<<endl;
        cout<<"|  SKEY | FATAL ERROR                                               ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;
        cout<<endl;
        cout<<"No se pudo abrir el archivo de claves, asegurate que el archivo se encuentre en";
        cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame:";
        cout<<"usuarios.txt, si el archivo tiene otro nombre renombralo al ya mencionado";

    }

    escritura.close();
    verificador.close();
    pauseU();

}

 void pausa();
 void error();

void menu::menuPrincipal()
{
    system("cls");
    int opcion;
    do
    {

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
        cout<<"|        5. Ayuda                         |                              ||"<<endl;
        cout<<"|        6. Informacion                   |                              ||"<<endl;
        cout<<"|        7. Salir                         |                              ||"<<endl;
        cout<<"___________________________________________________________________________"<<endl;

        cout<<"\n\n";
        cout<<" *Opci\242n: ";
        cin>>opcion;
        system(CLEAR);
        switch(opcion)
        {
        default:
            cout<<endl;
            cout<<endl;
            cout<<"______________________________________________________________________"<<endl;
            cout<<"| SKEY | FATAL ERROR                                                 ||"<<endl;
            cout<<"______________________________________________________________________"<<endl;


            cout<<"Ingresaste una opci\242n no valida!\n\n";
            break;

        case 1:
            crearClave();
            break;

        case 2:
            verClaves();
            break;


        case 3:
            eliminarClave();
            break;

        case 4:
            modificarClave();
            break;

        case 5:
            ayuda();
            break;
        case 6:
            info();
            break;

        case 7:
            system("cls");
            cout<<"Cerrando sesion de SKEY..."<<endl;
            Sleep(10);

            break;
        
        }
    }
    while(opcion!=7);
    pausa();
}

void menu::crearClave()
{

    User usuario;
    string nombre_user = usuario.nombreU;
    string username_user = usuario.username;
    string pass_user = usuario.password;

    int opc_FechaPago, cant_caracteres, i=0;
    char mi_clave4[4], mi_clave8[8];
    char digito[24];
    char cadena[36]=
    {
        'A','B','C','D','E','F','G','H','I','J','K','L',
        'M','N','O','P','Q','R','S','T','U','V','W','X',
        'Y','Z','0','1','2','3','4','5','6','7','8','9'
    };
    ofstream escritura;
    ifstream verUser;
    ifstream verificador;
    string auxCodigo;
    string auxUsername;
    bool coincidencia = false;
    bool controlador = false;
    verificador.open("clientes.txt",ios::in);
    escritura.open("clientes.txt",ios::app);

    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"______________________________________________________________________"<<endl;
        cout<<"| SKEY | CREAR CLAVE                                                 ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;

        fflush(stdin);

        cout<<" *Ingresa tu nombre de usuario";
        getline(cin,auxUsername);


        cout<<" *Ingresa el c\242digo de clave: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<"c\242digo de clave no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,codigoCliente);
            while(!verificador.eof())
            {
                getline(verificador,nombre);
                getline(verificador,FechaPago);

                if(codigoCliente==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"______________________________________________________________________"<<endl;
                    cout<<"| SKEY |  :( ERROR AL CREAR LA CLAVE...                             ||"<<endl;
                    cout<<"______________________________________________________________________"<<endl;


                    cout<<"\n\nYa existe una clave con ese c\242digo!\n\n";
                    cout<<"La clave con ese c\242digo es: "<<nombre<<"\n\n";
                    cout<<"Ingresa un c\242digo v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"\nc\242digo de clave no v\240lido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,codigoCliente);
            }

            if(verificador.eof()&&auxCodigo!=codigoCliente)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        codigoCliente=auxCodigo;
        username_user = auxUsername;

        cout<<"______________________________________________________________________"<<endl;
        cout<<"| SKEY | CREAR CLAVE                                                 ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;


        cout<<" *Clave de: ";
        cout<<username_user<<endl;

        cout<<" *C\242digo de la clave: ";
        cout<<codigoCliente<<endl;
        fflush(stdin);
        cout<<" *Ingresa el uso de la clave: ";
        getline(cin,nombre);
        fflush(stdin);
        cout<<endl;




        cout<<" *Ingresa la forma de crear la clave: \n"<<endl;
        cout<<"1- Manual"<<endl;
        cout<<"2- Automatica"<<endl;
        cout<<" Opci\242n: ";
        cin>>opc_FechaPago;


        if(opc_FechaPago == 1){
            cout<<" *Ingresa tu clave (MANUALMENTE):";
            cin>>FechaPago;
            fflush(stdin);

        }
        else
        {
            if(opc_FechaPago == 2){
                 cout<<" *Cantidad de caracteres: "<<endl;
                    cout<<" 1. 4 caracteres"<<endl;
                    cout<<" 2. 8 caracteres"<<endl;
                    cin>>cant_caracteres;


                    switch(cant_caracteres)
                    {
                        case 1:
                            system("cls");

                            cout<<"______________________________________________________________________"<<endl;
                            cout<<"| SKEY | ESTAMOS GENERANDO TU CLAVE...                              ||"<<endl;
                            cout<<"| YA FALTA POCO...                                                  ||"<<endl;
                            cout<<"______________________________________________________________________"<<endl;

                            cout<<" *Clave generada: ";
                            srand(time(NULL)); //Para que los numeros sean realmente aleatorios
                             for(i=0;i<=4;i++)
                            {
                                digito[i]=cadena[rand() % 35]; //numero aleatorio entre 0 y 35
                                printf("%c",digito[i]);
                                mi_clave4[i] = digito[i];

                            }

                             fflush(stdin);
                          cout<<" *Ingresa la clave generada: ";
                          getline(cin,FechaPago);


                            break;





                        case 2:
                            system("cls");

                            cout<<"______________________________________________________________________"<<endl;
                            cout<<"| SKEY | ESTAMOS GENERANDO TU CLAVE...                              ||"<<endl;
                            cout<<"| YA FALTA POCO...                                                  ||"<<endl;
                            cout<<"______________________________________________________________________"<<endl;

                            cout<<"\n\n";
                            cout<<"\n *Clave generada: ";

                            srand(time(NULL)); //Para que los numeros sean realmente aleatorios

                            for(i=0;i<=8;i++)
                            {
                                digito[i]=cadena[rand() % 35]; //numero aleatorio entre 0 y 35
                                printf("%c",digito[i]);
                                mi_clave8[i] = digito[i];

                            }

                             fflush(stdin);
                          cout<<"\n *Ingresa la clave: ";
                          getline(cin,FechaPago);


                            break;


                    }
            }
        }




        cout<<"\n\n";

        escritura<<codigoCliente<<"\n"<<username_user<<"\n"<<nombre<<"\n"<<FechaPago<<"\n";
        system("cls");
        cout<<"______________________________________________________________________"<<endl;
        cout<<"| SKEY | ¡CLAVE GENERADA CON EXITO!                                 ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;

    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
    pausa();
}

void menu::eliminarClave()
{
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    string auxCodigo;
    char respuesta[5];
    lectura.open("clientes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"______________________________________________________________________"<<endl;
    cout<<"| SKEY | ELIMINAR CLAVE                                             ||"<<endl;
    cout<<"______________________________________________________________________"<<endl;

    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);

        cout<<" *Ingresa el c\242digo de la clave que deseas dar de baja: ";
        getline(cin,auxCodigo);
        getline(lectura,codigoCliente);
        while(!lectura.eof())
        {
            getline(lectura, username_user);
            getline(lectura,nombre);
            getline(lectura,FechaPago);

            if(auxCodigo==codigoCliente)
            {
                encontrado=true;
                system("cls");
                cout<<"______________________________________________________________________"<<endl;
                cout<<"| SKEY | ELIMINAR CLAVE                                             ||"<<endl;
                cout<<"| INFORMACION DE LA CLAVE:                                          ||"<<endl;
                cout<<"______________________________________________________________________"<<endl;

                cout<<" *Clave de: "<<username_user<<endl;
                cout<<" *C\242digo: "<<codigoCliente<<endl;
                cout<<" *Uso: "<<nombre<<endl;
                cout<<" *Clave: "<<FechaPago<<endl;
                cout<<"\n\n";
                cout<<" ¿Realmente deseas dar de baja a la clave de: "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    system("cls");
                    cout<<"______________________________________________________________________"<<endl;
                    cout<<"| SKEY | ELIMINAR CLAVE                                             ||"<<endl;
                    cout<<"| LA CLAVE SE HA DADO DE BAJA CORRECTAMENTE.                        ||"<<endl;
                    cout<<"______________________________________________________________________"<<endl;

                }

                else
                {
                    system("cls");
                    cout<<"______________________________________________________________________"<<endl;
                    cout<<"| SKEY | ELIMINAR CLAVE                                             ||"<<endl;
                    cout<<"| LA CLAVE SE HA DADO DE BAJA CORRECTAMENTE.                        ||"<<endl;
                    cout<<"______________________________________________________________________"<<endl;

                    auxiliar<<username_user<<"\n"<<codigoCliente<<"\n"<<nombre<<"\n"<<FechaPago<<"\n";

                }

            }
            else
            {
                auxiliar<<username_user<<"\n"<<codigoCliente<<"\n"<<nombre<<"\n"<<"\n"<<FechaPago<<"\n";
            }
            getline(lectura,codigoCliente);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("clientes.txt");
    rename("auxiliar.txt","clientes.txt");
    pausa();
}

void menu::verClaves()
{
    string auxCodigo;
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("clientes.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);

        cout<<"______________________________________________________________________"<<endl;
        cout<<"|*** SKEY | Consultar detalles de mi clave ***                      ||"<<endl;
        cout<<"______________________________________________________________________"<<endl;


        cout<<" *Ingresa el codigo de tu clave: ";
        getline(cin,auxCodigo);
        getline(mostrar,codigoCliente);
                    system("cls");

        while(!mostrar.eof())
        {
            getline(mostrar,username_user);
            getline(mostrar,nombre);
            getline(mostrar,FechaPago);

            if(auxCodigo==codigoCliente)
            {
                encontrado=true;

                cout<<"______________________________________________________________________"<<endl;
                cout<<"|*** SKEY | Consultar detalles de mi clave ***                      ||"<<endl;
                cout<<"______________________________________________________________________"<<endl;
                cout<<"|Claves encontradas con exito                                       ||"<<endl;
                cout<<"______________________________________________________________________"<<endl;

                cout<<"\n\n"<<endl;

                cout<<" *C\242digo: "<< codigoCliente<<endl;
                cout<<" *Clave de: "<< username_user<<endl;
                cout<<" *Uso: "<< nombre<<endl;
                cout<<" *Clave: "<< FechaPago<<endl;
                cout<<"\n\n";
            }

            getline(mostrar,codigoCliente);
        }

        if(encontrado==false)
        {
            cout<<"________________________________________________________________________________"<<endl;
            cout<<"|ERROR: No se encontr\242 el c\242digo                                        ||"<<endl;
            cout<<"|"<<auxCodigo<<"                                                              ||";
            cout<<"________________________________________________________________________________"<<endl;


        }
    }

    else
    {
        error();
    }

    mostrar.close();
    pausa();
}


void menu::modificarClave()
{
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    string auxCodigo;
    string codigoModif;
    string auxNombre;
    string auxFecha;
    string auxUser;
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("clientes.txt",ios::in);
    verificador.open("clientes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);

    cout<<"\t\t\t\t***SKEY | Modificar los datos de clave***\t\t\t\t\n\n";

     cout<<"______________________________________________________________________"<<endl;
    cout<<"|    SKEY | MODIFICAR LOS DATOS DE CLAVE                            ||"<<endl;
    cout<<"______________________________________________________________________"<<endl;
    cout<<"|    COMPLETA LOS DATOS ESPECIFICADOS A CONTINUACION                ||"<<endl;
    cout<<"______________________________________________________________________"<<endl;


    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<" *Ingresa el c\242digo de la clave que deseas modificar: ";
        getline(cin,auxCodigo);

        if(auxCodigo=="")
        {
            do
            {
                cout<<" C\242digo de clave no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        }

        codigoModif=auxCodigo;

        getline(lectura,codigoCliente);
        while(!lectura.eof())
        {
            getline(lectura, username_user);
            getline(lectura,nombre);
            getline(lectura,FechaPago);

            if(auxCodigo==codigoCliente)
            {
                encontrado=true;
                mostrarClave(codigoModif);

                system("cls");
                cout<<"______________________________________________________________________"<<endl;
                cout<<"|    SKEY | MODIFICAR LOS DATOS DE CLAVE                            ||"<<endl;
                cout<<"______________________________________________________________________"<<endl;

                cout<<" Ingresa la nueva informaci\242n para la clave\n\n";
                fflush(stdin);
                cout<<" *Ingresa tu nombre de usuario: ";
                getline(cin, auxUser);
                cout<<" *Ingresa el c\242digo de la clave: ";
                getline(cin,auxCodigo);
                if(auxCodigo==codigoModif)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(auxCodigo==codigoModif)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        getline(verificador,codigoCliente);
                        while(!verificador.eof())
                        {
                            getline(verificador,nombre);
                            getline(verificador,FechaPago);

                            if(auxCodigo==codigoCliente)
                            {
                                coincidencia=true;
                                system("cls");
                                cout<<"______________________________________________________________________"<<endl;
                                cout<<"|    SKEY | :( ERROR AL MODIFICAR LA CLAVE                          ||"<<endl;
                                cout<<"______________________________________________________________________"<<endl;

                                cout<<"\n\nYa existe una clave con ese c\242digo!\n\n";
                                cout<<"La clave con ese c\242digo es para: "<<nombre<<"\n\n";
                                cout<<"Ingresa un c\242digo v\240lido!: ";
                                getline(cin,auxCodigo);

                                if(auxCodigo=="")
                                {
                                    do
                                    {
                                        cout<<"\nc\242digo de clave no v\240lido!, ";
                                        cout<<"intentalo nuevamente: ";
                                        getline(cin,auxCodigo);
                                    }
                                    while(auxCodigo=="");
                                }
                                break;
                            }

                            getline(verificador,codigoCliente);
                        }

                        if(verificador.eof()&&auxCodigo!=codigoCliente)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system(CLEAR);
                cout<<"______________________________________________________________________"<<endl;
                cout<<"|    SKEY | MODIFICAR LOS DATOS DE CLAVE                            ||"<<endl;
                cout<<"______________________________________________________________________"<<endl;

                cout<<"Ingresa el c\242digo del clave que deseas modificar: ";
                cout<<codigoModif;
                mostrarClave(codigoModif);
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para la clave\n\n";

                cout<<" *Ingresa tu nombre de usuario: ";
                getline(cin,auxUser);;
                fflush(stdin);

                cout<<" *Ingresa el c\242digo: ";
                cout<<auxCodigo;
                cout<<"\n\n";
                fflush(stdin);

                cout<<" *Ingresa el uso: ";
                getline(cin,auxNombre);;
                fflush(stdin);
                cout<<"\n\n";
                cout<<" *Ingresa la clave (MANUALMENTE): ";
                getline(cin,auxFecha);
                cout<<"\n\n";
                auxiliar<<auxUser<<"\n"<<auxCodigo<<"\n"<<auxNombre<<"\n"<<auxFecha<<"\n";
                system("cls");
                cout<<"__________________________________________________________________________"<<endl;
                cout<<"|    SKEY | LA INFORMACION DE LA CLAVE SE HA MODIFICADO CORRECTAMENTE   ||"<<endl;
                cout<<"__________________________________________________________________________"<<endl;
            }


            else
            {

                auxiliar<<username_user<<"\n"<<codigoCliente<<"\n"<<nombre<<"\n"<<FechaPago<<"\n";
            }


            getline(lectura,codigoCliente);
        }

    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("clientes.txt");
    rename("auxiliar.txt","clientes.txt");
    pausa();
}

void menu::ayuda()
{
        
        int opc_preg;
        cout<<"________________________________________________________________________"<<endl;
        cout<<"| SKEY - AYUDA                                                        ||"<<endl;
        cout<<"|                                                                     ||"<<endl;
        cout<<"|        XXXXXXXXXXXXXXXXXXXXX         | SKEY INC.                    ||"<<endl;
        cout<<"|        SISTEMA DE GENERACION         |                              ||"<<endl;
        cout<<"|        CODIGOS 'SKEY'                |                              ||"<<endl;
        cout<<"|        XXXXXXXXXXXXXXXXXXXXX         |                              ||"<<endl;
        cout<<"_______________________________________________________________________ "<<endl;
        cout<<"| PREGUNTAS FRECUENTES                                                ||"<<endl;
        cout<<"|                                                                     ||"<<endl;
        cout<<"|        1.Como creo una cuenta en SKey?                              ||"<<endl;
        cout<<"|        2.Que puedo hacer en SKey?                                   ||"<<endl;
        cout<<"|        3.Como puedo crear una clave?                                ||"<<endl;
        cout<<"|        4.Cual es la finalidad de SKey?                              ||"<<endl;
        cout<<"|        5.Como se crean las claves en SKey?                          ||"<<endl;
        cout<<"|        6.Consejos si se quiere crear una clave manualmente          ||"<<endl;
        cout<<"_______________________________________________________________________ "<<endl;
        cout<<"|                                                                     ||"<<endl;
        cout<<"|        #Pregunta seleccionada:                                      ||"<<endl;

        cin>>opc_preg;
        
        switch (opc_preg)
        {
            
            default:
                system("cls");
                    cout<<endl;
                    cout<<endl;
                    cout<<"______________________________________________________________________"<<endl;
                    cout<<"| SKEY | FATAL ERROR                                                 ||"<<endl;
                    cout<<"______________________________________________________________________"<<endl;
                    cout<<"Pregunta seleccionada no valida. \n\n";
                    break;
            case 1:
                system("cls");
                cout<<endl;
                cout<<"___________________________________________________________________________"<<endl;
                cout<<"| SKEY | AYUDA                                                           ||"<<endl;
                cout<<"___________________________________________________________________________"<<endl;
                cout<<"|                                                                        ||"<<endl;
                cout<<"| 1.Como creo una cuenta en SKey?                                        ||"<<endl;
                cout<<"|                                                                        ||"<<endl;
                cout<<"| Para crear una cuenta en SKey, podes seleccionar la opcion 2 que se    ||"<<endl;
                cout<<"| encuentra en el menu principal, al iniciar el programa.                ||"<<endl;
                cout<<"| Al elegir esa opcion, tendras que llenar un formulario con tus datos:  ||"<<endl;
                cout<<"|      *Nombre completo                                                  ||"<<endl;
                cout<<"|      *Nommbre de usuario                                               ||"<<endl;
                cout<<"|      *Clave                                                            ||"<<endl;
                cout<<"|                                                                        ||"<<endl;
                cout<<"___________________________________________________________________________"<<endl;
                break;


            case 2:
                system("cls");
                cout<<endl;
                cout<<"___________________________________________________________________________"<<endl;
                cout<<"| SKEY | AYUDA                                                           ||"<<endl;
                cout<<"___________________________________________________________________________"<<endl;
                cout<<"|                                                                        ||"<<endl;
                cout<<"| 2.Que puedo hacer en SKey?                                             ||"<<endl;
                cout<<"|                                                                        ||"<<endl;
                cout<<"| En SKey, vas a poder crear, guardar, ver y eliminar claves para los    ||"<<endl;
                cout<<"| distintos usos que les des. Las mismas pueden generarse de aleatoria   ||"<<endl;
                cout<<"| o manualmente.                                                         ||"<<endl;
                cout<<"___________________________________________________________________________"<<endl;
                break;
        
            case 3:
                system("cls");
                cout<<endl;
                cout<<"_______________________________________________________________________________"<<endl;
                cout<<"| SKEY | AYUDA                                                               ||"<<endl;
                cout<<"_______________________________________________________________________________"<<endl;
                cout<<"|                                                                            ||"<<endl;
                cout<<"| 3.Como puedo crear una clave?                                              ||"<<endl;
                cout<<"|                                                                            ||"<<endl;
                cout<<"| Para crear una clave en SKey, vas a tener que seleccionar la opcion 1      ||"<<endl;
                cout<<"| del menu de codigos. Una vez ahi, vas a tener que ingresar:                ||"<<endl;
                cout<<"|       *Nombre de usuario                                                   ||"<<endl;
                cout<<"|       *Codigo de la nueva clave                                            ||"<<endl;
                cout<<"|       *Uso de la nueva clave                                               ||"<<endl;
                cout<<"|       *Ingresar la forma de crear la clave (Manual - Automatica)           ||"<<endl; 
                cout<<"|         *Si se elige la forma manual, deberas de ingresar la clave a       ||"<<endl;
                cout<<"|          guardar.                                                          ||"<<endl;
                cout<<"|         *En caso contrario, tendras que seleccionar la cantidad de         ||"<<endl;
                cout<<"|          caracteres que deseas que tenga la clave a generar                ||"<<endl;
                cout<<"|          (4 u 8 caracteres).                                               ||"<<endl;
	            cout<<"|             * Ingresar la clave generada.                                  ||"<<endl;
                cout<<"|       *Presionar enter para volver al menu de codigos.                     ||"<<endl;
                cout<<"|                                                                            ||"<<endl;
                cout<<"_______________________________________________________________________________"<<endl;
                break;


            case 4:
                system("cls");
                cout<<endl;
                cout<<"_____________________________________________________________________________"<<endl;
                cout<<"| SKEY | AYUDA                                                             ||"<<endl;
                cout<<"_____________________________________________________________________________"<<endl;
                cout<<"|                                                                          ||"<<endl;
                cout<<"| 4.Cual es la finalidad de SKey?                                          ||"<<endl;
                cout<<"|                                                                          ||"<<endl;
                cout<<"| La finalidad de SKey es que las personas no tengan que preocuparse con   ||"<<endl;
                cout<<"| tener que acordarse de multiples claves o codigos para lo que            ||"<<endl;
                cout<<"| sea, debido a que todos los codigos de ingrese el usuario, podran        ||"<<endl;
                cout<<"| guardarse, modificarse o, incluso, eliminarse.                           ||"<<endl;
                cout<<"| Ademas, tratamos de proporcionar claves que cumplen con los consejos     ||"<<endl;
                cout<<"| basicos de seguridad, ya que son combinaciones alfanumericas.            ||"<<endl;
                cout<<"_____________________________________________________________________________"<<endl;
                break;

            case 5:
                system("cls");
                cout<<endl;
                cout<<"___________________________________________________________________________"<<endl;
                cout<<"| SKEY | AYUDA                                                           ||"<<endl;
                cout<<"___________________________________________________________________________"<<endl;
                cout<<"|                                                                        ||"<<endl;
                cout<<"| 5.Como se crean las claves en Skey?                                    ||"<<endl;
                cout<<"|                                                                        ||"<<endl;
                cout<<"| En SKey, las claves se crean a partir de una combinacion aleatoria     ||"<<endl;
                cout<<"| entre letras (minusculas y mayusculas) y numeros, en base a la         ||"<<endl;
                cout<<"| cantidad de caracteres que haya elegido el usuario.                    ||"<<endl;
                cout<<"___________________________________________________________________________"<<endl;
                break;


            case 6:
                system("cls");
                cout<<endl;
                cout<<"_______________________________________________________________________________"<<endl;
                cout<<"| SKEY | AYUDA                                                               ||"<<endl;
                cout<<"_______________________________________________________________________________"<<endl;
                cout<<"|                                                                            ||"<<endl;
                cout<<"| 6.Consejos si se quiere crear una clave manualmente                        ||"<<endl;
                cout<<"|                                                                            ||"<<endl;
                cout<<"|                                                                            ||"<<endl;               
                cout<<"| * Hacer claves de una longitud mínima de 8 caracteres. Los caracteres      ||"<<endl;
                cout<<"|   vuelven a la contraseña más robusta.                                     ||"<<endl;
                cout<<"| * Realizar combinaciones alfanuméricas. Estas son más difíciles de         ||"<<endl;
                cout<<"|   descubrir, teniendo en cuenta las diversas posibilidades de              ||"<<endl;
                cout<<"|   combinación de los caracteres.                                           ||"<<endl;
                cout<<"| * Utilizar distintas claves para cada servicio. De esta manera, si la      ||"<<endl;
                cout<<"|   contraseña es revelada, será más difícil para el atacante acceder al     ||"<<endl;
                cout<<"|   resto de las plataformas del usuario.                                    ||"<<endl;
                cout<<"| * Evitar palabras comunes.                                                 ||"<<endl;
                cout<<"| * Cambiar periódicamente las claves. Esto aumenta el nivel de seguridad    ||"<<endl;
                cout<<"|   de las credenciales.                                                     ||"<<endl;
                cout<<"_______________________________________________________________________________"<<endl;
                break;

       
        }

        pausa();


}

void menu::info()
{
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

        cout<<"Saludos XD"<<endl;
        pausa();

}


void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system(CLEAR);
}

void User::pauseU()
{

    cout<<"Presiona Enter para continuar...";
    getch();
    system(CLEAR);

}

int main()
{

    system ("color 1F");


    int opcion;
    User inicio;
    User login;

    do
    {
        system("cls");
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
        cin>>opcion;
        switch(opcion)
        {

            default:
                cout<<endl;
                cout<<endl;
                cout<<"______________________________________________________________________"<<endl;
                cout<<"| SKEY | FATAL ERROR                                                 ||"<<endl;
                cout<<"______________________________________________________________________"<<endl;


                cout<<"Ingresaste una opci\242n no valida!\n\n";
                break;

            case 1:
                login.login();
                break;

            case 2:
                inicio.registro();
                break;

            case 3:
                system("cls");
                cout<<"Cerrando SKEY..."<<endl;
                break;


        }
    }
    while(opcion!=3);

    return 0;
}

void error()
{
    cout<<"No se pudo abrir el archivo de claves, asegurate que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre renombralo al ya mencionado\n\n";
}
void User::errorU()
{
    cout<<"No se pudo abrir el archivo de claves, asegurate que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre renombralo al ya mencionado\n\n";

}
void menu::mostrarClave(string codigo)
{

    ifstream mostrar;
    mostrar.open("clientes.txt",ios::in);
    getline(mostrar,codigoCliente);
    while(!mostrar.eof())
    {
        getline(mostrar, username_user);
        getline(mostrar,nombre);
        getline(mostrar,FechaPago);

        if(codigo==codigoCliente)
        {

            cout<<"______________________________________________________________________"<<endl;
            cout<<"| SKEY | CLAVE ENCONTRADA                                           ||"<<endl;
            cout<<"______________________________________________________________________"<<endl;

            cout<<" * C\242digo: "<<codigoCliente<<endl;
            cout<<" * Usuario: "<<username_user<<endl;
            cout<<" * Uso: "<<nombre<<endl;
            cout<<" * Clave: "<<FechaPago<<endl;
            cout<<"\n\n";
        }

        getline(mostrar,codigoCliente);
    }

    mostrar.close();
}
