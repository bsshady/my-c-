#include <iostream>
#include <cmath>

int main() {
    int K;
    std::cout << "Введите количество элементов в последовательности: ";
    std::cin >> K;

    std::cout << std::endl;

    int M, N;
    std::cout << "Введите количество строк матрицы (M): ";
    std::cin >> M;
    std::cout << "Введите количество столбцов матрицы (N): ";
    std::cin >> N;

    int sequence[K];

    std::cout << "Введите элементы последовательности: ";
    for (int i = 0; i < K; i++) {
        std::cin >> sequence[i];
    }

    // Проверяем, есть ли хотя бы одно число, у которого все цифры одинаковы
    bool hasSameDigits = false;
    
    for (int i = 0; i < K; i++) {
        int num = sequence[i];
        int lastDigit = num % 10;
        int tempNum = num;
        bool allSame = true;

        while (tempNum > 0) {
            int currentDigit = tempNum % 10;
            if (currentDigit != lastDigit) {
                allSame = false;
                break;
            }
            tempNum /= 10;
        }

        if (allSame) {
            hasSameDigits = true;
            break;
        }
    }

    if (hasSameDigits) {
        // Если есть число с одинаковыми цифрами, сортируем последовательность (сортировка пузырьком)
        for (int i = 0; i < K-1; i++) {
            for (int j = 0; j < K-i-1; j++) {
                if (sequence[j] > sequence[j+1]) {
                    // Обмен значениями
                    int temp = sequence[j];
                    sequence[j] = sequence[j+1];
                    sequence[j+1] = temp;
                }
            }
        }

        std::cout << "Отсортированная последовательность: ";
        for (int i = 0; i < K; i++) {
            std::cout << sequence[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Нет чисел с одинаковыми цифрами." << std::endl;
    }
    std::cout << std::endl;

    // Переходим ко второму пункту задачи


    int matrix[M][N];

    std::cout << "Введите элементы матрицы:" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int minSum = std::abs(matrix[0][0]);
    int minSumRow = 0;

    // Находим строку с наименьшей суммой элементов
    for (int i = 0; i < M; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += matrix[i][j];
        }
        if (std::abs(rowSum) < minSum) {
            minSum = std::abs(rowSum);
            minSumRow = i;
        }
    }

    // Заменяем все значения в найденной строке на 0
    for (int j = 0; j < N; j++) {
        matrix[minSumRow][j] = 0;
    }

    std::cout << "Матрица после замены:" << std::endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
