#include <iostream>
#include <vector>
#include <limits>
#include "talie.h"
#include "fiszki.h"
#include "managertalii.h"

void manager::DodajTalia(){
    std::string name1;
    std::cout<<"Podaj nazwe nowej talii: "<<std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name1);
    


    if(name1.empty()){
        std::cout<<"Nazwa nie moze byc pusta"<<std::endl;
        return;
    };

    talie.emplace_back(name1);

    std::cout<<"Talia dodana poprawnie"<<std::endl;

    
};


void manager::WypiszTalie(){
    std::cout<<"Dodane talie"<<std::endl;
    for(int i=0; i<talie.size(); i++){
        std::cout<< i+1 << ". " << talie[i].GetName() << std::endl;
    };
};


void manager::UsunTalia(){
    if(talie.empty()){
        std::cout<<"Brak talii do usuniecia"<<std::endl;
        return;
    };

    WypiszTalie();
    std::cout<<"0. Nie chce usuwac talii"<<std::endl;


    std::cout<<"Podaj numer talii do usuniecia"<<std::endl;

    int index;
    std::cin>> index;

    if(index == 0){
        return;
    };

    if(index<1 || index>talie.size()){
        std::cout<<"Nieprawidlowy numer talii"<<std::endl;
        return;
    };

    talie.erase(talie.begin() + index - 1);
    std::cout<<"Talia usunieta prawidlowo"<<std::endl;

};  

talia* manager::WybierzTalie(){
    if(talie.empty()){
        std::cout<<"Brak dodanych talii"<<std::endl;
        return nullptr;
    };

    WypiszTalie();

    std::cout<<"Wybierz talie"<<std::endl;

    int index;
    std::cin>> index;
    if(index<1, index>talie.size()){
        std::cout<<"Nieprawidlowy numer talii"<<std::endl;
        return nullptr;
    };

    return &talie[index - 1];
};