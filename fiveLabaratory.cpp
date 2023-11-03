#include <iostream>
#include <cmath>

int main() {
    int K;
    // Ввод количества элементов в последовательности
    std::cout << "Введите количество элементов в последовательности (K < 20): ";
    std::cin >> K;

    // Проверка на ограничение по количеству элементов
    if (K >= 20) {
        std::cout << "Ошибка: K не может быть больше или равно 20." << std::endl;
        return 1;
    }

    int sequence[20]; // Максимальный размер массива для K < 20

    // Ввод элементов последовательности
    std::cout << "Введите элементы последовательности: ";
    for (int i = 0; i < K; i++) {
        std::cin >> sequence[i];
    }

    bool hasSameSum = false;
    bool hasThreeDistinctWithSameSum = false;

    // Проверяем, есть ли хотя бы одно число, все цифры которого одинаковы
    for (int i = 0; i < K; i++) {
        int num = sequence[i];
        int lastDigit = num % 10;
        int tempNum = num;
        int sum = 0;
        bool allSame = true;

        // Проверка для однозначных чисел (не удовлетворяют условию)
        if (tempNum < 10) {
            allSame = false;
        }

        while (tempNum > 0) {
            int currentDigit = tempNum % 10;
            sum += currentDigit;
            if (currentDigit != lastDigit) {
                allSame = false;
            }
            tempNum /= 10;
        }

        if (allSame) {
            hasSameSum = true;
            break;
        }
    }

    // Проверяем, есть ли три разных числа с одинаковой суммой цифр
    for (int i = 0; i < K; i++) {
        for (int j = i + 1; j < K; j++) {
            for (int m = j + 1; m < K; m++) {
                if (sequence[i] != sequence[j] && sequence[j] != sequence[m] && sequence[i] != sequence[m]) {
                    int sumI = 0;
                    int sumJ = 0;
                    int sumM = 0;

                    int tempNum = sequence[i];
                    while (tempNum > 0) {
                        sumI += tempNum % 10;
                        tempNum /= 10;
                    }

                    tempNum = sequence[j];
                    while (tempNum > 0) {
                        sumJ += tempNum % 10;
                        tempNum /= 10;
                    }

                    tempNum = sequence[m];
                    while (tempNum > 0) {
                        sumM += tempNum % 10;
                        tempNum /= 10;
                    }

                    if (sumI == sumJ && sumJ == sumM) {
                        hasThreeDistinctWithSameSum = true;
                        break;
                    }
                }
            }
            if (hasThreeDistinctWithSameSum) {
                break;
            }
        }
        if (hasThreeDistinctWithSameSum) {
            break;
        }
    }

    if (hasSameSum || hasThreeDistinctWithSameSum) {
        // Сортировка пузырьком для упорядочивания последовательности
        for (int i = 0; i < K - 1; i++) {
            for (int j = 0; j < K - i - 1; j++) {
                if (sequence[j] > sequence[j + 1]) {
                    int temp = sequence[j];
                    sequence[j] = sequence[j + 1];
                    sequence[j + 1] = temp;
                }
            }
        }

        // Вывод отсортированной последовательности
        std::cout << "Отсортированная последовательность: ";
        for (int i = 0; i < K; i++) {
            std::cout << sequence[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Нет чисел с одинаковой суммой цифр или три разных числа с одинаковой суммой цифр." << std::endl;
    }

    // Проверка на простоту введенного числа
    int numToCheck;
    std::cout << "Введите число для проверки на простоту: ";
    std::cin >> numToCheck;

    bool isPrime = true;
    if (numToCheck <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i <= std::sqrt(numToCheck); i++) {
            if (numToCheck % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        std::cout << numToCheck << " является простым числом." << std::endl;
    } else {
        std::cout << numToCheck << " не является простым числом. Делители: ";
        for (int i = 1; i <= numToCheck; i++) {
            if (numToCheck % i == 0) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }

    int M, N;
    // Ввод размеров матрицы
    std::cout << "Введите количество строк матрицы (M < 10): ";
    std::cin >> M;
    std::cout << "Введите количество столбцов матрицы (N < 10): ";
    std::cin >> N;

    // Проверка на ограничение по размерам матрицы
    if (M >= 10 || N >= 10) {
        std::cout << "Ошибка: M и N не могут быть больше или равны 10." << std::endl;
        return 1;
    }

    int matrix[10][10]; // Максимальный размер матрицы для M и N < 10

    // Ввод элементов матрицы
    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int minSum = 0;
    int minSumRow = 0;

    // Находим сумму элементов первой строки
    for (int j = 0; j < N; j++) {
        minSum += matrix[0][j];
    }

    // Находим строку с наименьшей суммой элементов
    for (int i = 1; i < M; i++) {
        int tempRowSum = 0;
        for (int j = 0; j < N; j++) {
            tempRowSum += matrix[i][j];
        }
        if (tempRowSum < minSum) {
            minSum = tempRowSum;
            minSumRow = i;
        }
    }

    // Заменяем все значения в найденной строке на 0
    for (int j = 0; j < N; j++) {
        matrix[minSumRow][j] = 0;
    }

    // Вывод матрицы после замены
    std::cout << "Матрица после замены:" << std::endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
