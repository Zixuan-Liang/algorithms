#include <iostream>
#include <vector>

int BeautifulArrays(std::vector<int> arr, int m){
    int consecutive_even = 0;
    std::vector<int> consecutive_evens;
    int odd_count = 0;
    for (auto const & item: arr){
        if (item % 2 == 0){
            consecutive_even++;
        }
        else{
            consecutive_evens.push_back(consecutive_even);
            consecutive_even = 0;
            odd_count++;
        }
    }
    consecutive_evens.push_back(consecutive_even);
    int ans = 0;
    for (int i = 0; i < odd_count - m + 1; i++){
        ans += (consecutive_evens[i]+1) * (consecutive_evens[i+m]+1);
    }
    return ans;
}

int main(){
    std::cout << BeautifulArrays(std::vector<int>{6,8,10,1,6,2,3,4,5,2,2,4}, 2) << std::endl;
    return 0;
}