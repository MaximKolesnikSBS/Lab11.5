/*
    Автор: Максим Колесник
    Группа: СБС-001-О-01
    Задание№: 11: 5)
    Цель: Создать класс для реализации комплексных чисел в алгебраической форме и определить основные операции: сложение, вычитание, умножение, деление.
          Создать произвольный класс , в котором определить метод для вычисления комплексного синуса.  
*/

#include<iostream>
#include<stdlib.h>
#include<conio.h>;
#include<climits>
#include<cmath>
#define_USE_MATH_DEFINES
using namespace std;

struct complex {
    double a, b;
};
class Complex {
    complex comp;
public:
    Complex(double x = 0, double y = 0) {
        comp.a = x;
        comp.b = y;
    }
    Complex operator +(const Complex& c);
    Complex operator *(const Complex& c);
    Complex operator -(const Complex& c);
    Complex operator /(const Complex& c);
    bool operator ==(const Complex& c);
    const Complex& operator =(const Complex& c) {
        comp.a = c.comp.a;
        comp.b = c.comp.b;
        return *this;
    }
    Complex conj();
    Complex Read();
    void Display();
};
Complex Complex::operator +(const Complex& c) {
    Complex d;
    d.comp.a = comp.a + c.comp.a;
    d.comp.b = comp.b + c.comp.b;
    return d;
}
Complex Complex::operator *(const Complex& c) {
    Complex t;
    t.comp.a = comp.a * c.comp.a - comp.b * c.comp.b;
    t.comp.b = comp.a * c.comp.b + comp.b * c.comp.a;
    return t;
}
Complex Complex::operator /(const Complex& c) {
    Complex t;
    t.comp.a = (comp.a * c.comp.a + comp.b * c.comp.b) / (comp.a * comp.a + comp.b * comp.b);
    t.comp.b = (comp.b * c.comp.a - comp.a * c.comp.b) / (comp.a * comp.a + comp.b * comp.b);
    return t;
}
Complex Complex::operator -(const Complex& c) {
    Complex y;
    y.comp.a = comp.a - c.comp.a;
    y.comp.b = comp.b - c.comp.b;
    return y;
}
bool Complex::operator ==(const Complex& c) {
    if ((comp.a == c.comp.a) && (comp.b == c.comp.b))
        return true;
    return false;
}
Complex Complex::conj() {
    comp.a = comp.a;
    comp.b = -comp.b;
    return *this;
}
void Complex::Display() {
    if (comp.b >= 0)
        cout << comp.a << "+" << comp.b << "i\n";
    else
        cout << comp.a << comp.b << "i\n";
}
Complex Complex::Read() {
    double x, y;
    cout << "Действительнвая часть: ";
    cin >> x;
    cout << "Мнимая часть:        : ";
    cin >> y;
    Complex A = Complex(x, y);
    return A;
}
//-----------------------------------------------------------
void execute()
{
    cout << " Задание: \n";
    cout << " Реализовать класс Complex для работы с комплексными числами.\n";
    cout << " Комплексное число представляются парой действительных чисел (a, b), где\n";
    cout << "     a — действительная часть, b — мнимая часть. \n";
    cout << " Реализовать операции:\n";
    cout << " - сложения\n";
    cout << " - вычитания\n";
    cout << " - умножения\n";
    cout << " - деления\n";
}
int chois() {
    int chois_1;
    cout << "     Операции комплексными числами\n";
    cout << " 1 - Сложение\n";
    cout << " 2 - Вычитание\n ";
    cout << " 3 - Умножение\n";
    cout << " 4 - Деление\n";
    cout << " 0 - Выход\n\n";
    cout << "\n Выберите действие : \n";
    cin >> chois_1;
    while ((chois_1 < 0) || chois_1 > 0 ) {
        cout << "     !!!Не корректные данные!!!\n";
        cout << " Ведите заново : ";
        cin >> chois_1;
    }
    return chois_1;
}
void choise() {
    switch (chois()) {
    case 1: {
        Complex a, b;
        cout << "Первое число:\n";
        a = a.Read();
        cout << "Второе число:\n";
        b = b.Read();
        Complex c = a + b;
        c.Display();
        break;
    }
    case 2: {
        Complex a, b;
        cout << "Первое число:\n";
        a = a.Read();
        cout << "Второе число:\n";
        b = b.Read();
        Complex c = a - b;
        c.Display();
        break;
    }
    case 3: {
        Complex a, b;
        cout << "Первое число:\n";
        a = a.Read();
        cout << "Второе число:\n";
        b = b.Read();
        Complex c = a * b;
        c.Display();
        break;
    }
    case 4: {
        Complex a, b;
        cout << "Первое число:\n";
        a = a.Read();
        cout << "Второе число:\n";
        b = b.Read();
        Complex c = a / b;
        c.Display();
        break;
    }
    default:exit(0);
    }
    system("pause");
    system("cls");
    choise();

}
//-----------------------------------------------------------
int value() {
    while (true) {
        cout << "Введите аргумент: ";
        short z;
        cin >> z;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Введено некорректное значение , повторите попытку " << endl;
        }
        else {
            return z;
        }
    }
}
int factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}
double calculations(int z) {
    double csin = 0;
    const unsigned short n = 8;
    for (int i = 0; i < n; i++) {
        csin += pow(-1, i) * pow(z, 2 * i + 1) / factorial(2 * i + 1);
    }
    return csin;
}
int main() {
    setlocale(LC_ALL, "Russian");
    execute();
    cout << "Демонстрация метода сложения\n";
    cout << "(2+4j)+(2-7j)= ";
    Complex A, B, C;
    A = Complex(2, 4);
    B = Complex(2, -7);
    C = A + B;
    C.Display();
    cout << "\nДемонстрация метода вычитание\n";
    cout << "(2+4j)-(2-7j)= ";
    C = A - B;
    C.Display();
    cout << "\nДемонстрация метода умнажение\n";
    cout << "(2+4j)*(2-7j)= ";
    C = A * B;
    C.Display();
    Complex R, T, Y;
    R = Complex(-2, 3);
    T = Complex(7, 1);
    cout << "\nДемонстрация метода деление\n";
    cout << "(-2+3j)/(7+1j)= ";
    Y = R / T;
    Y.Display();
    int z = value();
    double csin = calculations(z);
    cout << "Комплексный синус csin(" << z << ") = " << csin << endl;
    system("pause");
    system("cls");
    cout << "\n   -------------------------------------------------------\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    choise();
    return 0;
}
