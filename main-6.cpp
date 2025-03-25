#include <iostream>
#include <fstream>
#include <vector>
#include <map>

void insertZeros(std::vector<int>& arr, int K, int M) {
    arr.insert(arr.begin() + K, M, 0); // Вставляємо M нулів після K-го елемента
}

void findMaxEqualRow(const std::vector<std::vector<int>>& matrix, int& rowIndex) {
    int maxCount = 0;
    rowIndex = -1;

    for (int i = 0; i < matrix.size(); ++i) {
        std::map<int, int> countMap;
        for (int num : matrix[i]) {
            countMap[num]++;
        }

        int currentMax = 0;
        for (const auto& pair : countMap) {
            if (pair.second > currentMax) {
                currentMax = pair.second;
            }
        }

        if (currentMax >= maxCount) {
            maxCount = currentMax;
            rowIndex = i + 1; // +1 для індексації з 1
        }
    }
}

void binaryInsertionSort(std::vector<char>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        char key = arr[i];
        int left = 0, right = i - 1;

        // Знаходимо позицію для вставки
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Вставляємо елемент
        arr.insert(arr.begin() + left, key);
        arr.erase(arr.begin() + i + 1);
    }
}

void task1() {
    int N, K, M;
    std::cout << "task 1: Введіть розмір масиву N: ";
    std::cin >> N;

    std::vector<int> arr(N);
    std::cout << "Введіть елементи масиву: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Введіть K (номер елемента для вставки): ";
    std::cin >> K;
    std::cout << "Введіть M (кількість нулів для вставки): ";
    std::cin >> M;

    // Вставляємо нулі
    insertZeros(arr, K - 1, M); // K-1, бо індексація з 0

    // Виводимо масив
    std::cout << "Змінений масив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Записуємо в файл
    std::ofstream outFile("array_out_n.txt");
    for (int num : arr) {
        outFile << num << " ";
    }
    outFile.close();
}

void task2() {
    int M, N;
    std::cout << "task 2: Введіть кількість рядків M: ";
    std::cin >> M;
    std::cout << "Введіть кількість стовпців N: ";
    std::cin >> N;

    std::vector<std::vector<int>> matrix(M, std::vector<int>(N));
    std::cout << "Введіть елементи матриці: ";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int rowIndex;
    findMaxEqualRow(matrix, rowIndex);
    std::cout << "Номер останнього рядка з максимальною кількістю однакових елементів: " << rowIndex << std::endl;

    // Записуємо в файл
    std::ofstream outFile("matr_out_n.txt", std::ios::app);
    outFile << "Номер останнього рядка з максимальною кількістю однакових елементів: " << rowIndex << std::endl;
    outFile.close();
}

void task3() {
    std::cout << "task 3: Введіть 7 символів для сортування: ";
    std::vector<char> arr(7);
    for (int i = 0; i < 7; ++i) {
        std::cin >> arr[i];
    }

    binaryInsertionSort(arr);

    std::cout << "Відсортований масив: ";
    for (char c : arr) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // Записуємо в файл
    std::ofstream outFile("sorted_array.txt");
    for (char c : arr) {
        outFile << c << " ";
    }
    outFile.close();
}

int main() {
    int choice;
    do {
        std::cout << "Choose task: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
                case 3:
                task3();
                break;
            default:
                std::cout << "Wrong task" << std::endl;
        }
    } while (choice != 0);

    return 0;
}