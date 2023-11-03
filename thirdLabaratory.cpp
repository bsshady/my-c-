#include <iostream>

int main() {
    int A, B, C, X;
    
    // Ввод натуральных чисел A, B и C
    std::cout << "Введите натуральное число A: ";
    std::cin >> A;
    
    std::cout << "Введите натуральное число B: ";
    std::cin >> B;
    
    std::cout << "Введите натуральное число C: ";
    std::cin >> C;
    
    if (A<=0 | B<=0 | C<=0) {
        std::cout << "Ошибка ввода: Числа должны быть натуральными! (1,2,3...)";
        return 1;
    }

    //Проверка условия через блок if else if else 
    int result;
    if (A > B && B > C && (B+C)>A) {
        result = A - B - C;
        std::cout << "A - B - C = " << result << std::endl;
    } else if (B > A && B % C == 0 && C!=0) {
        result = (B / C) + (B - A); 
        std::cout << "(B / C) + (B - A) = " << result << std::endl;
    } else {
        result = A + B + C;
        std::cout << "A + B + C = " << result << std::endl;
    }
    
    //endl для красивого вывода
    std::cout << std::endl;

    // Ввод цифры N
    int N;
    std::cout << "Введите цифру N (0-9): ";
    std::cin >> N;

    //блок switch для вывода письменной цифры
    switch (N) {
        case 0:
            std::cout << "Ноль" << std::endl;
            break;
        case 1:
            std::cout << "Один" << std::endl;
            break;
        case 2:
            std::cout << "Два" << std::endl;
            break;
        case 3:
            std::cout << "Три" << std::endl;
            break;
        case 4:
            std::cout << "Четыре" << std::endl;
            break;
        case 5:
            std::cout << "Пять" << std::endl;
            break;
        case 6:
            std::cout << "Шесть" << std::endl;
            break;
        case 7:
            std::cout << "Семь" << std::endl;
            break;
        case 8:
            std::cout << "Восемь" << std::endl;
            break;
        case 9:
            std::cout << "Девять" << std::endl;
            break;
        default:
            std::cout << "Введено некорректное число" << std::endl;
            break;
    }

    std::cout << std::endl;

    std::cout << "Введите значение переменной X (-1 или 1): ";
    std::cin >> X;

    // switch (X) {
    //     case -1:
    //         std::cout << "Negative number" << std::endl;
    //         break;
    //     case 1:
    //         std::cout << "Positive number" << std::endl;
    //         break;
    //     default:
    //         std::cout << "Введено некорректное значение X" << std::endl;
    // }

    // solution №2
    //std::cout << (X == -1 ? "Negative number" : (X == 1 ? "Positive number" : "Введено некорректное значение X")) << std::endl;
    //solution №3
    bool isNegative = X == -1;
    bool isPositive = X == 1;
    bool isError = !((X==1) | (X==-1));

    isNegative && std::cout << "Negative number" << std::endl;
    isPositive && std::cout << "Positive number" << std::endl;
    isError && std::cout << "Введеное неверное число. (Введеное число должно быть равно -1, или 1.)" << std::endl;

    //solution №4
    // const char* messages[] = { "Negative number", "Positive number" };

    // std::cout << messages[(X + 1) / 2] << std::endl;

    //Возвращаем 0 функции
    return 0;
}
