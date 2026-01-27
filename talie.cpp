#include <iostream>
#include <vector>
#include <limits>
#include "talie.h"
#include "fiszki.h"

talia::talia(const std::string name1){
    name = name1;
};

void talia::DodajFiszka(){

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    std::string f;
    std::string b;



    std::cout<<"Przod fiszki: ";
    std::getline(std::cin, f);
    

    std::cout<<"Tyl fiszki: ";
    std::getline(std::cin, b);
   

    fiszki.emplace_back(f, b);
    std::cout<< "Fiszka dodana poprawnie" <<std::endl;

};

void talia::UsunFiszka(){
    int index;

    if(fiszki.empty()){
        std::cout << "Talia jest pusta" << std::endl;
        return;
    };

    WypiszFiszki();
    std::cout<<"0. Nie chce usuwac fiszki"<<std::endl;


    std::cout<< "Podaj numer fiszki do usuniecia: ";

    std::cin >> index;
    
    if(index==0){
        return;
    };

    if(index<1 || index>fiszki.size()){
        std::cout<<"Nieprawidlowy numer fiszki"<<std::endl;
        return;
    };


    fiszki.erase(fiszki.begin() + index -1);
    std::cout<<"Fiszka usunieta"<<std::endl;

};

void talia::WypiszFiszki(){

    if (fiszki.empty()){
        std::cout << "Talia pusta" << std::endl;
        return;
    };

    for(int i=0; i<fiszki.size(); i++){
        std::cout << i + 1 << ". Przod: " << fiszki[i].GetFront() << " Tyl: " <<fiszki[i].GetBack() << std::endl;
    };
};


std::string talia::GetName(){
    return name;

};void talia::Powtorka(){

    if(fiszki.empty()){
        std::cout<<"Talia pusta"<<std::endl;
        return;
    };

    std::vector<int> kolejka; 

    for(int i=0; i < fiszki.size(); i++){
        if(fiszki[i].GetDifficulty()>=0){
            kolejka.push_back(i);
        }
        else {
            fiszki[i].DifficultyPlus();
        };
    }; //petla tworzy vector indeksow fiszek ktore sa do powtorki, tak aby nie operowac bezposrednio na fiszkach 

    if(kolejka.empty()){
        std::cout<<"Brak fiszek potrzebujacych powtorki"<<std::endl;
        return;
    };

    while(!kolejka.empty()){

        int index = kolejka.front(); //bierzemy indeks fiszki 
        
        kolejka.erase(kolejka.begin()); //usuwamy index z kolejki
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Przod: "<<std::endl;
        std::cout<<fiszki[index].GetFront()<<std::endl;
        std::cout<<"Nacisnij ENTER aby zobaczyc odpowiedz."<<std::endl;
        std::cin.get();
        std::cout<<"Tyl: "<<std::endl;
        std::cout<<fiszki[index].GetBack()<<std::endl;
        std::cout<<"Poprawnie? T/N"<<std::endl;

        char odp;
        while(true){

            std::cin >> odp;

            if(odp == 'T' || odp == 't'){
                fiszki[index].MarkCorrect();
                break;

            }else if(odp == 'N' || odp == 'n'){
                fiszki[index].MarkWrong();
                kolejka.push_back(index); //dodajemy index na koniec kolejki
                break;

            }else {
                std::cout<<"Nieprawidlowy input. T/N?"<<std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }; //petla powtorzy sie tylko gdy uzytkownik poda nieprawidlowy input
        };
    };
};