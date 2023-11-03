#include <iostream>
#include <climits>
#include <cmath>

int main() {
    int N;
    std::cout << "Введите количество чисел в последовательности: ";
    std::cin >> N;

    std::cout << std::endl;

    int sum = 0;
    int max = INT_MIN;
    int maxIndex = -1;
    int sumEvenOdd = 0;
    
    for (int i = 0; i < N; i++) {
        int num;
        std::cout << "Введите число №" << (i + 1) << ": ";
        std::cin >> num;

        // Найти сумму четных чисел
        if (num % 2 == 0) {
            sum += num;

            // Найти наибольшее четное число и его индекс
            if (num > max) {
                max = num;
                maxIndex = i + 1;
            }
        }
        if (i % 2 == 0 && num != 0) {
            sumEvenOdd += num;
            std::cout << sumEvenOdd << std::endl;
        } else if (i % 2 != 0 && num != 0) {
            sumEvenOdd -= num;
            std::cout << sumEvenOdd << std::endl;
        } else {
            std::cout << "Ошибка при вычислении" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "Сумма всех четных чисел: " << sum << std::endl;
    std::cout << "Вычтенная сумма всех чисел стоящих на нечетных позициях от суммы стоящей на четных: " << sumEvenOdd << std::endl;
    std::cout << std::endl;
    if (maxIndex != -1) {
        std::cout << "Наибольшее четное число: " << max << " (номер " << maxIndex << ")" << std::endl;
    } else {
        std::cout << "В последовательности нет четных чисел." << std::endl;
    }

    std::cout << std::endl;
    
    int X;
    std::cout << "Введите целое число X: ";
    std::cin >> X;

    int mostFrequentDigit = -1; // Наиболее часто встречающаяся цифра
    int maxCount = 0; // Максимальное количество повторений

    for (int digit = 0; digit <= 9; digit++) {
        int count = 0; // Счетчик для текущей цифры
        int tempX = X; // Копия числа для обработки

        while (tempX > 0) {
            if (tempX % 10 == digit) {
                count++;
            tempX /= 10;
        }

        if (count > maxCount) {
            maxCount = count;
            mostFrequentDigit = digit;
        }
    }

    if (mostFrequentDigit != -1) {
        std::cout << "Наиболее часто встречающаяся цифра в числе X: " << mostFrequentDigit << std::endl;
    } else {
        std::cout << "В числе нет цифр." << std::endl;
    }

    return 0;
}
}
// #include <iostream>

// int main() {
//     int X;
//     std::cout << "Введите целое число X: ";
//     std::cin >> X;

//     return 0;
// }