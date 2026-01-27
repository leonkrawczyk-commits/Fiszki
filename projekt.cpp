#include <iostream>
#include "fiszki.h"
#include "talie.h"
#include "managertalii.h"
#include "menu.h"

int main(){
    manager manager1;
    menu menu(manager1);
    menu.run();
    return 0;
};
