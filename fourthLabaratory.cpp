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
    int maxIndex = 0;
    int sumEvenOdd = 0;
    
    for (int i = 0; i < N; i++) {
        int num;
        std::cout << "Введите число №" << (i + 1) << ": ";
        std::cin >> num;


        // Найти сумму четных чисел
        if (num!=0 && num%2==0) {
            sum += num;

            // Найти наибольшее четное число и его индекс
            if (num > max & num!=0) {
                max = num;
                maxIndex = i + 1;
            }
        }
        if (num!=0 && i%2==0) {
            sumEvenOdd+=num;
        }
        else if (num!=0 && i%2!=0) {
            sumEvenOdd-=num;
        }
        else {
            std::cout << "Ошибка при вычислении" << std::endl;
        }
    }

    std::cout << std::endl;

    if (N>0) {
        std::cout << "Сумма всех четных чисел: " << sum << std::endl;
        std::cout << "Вычтенная сумма всех чисел стоящих на нечетных позициях от суммы стоящей на четных: " << sumEvenOdd <<std::endl;
        if (maxIndex != 0) {
            std::cout << "Наибольшее четное число: " << max << " (номер " << maxIndex << ")" << std::endl;
        } else {
            std::cout << "В последовательности нет четных чисел." << std::endl;
    }
    }
    else {
        std::cout << "Сумма равна 0" << std::endl;
    }

    std::cout << std::endl;
    
    int X;
    std::cout << "Введите целое число X: ";
    std::cin >> X;
    std::cout << std::endl;
    X=abs(X);
    int sameX=X;
    int minDigit = pow(10,9);
    while (X > 0) {
        int digit = X;
        if (digit != 0 && digit != 7 && digit < minDigit) {
            minDigit = digit;
            digit=digit%10;
        }
        X /= 10;
    }

    if (minDigit != pow(10,9)) {
        std::cout << "Наименьшая цифра, отличная от 0 и 7: " << minDigit << std::endl;
    } else {
        std::cout << "В числе нет цифр, отличных от 0 и 7." << std::endl;
    }

    int mostNumCount = -1; // Наиболее часто встречающаяся цифра
    int maxCount = 0; // Максимальное количество повторений

    for (int digit = 0; digit <= 9; digit++) {
        int count = 0; // Счетчик для текущей цифры
        int tempX = sameX; // Копия числа для обработки

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

    if (mostNumCount != -1) {
        std::cout << "Наиболее часто встречающаяся цифра в числе X: " << mostNumCount << std::endl;
    } else {
        std::cout << "В числе нет цифр." << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
