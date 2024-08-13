//
// Created by danielh on 08-07-24.
//

#include <fstream>
#include <iostream>
#include "ProjectSettings.h"
#include <toml++/toml.h>

ProjectSettings::ProjectSettings() {
    
}

void ProjectSettings::initSettings(string problemName, Language lang, string mainFile) {
    std::ofstream file(".gettis");
    string output = "";
    output += "lang = " + lang.lang + "\n";
    output += "mainfile = " + mainFile + "\n"; 
    output += "problem = " + problemName + "\n";
    file.write(output.c_str(), sizeof(int));
    file.close();
}

void ProjectSettings::parseSettings() {
    try {
        // Parse a TOML file
        auto data = toml::parse_file(".gettis");

        // Access values from the parsed data
        auto lang = data["Project_Settings"]["lang"].as_string();
        auto mainfile = data["Project_Settings"]["main_file"].as_string();
        auto problem = data["Project_Settings"]["problem"].as_string();

        std::cout << "Lang: " << *lang << std::endl;
        std::cout << "Mainfile: " << *mainfile << std::endl;
        std::cout << "Problem: " << *problem << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error parsing TOML: " << e.what() << std::endl;
        return;
    }
}