//
// Created by danielh on 08-07-24.
//

#ifndef GETTISXX_PROJECTSETTINGS_H
#define GETTISXX_PROJECTSETTINGS_H

#include <string>
#include "Language.h"

class ProjectSettings {
public:
    ProjectSettings();
    void initSettings(string problemName, Language lang, string mainFile);
    void parseSettings();
    std::string lang;
    std::string problem;
    std::string main_file;
};


#endif //GETTISXX_PROJECTSETTINGS_H
