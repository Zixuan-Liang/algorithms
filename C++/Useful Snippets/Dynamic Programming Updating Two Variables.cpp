#include <functional>

using namespace std;

// 以斐波那契数列为例
int x, y;
tie(x, y) = pair{y, x + y};