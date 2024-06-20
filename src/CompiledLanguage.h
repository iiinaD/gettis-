//
// Created by danielh on 20-06-24.
//

#ifndef GETTISXX_COMPILEDLANGUAGE_H
#define GETTISXX_COMPILEDLANGUAGE_H


#include <string>
#include "Language.h"
using std::string;

class CompiledLanguage : Language{
    string compiler;
    int compile();
};


#endif //GETTISXX_COMPILEDLANGUAGE_H
