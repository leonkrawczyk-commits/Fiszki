#include "menu.h"
#include "managertalii.h"
#include "talie.h"
#include <iostream>
#include <limits>


menu::menu(manager& manager1) : manager1(manager1) {}

void menu::PokazMenu(){
    std::cout << "   MENU GLOWNE"<<std::endl;
    std::cout << "1. Dodaj talie"<<std::endl;
    std::cout << "2. Usun talie"<<std::endl;
    std::cout << "3. Wybierz talie"<<std::endl;
    std::cout << "0. Wyjscie"<<std::endl;
};

void menu::PokazMenuTalii(talia& name1) {
    std::cout <<  name1.GetName() << std::endl;
    std::cout << "1. Dodaj fiszke" << std::endl;
    std::cout << "2. Usun fiszke"<< std::endl;
    std::cout << "3. Powtorka"<<std::endl;
    std::cout << "0. Powrot"<<std::endl;
};

void menu::MenuTalii(talia& name1) {
    int wybor;
    bool w_talii = true;
    while(w_talii) {
        PokazMenuTalii(name1);

        std::cin >> wybor;
        

        switch(wybor) {
            case 1:{ 
                name1.DodajFiszka(); 
                break;
            }
            case 2:{ 
                name1.UsunFiszka(); 
                break;
            }
            case 3:{ 
                name1.Powtorka(); 
                break;
            }
            case 0:{ 
                w_talii = false; 
                break;
            }
            default:{
                std::cout << "Nieprawidlowa opcja."<<std::endl;
                w_talii = false;
            }

        };
       
    };
};

void menu::run() {
    int wybor;
    bool w_menu = true;
    while(w_menu) {
        PokazMenu();

        std::cin >> wybor;

        switch(wybor) {
            case 1: {
                manager1.DodajTalia(); 
                break;
            }
            case 2: {
                manager1.UsunTalia(); 
                break;
            }
            case 3: {
                talia* name1 = manager1.WybierzTalie(); //to moze zwrocic nullptr
                if(name1){ //jak zwroci nie nullptr
                    MenuTalii(*name1);
                };
                break;
            }
            case 0:{ 
                w_menu = false; 
                break;
            }
            default: {
                std::cout << "Nieprawidlowa opcja"<<std::endl;
                w_menu = false;
            };
        };
    };
};