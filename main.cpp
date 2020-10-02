#include <iostream>
///design
#include "design/principalmenu.h"
#include "closeProgramm.h"
///login y register
#include "login/menuPrincipal.h"
///clases
#include "classPassword.h"
#include "classUser.h"

int main()
{
    //lamada a clases
    user u;
    system ("color 1F");
	int opcion;
    do{
        menu_principal();
        std::cin>>opcion;

		switch(opcion)
		{
			default:
				showError();
				break;
			case 1:
				u.login();
				break;
			case 2:
				u.newUser();
				break;
			case 3:
				closeSkey(); break;
		}
	}
	while(opcion!=3);

	return 0;
}
