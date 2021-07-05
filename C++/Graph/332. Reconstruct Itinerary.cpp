class Solution {
public:
    // can also just use multiset<string>
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> flights;

    vector<string> itinerary;

    void dfs(string& curr) {
        while (flights.count(curr) && flights[curr].size() > 0) {
            string arrive = flights[curr].top();
            flights[curr].pop();
            dfs(arrive);
        }
        itinerary.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            string depart = ticket[0], arrive = ticket[1];
            flights[depart].push(arrive);
        }
        string currPos = "JFK";
        dfs(currPos);

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};