#include <iostream>
#include <vector>
#include <algorithm>

int MaxEvents(int n, std::vector<int> arrival, std::vector<int> duration){
    std::vector<std::pair<int, int>> arr_end;
    for(int i = 0; i < n; i++){
        arr_end.push_back(std::make_pair(arrival[i], arrival[i]+duration[i]));
    }
    std::sort(arr_end.begin(), arr_end.end(), [](std::pair<int, int> x, std::pair<int, int> y){return x.second <= y.second;});
    int event_count = 0;
    int greedy_end = 0;
    for (std::pair<int, int> item: arr_end){
        if(item.first >= greedy_end){
            event_count += 1;
            greedy_end = item.second;
        }
    }
    return event_count;
}

int main(){
    std::cout << MaxEvents(5, std::vector<int>{1, 3, 3, 5, 7}, std::vector<int>{2, 2, 1, 2, 1}) << std::endl;
    std::cout << MaxEvents(7, std::vector<int>{1, 3, 5, 7, 9, 10, 11}, std::vector<int>{3, 3, 3, 3, 3, 1, 1}) << std::endl;
    return 0;
}