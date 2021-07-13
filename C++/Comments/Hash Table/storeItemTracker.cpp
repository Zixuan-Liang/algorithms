#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> split(string& s, string del = " ") {
    vector<string> res;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        res.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    res.push_back(s.substr(start, end - start));
    return res;
}

int storeItemTracker(vector<string>& pricelist, vector<string>& logs) {
    int ans = 0;
    unordered_map<string, int> prices;
    map<int, int> discount;
    discount[0] = 0;
    for (string p : pricelist) {
        vector<string> s = split(p, ": ");
        prices[s[0]] = stoi(s[1]);
    }
    unordered_map<string, int> count;
    for (auto [key, price] : prices) {
        count[key] = 0;
    }
    vector<tuple<int, int, string, int>> vec;
    for (string tran : logs) {
        vector<string> s1 = split(tran, ", ");
        vector<string> s2 = split(s1[0], " ");
        string op = s2[0];
        int op1;
        if (op == "discount") {
            op1 = 0;
        }
        else if (op == "supply") {
            op1 = 1;
        }
        else if (op == "sell") {
            op1 = 2;
        }
        int timestamp = stoi(s2[1]);
        int amount = stoi(s1[2]);
        vec.push_back({timestamp, op1, s1[1], amount});
    }
    sort(begin(vec), end(vec));
    for (auto tran : vec) {
        int timestamp = get<0>(tran);
        int op = get<1>(tran);
        string item = get<2>(tran);
        int amount = get<3>(tran);
        if (op == 0) {
            discount[timestamp] = amount;
            discount[timestamp + stoi(item)] = 0;
        }
        else if (op == 1) {
            count[item] += amount;
        }
        else if (op == 2) {
            if (count[item] >= amount) {
                count[item] -= amount;
                auto ub = discount.upper_bound(timestamp);
                if (ub == discount.end()) {
                    ans += prices[item] * amount;
                }
                else {
                    int price = ceil(prices[item] * (100 - (--ub)->second) / 100.0);
                    ans += price * amount;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<string> pricelist = {"A: 254","B: 880","C: 670"};
    vector<string> logs = {"supply 19809, B, 3", "discount 54001, 13315, 22", "supply 36483, B, 10",
                           "supply 84149, B, 41", "sell 45374, C, 13", "sell 57631, A, 3",
                            "discount 21888, 5108, 93", "sell 12183, C, 28", "supply 27675, C, 90",
                            "supply 21279, A, 61", "sell 32762, B, 3", "sell 37941, A, 9",
                            "supply 78524, B, 49", "supply 66149, A, 77", "supply 57805, A, 17",
                            "sell 30196, A, 92", "supply 60199, B, 65", "supply 75039, C, 72",
                            "discount 28454, 1317, 74", "supply 34044, B, 90"};
    cout << storeItemTracker(pricelist, logs) << endl;
    return 0;
}
