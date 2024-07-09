//
// Created by danielh on 20-06-24.
//

#include "CompiledLanguage.h"

#include <utility>
#include <iostream>
#include <filesystem>


int CompiledLanguage::compile() {
    return compile(std::filesystem::current_path().filename().string());
}



int CompiledLanguage::test() {
    compile();
    std::vector<std::string> testFiles = Language::findTrimmedFilesByExtension({".in"});

    for (const auto& entry : testFiles) {
        string input = Language::getFileContent(entry + ".in");
        string res = this->execute(input);
    }

    return 0;
}

CompiledLanguage::CompiledLanguage() = default;


CompiledLanguage::~CompiledLanguage() = default;

