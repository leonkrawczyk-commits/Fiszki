#ifndef _FISZKI_
#define _FISZKI_
#include <iostream>

class fiszki{
    public:
    std::string GetFront();
    std::string GetBack();
    void MarkCorrect();
    void MarkWrong();
    double GetDifficulty();



    private:
    std::string f; //przod fiszki
    std::string b; //tyl fiszki
    int c; //ilosc poprawnych odpowiedzi uzytkownika przy danej fiszce 
    int w; //ilosc blednych odpowiedzi uzytkownika przy danej fiszce
    double d; //wspolczynnik difficulty fiszki (liczony z int c oraz int w)
};

#endif