#include <iostream>
#include <string>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();

private:
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

string Fraction::toString() {
    int whole = numerator / denominator;
    int remainder = (numerator % denominator);
    string sign = (numerator < 0) && (denominator < 0) ? "-" : "";
    string result = sign;

    if (whole != 0)
        result += to_string((whole)) + " ";

    result += to_string(remainder) + "/" + to_string((denominator));
    return result;
}

double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int num, den;
    string input = "";
    getline(cin, input);
    size_t pos = input.find("/");
    if (pos != string::npos) {
        num = stoi(input.substr(0, pos));
        den = stoi(input.substr(pos + 1));
    }

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}
