#include <iostream>
#include <vector>

long VariantsCount(int n, int s0, int k, int b, int m, long a){
    std::vector<int> s;
    s.push_back(s0);
    for (int i = 0; i < n-1; i++){
        s.push_back(((k * s[i] + b) % m) + 1 + s[i]);
    }
    int count = 0, row = n - 1, col = 0;
    while(row > col){
        if (s[row] * s[col] > a){
            count += col;
            row -= 1;
        }
        else{
            col += 1;
        }
    }
    return 2 * count + (row+1) * (col+1) - (s[row] * s[col] > a);
}

int main(){
    std::cout << VariantsCount(3, 2, 3, 3, 2, 15) << std::endl;
    std::cout << VariantsCount(3, 1, 1, 1, 2, 4) << std::endl;
    return 0;
}