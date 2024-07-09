//
// Created by danielh on 20-06-24.
//

#ifndef GETTISXX_COMPILEDLANGUAGE_H
#define GETTISXX_COMPILEDLANGUAGE_H


#include <string>
#include "Language.h"
using std::string;

class CompiledLanguage : public Language {
public:
    CompiledLanguage();
    ~CompiledLanguage();
    virtual int compile();
    virtual int compile(string mainFile) = 0;
    string execute(string input) override = 0;
    int test();

};


#endif //GETTISXX_COMPILEDLANGUAGE_H
