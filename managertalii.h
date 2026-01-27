#ifndef _MANAGER_TALII_
#define _MANAGER_TALII_
#include "talie.h"
#include <vector>

class manager{

    public:
    void DodajTalia();
    void UsunTalia();
    void WypiszTalie();
    talia* WybierzTalie();
    
    private:
    std::vector<talia> talie;

};


#endif