#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <limits>
#include <string>

class LinearEquation {
protected:
    double a, b;

public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    virtual std::vector<double> solve() {
        if (a == 0) {
            if (b == 0) return {}; // Infinite solutions
            return {}; // No solution
        }
        return {-b / a};
    }
};

class QuadraticEquation : public LinearEquation {
protected:
    double c;

public:
    QuadraticEquation(double a, double b, double c) : LinearEquation(a, b), c(c) {}

    std::vector<double> solve() override {
        if (a == 0) {
            return LinearEquation(b, c).solve(); // Fallback to linear equation
        }

        dou
