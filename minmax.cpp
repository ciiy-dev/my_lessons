#include <iostream>
#include <conio.h>
#include <vector>
void MinMax(int n) {
    int min = 9, max = 0;
    while (n > 0) {
        if (n % 10 > max)
            max = n % 10;
        if (n % 10 < min)
            min = n % 10;
        n /= 10;
    }
    std::cout << "min= " << min << "\nmax= " << max;
}
int main() {
    int num = 0;
    while (num < 1000 || num>9999)
        std::cin >> num;
    MinMax(num);
}
	