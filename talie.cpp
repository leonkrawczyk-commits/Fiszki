#include <iostream>
#include <vector>
#include <limits>
#include "talie.h"
#include "fiszki.h"

talia::talia(const std::string name1){
    name = name1;
};

void talia::DodajFiszka(){

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
    std::cout<< "Podaj numer fiszki do usuniecia: ";

    std::cin >> index;

    if(index<1){
        std::cout<<"Nieprawidlowy numer fiszki"<<std::endl;
        return;
    }

    else if(index>fiszki.size()){
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

void talia::Powtorka(){

    if(fiszki.empty()){
        std::cout<<"Talia pusta";
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

    

    while(!kolejka.empty()){

        int index = kolejka.back(); //bierzemy indeks fiszki (bedzie szlo od konca tabeli ale nie ma znaczenia)
        
        kolejka.pop_back(); //usuwamy index z kolejki
        
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
            if(odp == 'T', odp == 't'){
                fiszki[index].MarkCorrect();
                break;

            }else if(odp == 'N', odp == 'n'){
                fiszki[index].MarkWrong();
                kolejka.push_back(kolejka.at(0)); //kopiujemy index ostatniej (pierwszej) fiszki w kolejce na pierwsze miejsce w kolejce
                kolejka.at(0) = index; //w miejscu ostatniego indexu wpisujemy index fiszki na ktora opd byla bledna
                // w ten sposob fiszka na ktora uzytkownik odpowiedzial zle wroci w tej samej powtorce na samym koncu
                break;

            }else {
                std::cout<<"Nieprawidlowy input"<<std::endl;
            }; //petla powtorzy sie tylko gdy uzytkownik poda nieprawidlowy input
        };
    };
};