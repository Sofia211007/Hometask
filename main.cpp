#include <iostream>
#include <cmath> 
using namespace std;

// Завдання 1 реалізація
void Minmax(double &x, double &y) {
    if (x > y) {
        swap(x, y); // Міняємо місцями значення, якщо x більше y
    }
}

void task_proc11() {
    double A, B, C, D;

    // Введення чотирьох чисел
    cout << "Введіть чотири числа (A, B, C, D): ";
    cin >> A >> B >> C >> D;

    // Використання процедури Minmax 
    Minmax(A, B); // Порівнюємо та змінюємо місцями значення A і B для отримання меншого в A
    Minmax(C, D); // Порівнюємо та змінюємо місцями значення C і D для отримання меншого в C

    Minmax(A, C); // Порівнюємо мінімальні значення з A і C для отримання загального мінімуму в A
    Minmax(B, D); // Порівнюємо максимальні значення з B і D для отримання загального максимуму в D

    // Виведення результатів
    cout << "Мінімальне значення: " << A << endl;
    cout << "Максимальне значення: " << D << endl;
}

// Завдання 2 реалізація
bool inputAndValidate(double &A, double &B, double &C) {
    cout << "Введіть коефіцієнти A, B, C (A не повинно дорівнювати 0): ";
    cin >> A >> B >> C;

    if (A == 0) {
        cout << "Помилка: Коефіцієнт A не може дорівнювати 0!" << endl;
        return false; // Некоректні дані
    }

    return true; // Дані коректні
}

bool hasRealRoots(double A, double B, double C) {
    double D = B * B - 4 * A * C; // Обчислення дискримінанта
    return D >= 0;               // Дійсні корені існують
}

void task_boolean24() {
    double A, B, C;

    if (!inputAndValidate(A, B, C)) {
        return; // Якщо дані некоректні — завершити виконання функції
    }

    bool result = hasRealRoots(A, B, C);

    if (result) {
        cout << "Квадратне рівняння має дійсні корені." << endl;
    } else {
        cout << "Квадратне рівняння не має дійсних коренів." << endl;
    }
}

// Завдання 3 реалізація
bool inputAndValidate(int &number) {
    cout << "Введіть тризначне число: ";
    cin >> number;

    if (number < 100 || number > 999) {
        cout << "Помилка: Число не є тризначним!" << endl;
        return false; // Некоректні дані
    }

    return true; // Дані коректні
}

int calculateResult(int number) {
    int hundreds = number / 100;      // Отримуємо сотні
    int tens = (number / 10) % 10;   // Отримуємо десятки
    int units = number % 10;         // Отримуємо одиниці

    return hundreds * 100 + units * 10 + tens; // Формуємо нове число
}

void outputResult(int result) {
    cout << "Результат після перестановки цифр десятків і одиниць: " << result << endl;
}

void task_integer16() {
    int number;

    if (!inputAndValidate(number)) {
        return; // Якщо дані некоректні — завершити виконання функції
    }

    int result = calculateResult(number);
    outputResult(result);
}

// Перемикання між завданнями 
int main() {
    int menu;

    while (true) { // Цикл для повторного вибору завдань
        cout << "\nОберіть завдання:" << endl;
        cout << "11" << endl;
        cout << "24" << endl;
        cout << "16" << endl;
        cin >> menu;

        switch (menu) {
            case 11:
                task_proc11();
                break;
            case 24:
                task_boolean24();
                break;
            case 16:
                task_integer16();
            default:
                cout << "Невірний вибір!" << endl;
                return 0;
        }
    }

    return 0;
}