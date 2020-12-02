#include <iostream>
#include <unordered_map>
#include <string>

char MaximumOccurringCharacter(std::string str){
    std::unordered_map<char, std::pair<int, int>> map;
    for (int i = 0; i < str.length(); i++){
        if (map.find(str[i]) != map.end()){
            map[str[i]].second++;
        }
        else{
            map[str[i]] = std::make_pair(i, 1);
        }
    }
    std::pair<int, int> m(str.length()+1, 0);
    char result;
    for (auto const &x: map){
        if (x.second.second > m.second){
            m = x.second;
            result = x.first;
        }
        else if(x.second.second == m.second && x.second.first < m.first){
            m = x.second;
            result = x.first;
        }
    }
    return result;
}

int main(){
    std::cout << MaximumOccurringCharacter("hello,world") << std::endl;
}