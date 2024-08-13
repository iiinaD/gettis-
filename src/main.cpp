#include <iostream>
#include <curl/curl.h>
#include <unordered_map>
#include <filesystem>
#include <fstream>
#include "Language.h"
#include "CompiledLanguage.h"
#include "langs/Java.h"
#include "ProjectSettings.h"


using std::string;

void decompressFile(string inputFile) {
    std:string command = "unzip ";
    command += inputFile;

    int returnCode = system(command.c_str());
    system(("rm " + inputFile).c_str());
}

void getTestFiles(string fileName) {
    CURL *curl;
    CURLcode res;
    FILE *file;
    const char *url = "https://open.kattis.com/problems/twosum/file/statement/samples.zip";
    //const char *fileName = "samples.zip";

    curl = curl_easy_init();
    if(curl) {

        file = fopen(fileName.c_str(),"wb");
        if(file == NULL){
            std::cerr << "Error opening file" << fileName << std::endl;
            return;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url); //Set the url to be curled from
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL); //Makes it so libcurl dosent handle the data on its own
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file); //Makes libcurl write the results to the file

        /* Perform the request, res gets the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            std::cout << "\nDownload completed successfully\n";
        }
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(file); //Closing the file
    }
    decompressFile(fileName);
}

void initialiseProject(string problemName){
    
}

void initialiseProject(string problemName, Language& lang){
    string camelProblemName = problemName;
    camelProblemName[0] = std::toupper(camelProblemName[0]);
    std::cout << camelProblemName << std::endl;
    std::filesystem::create_directory(camelProblemName.c_str()); // mkdir in current directory with problem name
    system(("cd " + camelProblemName).c_str());
    // download test files and extract
    getTestFiles(problemName);
    // Make main file
    string filename = lang.createFile(camelProblemName);
    // Make project settings file
    ProjectSettings *ps = new ProjectSettings();
    ps->initSettings(camelProblemName, lang, filename);
    delete ps;
}

std::unordered_map<string, char> COMMANDS = {
        {"init", 'i'},
        {"test", 't'},
        {"submit", 's'},
        {"help", 'h'}
};

std::unordered_map<string, Language*> LANGUAGE = {
        {"java", new Java()}
};



int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "Incorrect usage of the gettis command. See \"gettis help\" for more info" << std::endl;
    }
    // Read the command
    //char command = COMMANDS[argv[1]];
    char command = 'i';
    new ProjectSettings();

    switch (command) {
        case 'i':
            // Run init
            initialiseProject("twosum", *LANGUAGE["java"]);
            break;
        case 't':
            // Run test
            break;
        case 's':
            // Run submit
            break;
        case 'h':
            // Run help
            break;
        default:

            break;
    }


    //const char* fileName = "samples.zip";
    //getTestFiles(fileName);

    //std::vector<string> result = Language::findTrimmedFilesByExtension({".in"});

    /*for (const auto& entry : result) {
        std::cout << entry << std::endl;
    }*/

    //LANGUAGE["java"]->test();

    std::cout << "\nFinished";
    return 0;
}
