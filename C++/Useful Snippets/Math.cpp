#include <numeric>

using namespace std;

// stl库的gcd在numeric头文件
// 自己实现gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}