#include <iostream>
#include <fstream>
#include <stdexcept>

class Rational {
private:
    int numerator;
    int denominator;

    void validate() {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
    }

public:
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        validate();
    }

    void setNumerator(int num) {
        numerator = num;
    }

    void setDenominator(int denom) {
        denominator = denom;
        validate();
    }

    friend std::ostream& operator<<(std::ostream& out, const Rational& r) {
        out << r.numerator << "/" << r.denominator;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Rational& r) {
        char separator;
        in >> r.numerator >> separator >> r.denominator;
        if (r.denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        return in;
    }

    Rational operator-(const Rational& other) const {
        return Rational(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Rational operator-() const {
        return Rational(-numerator, denominator);
    }

    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    friend void writeToFile(const std::string& filename, const Rational& r) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file.");
        }
        file << r;
    }
};

int main() {
    try {
        Rational r1, r2;
        std::cout << "Enter first rational number (format: numerator/denominator): ";
        std::cin >> r1;

        std::cout << "Enter second rational number (format: numerator/denominator): ";
        std::cin >> r2;

        Rational result = r1 - r2;
        std::cout << "Subtraction result: " << result << std::endl;

        Rational negation = -r1;
        std::cout << "Negated first rational: " << negation << std::endl;

        Rational division = r1 / r2;
        std::cout << "Division result: " << division << std::endl;

        writeToFile("output.txt", division);
        std::cout << "Division result written to file." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "File error: " << e.what() << std::endl;
    }

    return 0;
}
