#ifndef PRINCIPALMENU_H_INCLUDED
#define PRINCIPALMENU_H_INCLUDED
    #include <stdio.h>
	#include <stdlib.h>
	void menu_principal()
	{
			printf("\n________________________________________________________________________");
	        printf("\n|BIENVENIDO A SKEY                                                    ||");
	        printf("\n|                                                                     ||");
	        printf("\n|        XXXXXXXXXXXXXXXXXXXXX         | SKEY INC.                    ||");
	        printf("\n|        SISTEMA DE GENERACION         |                              ||");
	        printf("\n|        CODIGOS 'SKEY'                |                              ||");
	        printf("\n|        XXXXXXXXXXXXXXXXXXXXX         |                              ||");
	        printf("\n_______________________________________________________________________ ");
	        printf("\n|PARA CONTINUAR, SELECCIONA ALGUNAS DE LAS OPCIONES                   ||");
	        printf("\n|                                                                     ||");
	        printf("\n|        1-Iniciar sesion                                             ||");
	        printf("\n|        2-Crear cuenta                                               ||");
	        printf("\n|        3-Salir                                                      ||");
	        printf("\n________________________________________________________________________");

	        printf("\nOpcion: ");
	}

	void showError()
	{
		printf("\n");
		printf("\n______________________________________________________________________");
		printf("\n| SKEY | FATAL ERROR                                                 ||");
		printf("\n______________________________________________________________________");
		printf("\n");
		printf("\nIngresaste una opci\242n no valida");
	}


#endif // PRINCIPALMENU_H_INCLUDED
