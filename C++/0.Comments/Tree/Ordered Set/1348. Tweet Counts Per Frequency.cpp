class TweetCounts {
public:
    
    unordered_map<string, multiset<int>> tweets;
    
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if (!tweets.count(tweetName)) {
            return {};
        }
        int interval = 1;
        if (freq == "minute") {
            interval = 60;
        }
        else if (freq == "hour") {
            interval = 3600;
        }
        else if (freq == "day") {
            interval = 86400;
        }
        int size = (endTime - startTime) / interval + 1;
        vector<int> ans(size, 0);
        for (int i = 0; i < size; i++) {
            int start = startTime + i * interval;
            int end = min(endTime, startTime + (i + 1) * interval - 1);
            auto lb = tweets[tweetName].lower_bound(start);
            auto ub = tweets[tweetName].upper_bound(end);
            ans[i] = distance(lb, ub);
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */