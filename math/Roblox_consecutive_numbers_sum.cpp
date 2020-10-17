#include <iostream>
#include <cmath>

int consecutive_numbers_sum(int N){
    int upper_limit = std::pow(2 * N + 0.25, 0.5) - 0.5 + 1;
    int count = 0;
    for (int k = 1; k < upper_limit; k++){
        if ((N - k*(k+1)/2)%k == 0){
            count++;
        }
    }
    return count;
}

int main(){
    std::cout << consecutive_numbers_sum(15) << std::endl;
}