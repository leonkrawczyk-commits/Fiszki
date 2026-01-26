#ifndef _MANAGER_TALII_
#define _MANAGER_TALII_
#include "talie.h"
#include <vector>

class Manager{

    public:
    void AddTalia();
    void RemoveTalia();
    void WypiszTalie();
    talia* WybierzTalie();
    
    private:
    std::vector<talia> talie;

};

#endif