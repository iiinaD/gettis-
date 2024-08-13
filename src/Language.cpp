//
// Created by danielh on 20-06-24.
//

#include "Language.h"
#include <string>
#include <utility>
#include <filesystem>
#include <iostream>
#include <fstream>
using std::string;

string Language::execute(string input) {
return "";
}

string Language::getFileContent(string fileName) {
    std::ifstream file(fileName);  // Open the file
    if (!file.is_open()) {  // Check if the file was successfully opened
        std::cerr << "Failed to open the file." << std::endl;
        return "";
    }
    std::string input = "";
    std::string line;
    while (std::getline(file, line)) {  // Read line by line
        input += line;
    }
    file.close();  // Close the file
    return input;
}

int Language::test(){
    return 0;
}


std::vector<std::string> Language::findFilesByExtension(std::vector<std::string> extensions) {

    std::vector<string> fileNames;

    // Iterate over each file in the directory
    for (const auto& entry : std::filesystem::directory_iterator(".")) {
        // Check if the current entry is a regular file and ends with the given extension. Looping through array since its faster then a set for smaller sizes
        for (const auto& ex : extensions) {
            if (entry.is_regular_file() && entry.path().extension() == ex) {
                fileNames.push_back(entry.path().filename().string());
            }
        }
    }

    return fileNames;

}


std::vector<std::string> Language::findTrimmedFilesByExtension(std::vector<std::string> extensions) {

    std::vector<string> fileNames;

    // Iterate over each file in the directory
    for (const auto& entry : std::filesystem::directory_iterator(".")) {
        // Check if the current entry is a regular file and ends with the given extension. Looping through array since its faster then a set for smaller sizes
        for (const auto& ex : extensions) {
            if (entry.is_regular_file() && entry.path().extension() == ex) {
                fileNames.push_back(entry.path().stem().string());
            }
        }
    }

    return fileNames;

}

string Language::getBoilerplate(string problemName){
    return "";
}

string Language::createFile(string fileName){
    string fullFileName = fileName + fileExtension[0];
    std::ofstream file(fullFileName);
    string content = getBoilerplate(fileName);
    file.write(content.c_str(), content.size());
    file.close();
    return fullFileName;
}

Language::Language() = default;

Language::~Language() = default;

