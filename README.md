#include <iostream>

int main() {
    // Оголошення змінних
    int A, B, C;

    // Введення початкових значень змінних
    std::cout << "Введіть значення A: ";
    std::cin >> A;
    std::cout << "Введіть значення B: ";
    std::cin >> B;
    std::cout << "Введіть значення C: ";
    std::cin >> C;

    // Виведення початкових значень змінних
    std::cout << "Початкові значення змінних:" << std::endl;
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "C = " << C << std::endl;

    // Переміщення значень
    int temp = A;  // Зберігаємо значення A
    A = C;         // Переміщаємо C в A
    C = B;         // Переміщаємо B в C
    B = temp;      // Переміщаємо збережене значення A в B

    // Виведення нових значень змінних
    std::cout << "Нові значення змінних:" << std::endl;
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "C = " << C << std::endl;

    return 0;
}
