#ifndef CLASSUSER_H
#define CLASSUSER_H

    #include <iostream>
    #include <string>
    using namespace std;


    class user
    {
        public:
            string username;
            string name;
            string access_p;
            string ac_codification;
        public:
            void login();
            void newUser();
            void error_login();
            void pauseU();
            void errorU();
            void loginMenu();
            void WelcomeMessageToSkey();
            void ShowPasswordMenuPrincipal();
            void menuRegister();
            void error_register();
            void Showcoincidence();
            void ShowRegisterOk();
            void ShowRegisterFatalError();
            void menuCreatingAnAcount();
    };

#endif // CLASSUSER_H
