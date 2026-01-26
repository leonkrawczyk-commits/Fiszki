#ifndef _TALIA_
#define _TALIA_
#include <iostream>
#include <vector>
#include "fiszki.h"


class talia{

    public:

    talia(const std::string name1);

    void DodajFiszka();
    void UsunFiszka();
    void Powtorka();
    void WypiszFiszki();
    

    private:
    std::string name; //nazwa talii
    std::vector<fiszka> fiszki; //lista fiszek w danej talii
};




#endif