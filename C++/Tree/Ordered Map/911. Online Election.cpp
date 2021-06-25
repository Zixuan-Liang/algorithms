class TopVotedCandidate
{
    map<int, int> m;
    vector<int> times;

public:
    TopVotedCandidate(vector<int> persons, vector<int> times)
    {
        int n = persons.size(), lead = -1;
        this->times = times;
        map<int, int> count;
        for (int i = 0; i < n; ++i)
        {
            lead = ++count[persons[i]] >= count[lead] ? persons[i] : lead;
            m[times[i]] = lead;
        }
    }

    int q(int t)
    {
        return (--m.upper_bound(t))->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */