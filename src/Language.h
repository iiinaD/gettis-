//
// Created by danielh on 20-06-24.
//

#ifndef GETTISXX_LANGUAGE_H
#define GETTISXX_LANGUAGE_H

#include <string>
#include <vector>

using std::string;


class Language {
protected:

public:
    Language();
    ~Language();
    virtual string execute(string input);
    static std::vector<std::string> findFilesByExtension(std::vector<std::string> extensions);
    static string getFileContent(string fileName);
    virtual int test();

    static std::vector<string> findTrimmedFilesByExtension(std::vector<std::string> extensions);
};


#endif //GETTISXX_LANGUAGE_H
