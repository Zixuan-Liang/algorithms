class TopVotedCandidate {
    
    vector<int> leads;
    vector<int> times;
    
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        leads.resize(times.size(), 0);
        unordered_map<int, int> count;
        int currLead = 0;
        for (int i = 0; i < persons.size(); i++) {
            int person = persons[i];
            count[person]++;
            if (count[person] >= currLead) {
                leads[i] = person;
                currLead = count[person];
            }
            else {
                leads[i] = leads[i-1];
            }
        }
    }
    
    int q(int t) {
        auto ub = upper_bound(times.begin(), times.end(), t);
        return leads[ub - 1 - times.begin()];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */