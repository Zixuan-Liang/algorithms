struct Tuple {
    int bitMask;
    int curr;
    int cost;

    Tuple(int bit, int n, int c) {
        bitMask = bit;
        curr = n;
        cost = c;
    }

    bool operator==(const Tuple& other) const {
        return bitMask == other.bitMask && curr == other.curr; // cost无所谓，因为只关心已访问节点和当前节点
    }
    
};

struct TupleHash {
    size_t operator() (const Tuple &p) const {
        return std::hash<int>{}(p.bitMask) ^ std::hash<int>{}(p.curr); // cost无所谓，因为只关心已访问节点和当前节点
    }
};

class Solution {
public:
     int shortestPathLength(vector<vector<int>>& graph) {

        int N = graph.size();

        queue<Tuple> q;
        unordered_set<Tuple, TupleHash> visited;

        for (int i = 0; i < N; i++) {
            int tmp = (1 << i);
            visited.insert(Tuple(tmp, i, 0));
            q.push(Tuple(tmp, i, 1));
        }

        while (!q.empty()) {
            Tuple curr = q.front();
            q.pop();

            if (curr.bitMask == (1 << N) - 1) {
                return curr.cost - 1;
            }
            else {
                auto& neighbors = graph[curr.curr];

                for (int v : neighbors) {
                    int bitMask = curr.bitMask;
                    bitMask |= (1 << v);

                    Tuple t(bitMask, v, 0);
                    if (!visited.count(t)) {
                        q.push(Tuple(bitMask, v, curr.cost + 1));
                        visited.insert(t);
                    }
                }
            }
        }
        return -1;
    }
};