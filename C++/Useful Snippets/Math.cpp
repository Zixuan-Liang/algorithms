#include <numeric>

using namespace std;

// stl库的gcd在numeric头文件
// 自己实现gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

// 判断质数
// 质数有一个特点，就是它总是等于 6x-1 或者 6x+1，其中 x 是大于等于1的自然数。
// 所以循环的步长可以设为 6，然后每次只判断两侧的数即可。
bool isPrime(int x) {
    if (x <= 3) {
        return x > 1;
    }
    if (x % 6 != 1 && num % 6 != 5) {
        return false;
    }
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}