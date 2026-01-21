#include "fiszki.h"

fiszki::fiszki(){
    
};

std::string GetFront(std::string f){
    return f;
};

std::string GetBack(std::string b){
    return b;
};

void MarkCorrect(int c,int w,double d){
    c = c + 1;
    d = d + c/(w+1);
};

void MarkWrong(int c,int w,double d){
    w = w + 1;
    d = d - w/(c+1);
};

double GetDifficulty(double d){
    return d;
};

