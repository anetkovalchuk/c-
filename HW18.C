#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Array {
private:
    std::vector<int> data;

public:
    Array(const std::vector<int>& input) : data(input) {}

    void hashSort(int maxValue) {
        if (maxValue <= 0) {
            throw std::invalid_argument("Max value must be greater than zero.");
        }

               std::vector<int> hashTable(maxValue + 1, 0);

        for (int num : data) {
            if (num < 0 || num > maxValue) {
                throw std::out_of_range("Element out of range for hashing.");
            }
            hashTable[num]++;
        }

        data.clear();
        for (int i = 0; i <= maxValue; ++i) {
            while (hashTable[i] > 0) {
                data.push_back(i);
                hashTable[i]--;
            }
        }
    }

    void print() const {
        for (int num : data) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    try {
        std::vector<int> input = {4, 2, 2, 8, 3, 3, 1};
        int maxValue = 8; // Max value in the array

        Array array(input);
        std::cout << "Original array: ";
        array.print();

        array.hashSort(maxValue);

        std::cout << "Sorted array: ";
        array.print();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
