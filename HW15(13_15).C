#include <iostream>
#include <sstream>
#include <string>

int countWordsWithChar(const std::string& input, char target) {
    std::istringstream stream(input);
    std::string word;
    int count = 0;

    while (stream >> word) {
        if (word.find(target) != std::string::npos) {
            count++;
        }
    }
    return count;
}

int main() {
    std::string input;
    char target;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::cout << "Enter a character to search for: ";
    std::cin >> target;

    int result = countWordsWithChar(input, target);
    std::cout << "Number of words containing '" << target << "': " << result << std::endl;

    return 0;
}
