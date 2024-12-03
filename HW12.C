#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string word;
        bool firstWord = true;

        while (ss >> word) {
            word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
                return !std::isdigit(c);
            }), word.end());

            if (!word.empty()) {
                if (!firstWord) {
                    outputFile << " ";
                }
                outputFile << word;
                firstWord = false;
            }
        }
        outputFile << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "File processing completed." << std::endl;
    return 0;
}
