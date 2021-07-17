#include <numeric> // accumulate, max_element
#include <algorithm> // sort

using namespace std;

vector<int> v(10, 0); // 10个0
v.resize(20);
fill(begin(v), end(v), 1); // 填满，初始化
int sum = accumulate(begin(v), end(v), 0); // 求和

sort(begin(v), end(v)); // 默认从小到大
sort(begin(v), end(v), greater<int>()); // 从大到小排序

vector<int>::iterator maxIt = max_element(begin(v), end(v)); // 最大值的位置
auto minIt = min_element(begin(v), end(v)); // 最小值的位置