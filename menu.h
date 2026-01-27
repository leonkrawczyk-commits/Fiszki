#ifndef _MENU_
#define _MENU_
#include "managertalii.h"

class menu{

    public:
    menu(manager& manager1);
    void run(); //funkcja publiczna w ktorej wywolujemy inne prywatne metody klasy w zaleznosci od wyboru

    private:
    manager& manager1; //referencja na obiekt klasy manager z konstruktora domyslnego klasy manager

    void PokazMenu();
    void MenuTalii(talia& name1);
    void PokazMenuTalii(talia& name1);

};



#endif 