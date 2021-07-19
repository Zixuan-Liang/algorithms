#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <tuple>

struct VectorHash {
    std::size_t operator()(const vector<string> &vec) const {
        string comb = "";
        for (auto& ele: vec){
            comb += ele;
        }
        return std::hash<string>{}(comb);
    }
};

bool mySortComp(tuple<string, int, string> a, tuple<string, int, string> b){
        return get<1>(a) < get<1>(b);
}

class Solution {
public:    
    
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        
        vector<tuple<string, int, string>> combineV;
        for (int i = 0; i < username.size(); i++){
            combineV.emplace_back(make_tuple(username[i], timestamp[i], website[i]));
        }
        sort(combineV.begin(), combineV.end(), mySortComp);
        
        unordered_map<string, unordered_set<vector<string>, VectorHash>> map1, map2, map3;
        unordered_map<vector<string>, int, VectorHash> seqMap;
        
        for (auto& t: combineV){
            string user = get<0>(t), web = get<2>(t);
            for (auto& p: map2[user]){
                vector<string> threeSeq = p;
                threeSeq.emplace_back(web);
                map3[user].insert(threeSeq);
            }
            for (auto& p: map1[user]){
                vector<string> twoSeq = p;
                twoSeq.emplace_back(web);
                map2[user].insert(twoSeq);
            }
            map1[user].insert(vector<string>{web});
        }
        
        int userCount = 0;
        vector<string> res;
        
        for (auto& p: map3){
            for (auto& seq: p.second){
                seqMap[seq]++;
                if (seqMap[seq] > userCount || (seqMap[seq] == userCount && seq < res)){
                    res = seq;
                    userCount = seqMap[seq];
                }
            }
        }
        
        return res;
        
    }
};