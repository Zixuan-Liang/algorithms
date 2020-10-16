#include <iostream>
#include <stack>
#include <string>

struct Record{
    char c;
    int freq;
};

std::string WordCompression(std::string str, int k){
    std::stack<Record> sta;
    for (char const &c: str){
        Record new_record = {c, 1};
        if (sta.empty()){
            sta.push(new_record);
        }
        else{
            Record top = sta.top();
            if (top.c == c){
                if (top.freq == k - 1){
                    for (int i = 0; i < k - 1; i++){
                        sta.pop();
                    }
                }
                else{
                    sta.push(Record{c, top.freq + 1});
                }
            }
            else{
                sta.push(new_record);
            }
        }
    }
    std::string result = "";
    while (!sta.empty()){
        result = sta.top().c + result;
        sta.pop();
    }
    return result;
}

int main(){
    std::cout << WordCompression("geeksforgeeks", 2) << std::endl;
    std::cout << WordCompression("abbcccb", 3) << std::endl;
    std::cout << WordCompression("bbcccb", 3) << std::endl;
}