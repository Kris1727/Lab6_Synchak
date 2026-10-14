#include <iostream>
#include <vector>
#include <utility>

class Fraction {
private:
    int num_;
    int den_;
public:
    Fraction(int num = 0, int den = 1) : num_{num}, den_{den} {}

    bool operator>(const Fraction& other) const {
        return num_ * other.den_ > other.num_ * den_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        return os << f.num_ << '/' << f.den_;
    }
};

template <typename T>
void swapWithMax(std::vector<T>& arr, int k) {
    int n = arr.size();
    if (k < 0 || k >= n) {
        std::cout << "Невірний індекс k\n";
        return;
    }
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    std::swap(arr[k], arr[maxIndex]);
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const T& item : arr) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> numbers{3, 9, 2, 9, 5};
    int k1 = 0;
    std::cout << "int до:    ";
    printArray(numbers);
    swapWithMax(numbers, k1);
    std::cout << "int після: ";
    printArray(numbers);

    std::vector<Fraction> fractions{Fraction(1, 2), Fraction(3, 4), Fraction(1, 3), Fraction(5, 6)};
    int k2 = 0;
    std::cout << "Fraction до:    ";
    printArray(fractions);
    swapWithMax(fractions, k2);
    std::cout << "Fraction після: ";
    printArray(fractions);

    return 0;
}