#include "fiszki.h"

fiszka::fiszka(const std::string f1, const std::string b1){
    c = 0;
    w = 0;
    d = 1;
    f = f1;
    b = b1;
};

std::string fiszka::GetFront(){
    return f;
};

std::string fiszka::GetBack(){
    return b;
};

void fiszka::MarkCorrect(){
    c = c + 1;
    d = d - c/(w+1);
};

void fiszka::MarkWrong(){
    w = w + 1;
    d = d + w/(c+1);
};

double fiszka::GetDifficulty(){
    return d;
};

void fiszka::DifficultyPlus(){
    d = d + 1;
};

