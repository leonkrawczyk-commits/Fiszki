#ifndef _FISZKI_
#define _FISZKI_
#include <iostream>

class fiszka{
    public:
    fiszka(const std::string f1, const std::string b1);

    std::string GetFront();
    std::string GetBack();
    void MarkCorrect(); //zwieksza c fiszki o 1 a potem zmniejsza jej d zgdonie z algorytmem 
    void MarkWrong(); //zwieksza w, zwieksza d
    double GetDifficulty(); //fiszka bedzie wyswietlana w powtorce tylko gdy jej d jest >=0
    void DifficultyPlus(); //gdy fiszka nie zostanie wywolana w powtorce, jej d zwieksza sie o jeden tak aby miala szanse jeszcze kiedys sie pojawic
    


    private:
    std::string f; //przod fiszki
    std::string b; //tyl fiszki
    int c; //ilosc poprawnych odpowiedzi uzytkownika przy danej fiszce 
    int w; //ilosc blednych odpowiedzi uzytkownika przy danej fiszce
    double d; //wspolczynnik difficulty fiszki (liczony z int c oraz int w)
};

#endif