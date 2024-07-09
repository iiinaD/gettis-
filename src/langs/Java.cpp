//
// Created by danielh on 08-07-24.
//

#include <sstream>
#include "Java.h"


int Java::compile(string directoryName){
    std::vector<std::string> extensions = {".java"};
    std::vector<std::string> files = Language::findFilesByExtension(extensions);

    std::string filesString;
    for (const auto& entry : files) {
        filesString += entry + " ";
    }
    system(("javac -encoding UTF-8 " + filesString).c_str());
    return 0;
}

std::string Java::execute(string input) {
    std::stringstream output;
    /*
    // Open a pipe to another program
    FILE* pipe = popen("program_executable", "w");
    if (!pipe) {
        std::cerr << "Failed to open pipe to program_executable." << std::endl;
        return 1;
    }
    */
    return "";
}
