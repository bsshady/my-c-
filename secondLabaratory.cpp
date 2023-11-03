#include <iostream>
#include <bitset>

int main() {
    unsigned char X = 7; // инициализируем переменную X
    // 7 = 00000111
    //unsigned char X = 98; 
    // 98 = 01100010
    // unsigned char X = 241; 
    // 241 = 11110001
    int i; // Объявляем переменную i
    int firstCount;
    int invertedBin;
    int j;
    int invertedBits=X;
    int reversedX;

    //вариант 1 решение

    //Вывод исходного X в 10 с.с, и в 2 с.с.
    std::cout << "Исходное значение X в десятичной системе и двоичной системе: " << int(X) << ", " << std::bitset<8>(X) << std::endl;
    std::cout << std::endl;

    //Конструкция ввода i
    std::cout << "Введите позицию i бита. Число от 0 до 7: ";
    std::cin >> i;

    std::cout << "Введите позицию j бита: Число от 0 до 7: ";
    std::cin >> j;
    std::cout << std::endl;

    //Установка нужного i бита в 1
    X = X | (1 << i);
    firstCount=255; // берем 255, потому что двоичная запись 255 это 11111111, память не переполняется и все ячейки имеют по 1 байту
    invertedBin=X^firstCount;
    
    std::cout << "Изначальное число без перестановки: " << std::bitset<8>(invertedBits) << std::endl;
    int bitI=(invertedBits>>i) &1; // получаем значение бита i
    int bitJ=(invertedBits>>j) &1; // получаем значение бита j

    invertedBits= (invertedBits & ~(1 << i)& ~(1<<j)) | (bitI<<j) | (bitJ<<i); // первая часть перед первым ИЛИ, сбрасывает изначальное значение i, j в 0 инвертируя и умножая значение. вторая часть кода сдвигает нужные биты в прошлые значения битов. БИТЖИТОЕ в прошлое значение итого, БИТИТОЕ в прошлое значение житого.
    std::cout << "Число после перестановки i и j битов: " << std::bitset<8>(invertedBits) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Изначальная битовая цепочка: " << std::bitset<8>(X) << std::endl;
    reversedX|=((X>>0)&1) << (8-1-0);
    reversedX|=((X>>1)&1) << (8-1-1);
    reversedX|=((X>>2)&1) << (8-1-2);
    reversedX|=((X>>3)&1) << (8-1-3);
    reversedX|=((X>>4)&1) << (8-1-4);
    reversedX|=((X>>5)&1) << (8-1-5);
    reversedX|=((X>>6)&1) << (8-1-6);
    reversedX|=((X>>7)&1) << (8-1-7);
    std::cout << "Перевернутая битовая цепочка: " << std::bitset<8>(reversedX) << std::endl;
    std::cout << std::endl;


    //Вывод обновленного X в 10 с.с, и в 2 с.с
    std::cout << "Полученное значение X в десятичной и двоичной  системе: " << int(X) << ", " << std::bitset<8>(X) << std::endl;
    std::cout << "Инвертированные биты: " <<  std::bitset<8>(invertedBin) << std::endl;
    return 0; // Возвращаем int число int процедуре ;3
}
