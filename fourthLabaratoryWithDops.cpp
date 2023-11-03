#include <iostream>
#include <climits>
#include <cmath>

// Функция для ввода числа N
int getInputN() {
    int N;
    std::cout << "Введите количество чисел в последовательности: ";
    std::cin >> N;
    return N;
}

// Функция для ввода последовательности чисел
void getInputSequence(int N, int sequence[]) {
    for (int i = 0; i < N; i++) {
        std::cout << "Введите число №" << (i + 1) << ": ";
        std::cin >> sequence[i];
    }
}

// Функция для вычисления суммы четных чисел и нахождения наибольшего четного числа
void calculateSumAndMax(int N, int sequence[], int& sum, int& max, int& maxIndex) {
    sum = 0;
    max = INT_MIN;
    maxIndex = 0;
    
    for (int i = 0; i < N; i++) {
        int num = sequence[i];

        if (num != 0 && num % 2 == 0) {
            sum += num;

            if (num > max && num != 0) {
                max = num;
                maxIndex = i + 1;
            }
        }
    }
}

// Функция для вычисления суммы чисел на четных и нечетных позициях
int calculateSumEvenOdd(int N, int sequence[]) {
    int sumEvenOdd = 0;

    for (int i = 0; i < N; i++) {
        int num = sequence[i];

        if (num != 0 && i % 2 == 0) {
            sumEvenOdd += num;
        } else if (num != 0 && i % 2 != 0) {
            sumEvenOdd -= num;
        }
    }

    return sumEvenOdd;
}

// Функция для вычисления наименьшей цифры отличной от 0 и 7 в числе X
int findMinDigit(int X) {
    X = abs(X);
    int minDigit = 9;

    while (X > 0) {
        int digit = X % 10;
        if (digit != 0 && digit != 7) {
            minDigit = std::min(minDigit, digit);
        }
        X /= 10;
    }

    return minDigit;
}

// Функция для нахождения наиболее часто встречающейся цифры
int findMostFrequentDigit(int X) {
    int mostNumCount = -1; // Наиболее часто встречающаяся цифра
    int maxCount = 0; // Максимальное количество повторений

    for (int digit = 0; digit <= 9; digit++) {
        int count = 0; // Счетчик для текущей цифры
        int tempX = X; // Копия числа для обработки

        while (tempX > 0) {
            if (tempX % 10 == digit) {
                count++;
            }
            tempX /= 10;
        }

        if (count > maxCount) {
            maxCount = count;
            mostNumCount = digit;
        }
    }

    return mostNumCount;
}

int main() {
    int N = getInputN();

    if (N <= 0) {
        std::cout << "Сумма равна 0" << std::endl;
        return 0;
    }

    int sequence[N];
    getInputSequence(N, sequence);

    int sum, max, maxIndex;
    calculateSumAndMax(N, sequence, sum, max, maxIndex);

    int sumEvenOdd = calculateSumEvenOdd(N, sequence);

    std::cout << "Сумма всех четных чисел: " << sum << std::endl;
    std::cout << "Вычтенная сумма всех чисел стоящих на нечетных позициях от суммы стоящей на четных: " << sumEvenOdd << std::endl;

    if (maxIndex != 0) {
        std::cout << "Наибольшее четное число: " << max << " (номер " << maxIndex << ")" << std::endl;
    } else {
        std::cout << "В последовательности нет четных чисел." << std::endl;
    }

    int X;
    std::cout << "Введите целое число X: ";
    std::cin >> X;

    int minDigit = findMinDigit(X);

    if (minDigit == 9) {
        std::cout << "В числе нет цифр, отличных от 0 и 7." << std::endl;
    } else {
        std::cout << "Наименьшая цифра, отличная от 0 и 7: " << minDigit << std::endl;
    }

    int mostNumCount = findMostFrequentDigit(X);

    if (mostNumCount != -1) {
        std::cout << "Наиболее часто встречающаяся цифра в числе X: " << mostNumCount << std::endl;
    } else {
        std::cout << "В числе нет цифр." << std::endl;
    }

    return 0;
}