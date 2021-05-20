#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int find_longest_consecutive(std::vector<int> bars){
    std::unordered_set<int> s;
    for (int bar: bars){
        s.insert(bar);
    }
    int result = 0;
    for (int bar: bars){
        if (s.find(bar - 1) == s.end()){
            int i = bar;
            while (s.find(i) != s.end()){
                i++;
            }
            result = std::max(result, i - bar);
        }
    }
    return result;
}

long prison(int n, int m, std::vector<int> h, std::vector<int> v){
    int hole_height = find_longest_consecutive(h) + 1;
    int hole_width = find_longest_consecutive(v) + 1;
    return hole_height * hole_width;
}

int main(){
    std::vector<int> arr{ 1, 9, 3, 10, 4, 20, 2 };
    std::cout << find_longest_consecutive(arr) << std::endl;
}