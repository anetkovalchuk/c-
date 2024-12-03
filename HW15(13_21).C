#include <iostream>
#include <string>
#include <unordered_map>

void replaceWordsWithDigits(std::string& input) {
    std::unordered_map<std::string, char> replacements = {
        {"one", '1'}, {"two", '2'}, {"three", '3'},
        {"four", '4'}, {"five", '5'}, {"six", '6'},
        {"seven", '7'}, {"eight", '8'}, {"nine", '9'}
    };

    for (const auto& [word, digit] : replacements) {
        size_t pos = 0;
        while ((pos = input.find(word, pos)) != std::string::npos) {
            input.replace(pos, word.length(), 1, digit);
            pos += 1; 
        }
    }
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    replaceWordsWithDigits(input);

    std::cout << "Modified string: " << input << std::endl;

    return 0;
}
