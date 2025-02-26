#include <iostream>
using namespace std;

const int M = 20, N = 20; // Максимальні розміри матриці

// Функція введення матриці
void get_matr(int in_matr[M][N], int &in_m, int &in_n) {
    do {
        cout << "Введіть кількість рядків (2-20): ";
        cin >> in_m;
        cout << "Введіть кількість стовпців (2-20): ";
        cin >> in_n;
    } while (in_n < 2 || in_n > N || in_m < 2 || in_m > M);
    
    cout << "Введіть елементи: " << endl;
    for (int i = 0; i < in_m; i++)
        for (int j = 0; j < in_n; j++)
            cin >> in_matr[i][j];
}

// Завдання 1: Matrix40
// Функція для знаходження номера останнього рядка з максимальною кількістю однакових елементів
int last_row_with_max_equal(int matr[M][N], int m, int n) {
    int max_count = 0;
    int last_row = -1;

    for (int i = 0; i < m; i++) {
        int count[101] = {0}; // Припустимо, що елементи матриці в межах 0-100
        for (int j = 0; j < n; j++) {
            count[matr[i][j]]++;
        }
        
        int current_max = 0;
        for (int k = 0; k < 101; k++) {
            if (count[k] > current_max) {
                current_max = count[k];
            }
        }

        // Якщо поточна максимальна кількість однакових елементів більша за 1
        if (current_max > 1) {
            if (current_max >= max_count) {
                max_count = current_max;
                last_row = i + 1; // Номери рядків з 1
            }
        }
    }
    return last_row;
}

// Функція виведення матриці
void show_matr(const int out_matr[M][N], const int m, const int n) {
    cout << endl << "Матриця: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << out_matr[i][j] << "\t";
        cout << endl;
    }
}

// Завдання 2: Matrix72
// Функція для вставки стовпця з одиниць перед першим стовпцем з додатніми елементами
void insert_column_before_positive(int matr[M][N], int &m, int &n) {
    int insert_col = -1;

    // Знаходимо перший стовпець з додатніми елементами
    for (int j = 0; j < n; j++) {
        bool has_positive = true;
        for (int i = 0; i < m; i++) {
            if (matr[i][j] <= 0) {
                has_positive = false;
                break;
            }
        }
        if (has_positive) {
            insert_col = j;
            break;
        }
    }

    // Якщо знайдено стовпець, вставляємо новий стовпець
    if (insert_col != -1) {
        for (int i = 0; i < m; i++) {
            for (int j = n; j > insert_col; j--) {
                matr[i][j] = matr[i][j - 1];
            }
            matr[i][insert_col] = 1; // Вставляємо одиницю
        }
        n++; // Збільшуємо кількість стовпців
    }
}

// Головна функція
int main() {
    int matr[M][N]; // Оголошення матриці
    int row, col; // Реальні розміри матриці
    int choice;

    do {
        cout << "Виберіть завдання (1 - Matrix40, 2 - Matrix72, 0 - Вихід): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                get_matr(matr, row, col); // Введення матриці
                show_matr(matr, row, col); // Виведення матриці
                int lastRow = last_row_with_max_equal(matr, row, col); // Зберігаємо результат
                if (lastRow != -1) {
                    cout << "Останній рядок з максимальною кількістю однакових елементів: " << lastRow << endl;
                } else {
                    cout << "Рядки не знайдено." << endl;
                }
                break;
            }
            case 2:
                get_matr(matr, row, col); // Введення матриці
                show_matr(matr, row, col); // Виведення матриці
                insert_column_before_positive(matr, row, col); // Вставка стовпця
                cout << "Матриця після вставки: " << endl;
                show_matr(matr, row, col); // Виведення зміненої матриці
                break;
            case 0:
                cout << "Вихід..." << endl;
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}