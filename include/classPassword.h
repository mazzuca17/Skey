#ifndef CLASSPASSWORD_H
#define CLASSPASSWORD_H
    #include <iostream>
    #include <string>

    using namespace std;

    class password
    {
        private:
            string uso;
            string propietario;
            int opcion_formacion;
            string codigo;
            string contenido;

        public:
            void menuPrincpal_pass();
            void crearClave();
            void eliminarClave();
            void modificarClave();
            void verClaves();
            void mostrarClave(string param_code);
            void show_menus(int );
            void ShowErrorInputs(); void ShowGenerationPass(); void error(); void pausa(); void gotomenu();
            void ShowMenusModificarClaves(int);
            void info();
            void ShowMenusEliminarClave(int);
    };

#endif // CLASSPASSWORD_H
