#include <iostream>
#include <cmath> // Change math.h to cmath for C++

using namespace std;

void convertIntoDigits(int &n) {
    int ans = 0;
    int i = 0;

    while (n > 0) {
        int digit = n % 10;
        ans = ans + (digit * pow(10, i));

        n = n / 10;
        i++;
    }

    cout << ans;
}

int main() {
    int n = 345;
    convertIntoDigits(n);

    return 0;
}
