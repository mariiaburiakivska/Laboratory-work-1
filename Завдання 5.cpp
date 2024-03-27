// Завдання 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Drib {
    int numerator;
    int denominator;
public:
    Drib() : numerator(), denominator() {} // конструктор за замовчуванням
    Drib(int n, int d) : numerator(n), denominator(d) {} //ініціалізуючий конструктор

    Drib(const Drib& other) { // копіюючий конструктор
        numerator = other.numerator;
        denominator = other.denominator;
    }

    Drib(double value) { // конструктор перетворення
        numerator = value * 100;
        denominator = 100;
    }

    void Print() {
        cout << numerator << "/" << denominator;
    }

    int NSD(int a, int b) {
        if (b == 0) {
            return a;
        }
        else {
            return NSD(b, a % b);
        }
    }

    void Skorochennia() {
        int a = numerator;
        int b = denominator;
        int nsd = NSD(a, b);

        numerator /= nsd; //скорочуємо дріб
        denominator /= nsd;
    }

    Drib Dodavannia(const Drib& other) {
        int new_numerator = this->numerator * other.denominator + other.numerator * this->denominator; //чисельник після додавання
        int new_denominator = this->denominator * other.denominator; //зведення до спільного знаменника
        Drib drib_result(new_numerator, new_denominator);
        drib_result.Skorochennia();
        return drib_result;
    }

    Drib Vidnimannia(const Drib& other) {
        int new_numerator = this->numerator * other.denominator - other.numerator * this->denominator; //чисельник після віднімання
        int new_denominator = this->denominator * other.denominator; //зведення до спільного знаменника
        Drib drib_result(new_numerator, new_denominator);
        drib_result.Skorochennia();
        return drib_result;
    }

    Drib Mnozhennia(const Drib& other) {
        int new_numerator = this->numerator * other.numerator;
        int new_denominator = this->denominator * other.denominator;
        Drib drib_result(new_numerator, new_denominator);
        drib_result.Skorochennia();
        return drib_result;
    }

    Drib Dilennia(const Drib& other) {
        int new_numerator = this->numerator * other.denominator; //множимо на перевернутий дріб
        int new_denominator = this->denominator * other.numerator;
        Drib drib_result(new_numerator, new_denominator);
        return drib_result;
    }

    Drib DodavanniaInteger(int c) {
        int new_numerator = this->numerator + c * this->denominator; 
        int new_denominator = this->denominator; 
        Drib drib_result(new_numerator, new_denominator);
        return drib_result;
    }

    Drib MnozhenniaInteger(int c) {
        int new_numerator = this->numerator * c;
        int new_denominator = this->denominator * c;
        Drib drib_result(new_numerator, new_denominator);
        return drib_result;
    }

};


int main()
{
    setlocale(LC_ALL, "Ukr");

    Drib drib1(4, 5);
    cout << "Addition: " << '\t';
    drib1.Print();
    cout << " + ";
    Drib drib2(1, 10);
    drib2.Print();
    cout << " = ";
    Drib drib3 = drib1.Dodavannia(drib2);
    drib3.Print();
    cout << endl;

    cout << "Subtraction: " << '\t';
    drib1.Print();
    cout << " - ";
    drib2.Print();
    cout << " = ";
    Drib drib4 = drib1.Vidnimannia(drib2);
    drib4.Print();
    cout << endl;

    cout << "Multiplication: ";
    drib1.Print();
    cout << " * ";
    drib2.Print();
    cout << " = ";
    Drib drib5 = drib1.Mnozhennia(drib2);
    drib5.Print();
    cout << endl;

    cout << "Division: " << '\t';
    drib1.Print();
    cout << " / ";
    drib2.Print();
    cout << " = ";
    Drib drib6 = drib1.Dilennia(drib2);
    drib6.Print();
    cout << endl;

    Drib drib7(3.14);
    cout << "Conversion: " << '\t' << "3.14 = ";
    drib7.Print();
    cout << endl << endl;

    int c;
    cout << "Enter an integer: ";
    cin >> c;
    cout << "Addition with an integer: " << '\t';
    drib1.Print();
    cout << " + ";
    cout << c;
    cout << " = ";
    Drib drib8 = drib1.DodavanniaInteger(c);
    drib8.Print();
    cout << endl;

    cout << "Multiplication by an integer: " << '\t';
    drib1.Print();
    cout << " * ";
    cout << c;
    cout << " = ";
    Drib drib9 = drib1.MnozhenniaInteger(c);
    drib9.Print();
    cout << endl;

}


