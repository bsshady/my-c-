#include <iostream> 

int main() {
    int x = 755;
    int digit=x%10;
    int minDigit=10;
    while (x>0) {
        if (digit!=0 && digit!=7 && digit < minDigit) {
            digit%=x;
        }
    }
    std::cout <<digit;
}