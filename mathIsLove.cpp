#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long Y;
        scanf("%lld", &Y);
        double n = (-1 + sqrt(1 + 8*Y)) / 2;
        if (n == (int)n) {
            printf("%d\n", (int)n);
        } else {
            printf("NAI\n");
        }
    }
    return 0;
}
