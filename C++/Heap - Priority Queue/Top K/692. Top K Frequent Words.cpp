struct ComparePair{
    bool operator()(pair<string, int> const& a, pair<string, int> const& b){
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordCount;
        for (auto& w : words) wordCount[w]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> minHeap;
        for (auto& w : wordCount){
            minHeap.push({w.first, w.second});
            if (minHeap.size() > k) minHeap.pop();
        }
        vector<string> res;
        while (!minHeap.empty()){
            res.emplace_back(minHeap.top().first);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};