#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

void createAndProcessFile(const std::string& filename, int n) {
    std::ofstream outfile(filename);
    for (int i = 1; i <= n; ++i) {
        outfile << "   Line " << i << "   with   extra   spaces   \n";
    }
    outfile.close();

    std::ifstream infile(filename);
    std::ofstream tempFile("temp.txt");
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string word, result;
        while (iss >> word) {
            if (!result.empty()) result += " ";
            result += word;
        }
        tempFile << result << "\n";
    }

    infile.close();
    tempFile.close();
    std::remove(filename.c_str());
    std::rename("temp.txt", filename.c_str());
}

int main() {
    std::string filename = "output.txt";
    int n = 5;
    createAndProcessFile(filename, n);
    return 0;
}
