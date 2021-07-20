#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// Power Grid: minimum spanning tree
vector<vector<int>> minimum_spanning_tree(vector<vector<int>>& connection) {
    unordered_map<int, unordered_map<int, int>> adjs;
    for (auto edge : connection) {
        adjs[edge[0]][edge[1]] = edge[2];
        adjs[edge[1]][edge[0]] = edge[2];
    }
    vector<vector<int>> keys(adjs.size());
    for (int i = 0; i < keys.size(); i++) {
        keys[i] = {INT_MAX, i, -1}; // key value, node id, parent
    }
    keys[0][0] = 0;
    set<vector<int>> pq(keys.begin(), keys.end());
    unordered_set<int> tree;
    vector<vector<int>> ans;
    while (!pq.empty()) {
        vector<int> node = *pq.begin();
        pq.erase(pq.begin());
        if (node[2] != -1) {
            int p = min(node[1], node[2]), c = max(node[1], node[2]);
            ans.push_back({p, c, adjs[p][c]});
            tree.insert(p);
            tree.insert(c);
        }
        for (auto [neighbor_id, weight] : adjs[node[1]]) {
            if (!tree.count(neighbor_id) && weight < keys[neighbor_id][0]) {
                pq.erase(keys[neighbor_id]);
                keys[neighbor_id][0] = weight;
                keys[neighbor_id][2] = node[1];
                pq.insert(keys[neighbor_id]);
            }
        }
    }
    return ans;
}

// Employment tree
// 1120. Maximum Average Subtree
// https://leetcode.com/discuss/interview-question/797541/Amazon-Online-Assessment-2-SDE-1
struct TreeNode {
    int working_time;
    vector<TreeNode*> reportees;
    TreeNode(int t) {working_time = t;}
};

vector<int> employment_helper(TreeNode* node, double& max_time, TreeNode*& ans) {
    if (!node) {
        return {0, 0}; // number of employees, total months
    }
    int count = 1, total_time = node->working_time;
    if (!node->reportees.empty()) {
        for (TreeNode* r : node->reportees) {
            vector<int> v = employment_helper(r, max_time, ans);
            count += v[0];
            total_time += v[1];
        }
        double curr_time = 1.0 * total_time / count;
        if (curr_time > max_time) {
            ans = node;
            max_time = curr_time;
        }
    }
    return {count, total_time};
}

TreeNode* oldest_team(TreeNode* president) {
    double max_time = INT_MIN;
    TreeNode* ans;
    employment_helper(president, max_time, ans);
    return ans;
}

// 973. K Closest Points to Origin
int d2o(vector<int>& point) {
    return point[0] * point[0] + point[1] * point[1];
}

int partition(vector<vector<int>>& points, int left, int right, int pivotIdx) {
    int pivot = d2o(points[pivotIdx]);
    swap(points[right], points[pivotIdx]);
    int storeIdx = left;
    for (int i = left; i < right; i++) {
        if (d2o(points[i]) < pivot) {
            swap(points[i], points[storeIdx]);
            storeIdx++;
        }
    }
    swap(points[right], points[storeIdx]);
    return storeIdx;
}

void quickSelect(vector<vector<int>>& points, int left, int right, int kSmallestIdx) {
    if (left == right) {
        return ;
    }
    int pivotIdx = left + rand() % (right - left + 1);
    pivotIdx = partition(points, left, right, pivotIdx);
    if (pivotIdx == kSmallestIdx) {
        return ;
    }
    else if (pivotIdx > kSmallestIdx) {
        quickSelect(points, left, pivotIdx - 1, kSmallestIdx);
    }
    else {
        quickSelect(points, pivotIdx + 1, right, kSmallestIdx);
    }
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    quickSelect(points, 0, points.size() - 1, k - 1);
    return vector<vector<int>>(points.begin(), points.begin()+k);
}

// Count of substrings of length K with exactly K distinct characters
// Given string str of the lowercase alphabet and an integer K,
// the task is to count all substrings of length K which have exactly K distinct characters.
int count_substrings(string& s, int k) {
    if (s.size() < k) return 0;
    unordered_map<char, int> distinct;
    for (int i = 0; i < k; i++) {
        distinct[s[i]]++;
    }
    int ans = 0;
    if (distinct.size() == k) {
        ans++;
    }
    for (int i = k; i < s.size(); i++) {
        distinct[s[i]]++;
        distinct[s[i - k]]--;
        if (distinct[s[i - k]] == 0) {
            distinct.erase(s[i - k]);
        }
        if (distinct.size() == k) {
            ans++;
        }
    }
    return ans;
}

// Count of ways to split a given number into prime segments
//Input: str = “3175”
//Output: 3
//Explanation:
//There are 3 ways to split this string into prime numbers which are (31, 7, 5), (3, 17, 5), (317, 5).
bool isPrime(int x) {
    if (x <= 3) {
        return x > 1;
    }
    if (x % 6 != 1 && x % 6 != 5) {
        return false;
    }
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int prime_helper(string& s, int i, vector<int>& dp) {
    if (dp[i] != -1) {
        return dp[i];
    }
    int ans = 0;
    for (int len = 1; len <= 3; len++) { // 分解为<=1000的质数，所以len<=3，如果质数大小不限，则len<=i
        if (i - len >= 0 && s[i - len] != '0' && isPrime(stoi(s.substr(i-len, len)))) {
            ans += prime_helper(s, i - len, dp);
        }
    }
    dp[i] = ans;
    return ans;
}

int count_prime_strings(string& s) {
    int n = s.size();
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    return prime_helper(s, n, dp);
}

// 874. Walking Robot Simulation
struct PairHash {
    size_t operator()(const pair<int, int>& p)const {
        auto intHash = hash<int>();
        return intHash(p.first) ^ intHash(p.second);
    }
};

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_set<pair<int, int>, PairHash> lookup;
    for (auto obstacle : obstacles) {
        lookup.insert({obstacle[0], obstacle[1]});
    }
    vector<vector<int>> move = {{0,1},{1,0},{0,-1},{-1,0}};
    int direction = 0; // 0 : north, 1: east, 2: south, 3: west
    int x = 0, y = 0;
    int ans = 0;
    for (int command : commands) {
        if (command == -2) {
            direction = direction == 0 ? 3 : direction - 1;
        }
        else if (command == -1) {
            direction = direction == 3 ? 0 : direction + 1;
        }
        else {
            int dx = move[direction][0], dy = move[direction][1];
            for (int i = 0; i < command; i++) {
                if (!lookup.count({x + dx, y + dy})) {
                    x += dx;
                    y += dy;
                    ans = max(ans, x * x + y * y);
                }
                else {
                    break;
                }
            }
        }
    }
    return ans;
}

// 1. Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> lookup;
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];
        if (lookup.count(need)) {
            return {lookup[need], i};
        }
        else {
            lookup[nums[i]] = i;
        }
    }
    return {-1, -1};
}

// 1629. Slowest Key
char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    char ans = keysPressed[0];
    int longest_duration = releaseTimes[0];
    for (int i = 1; i < keysPressed.size(); i++) {
        int duration = releaseTimes[i] - releaseTimes[i - 1];
        if (duration > longest_duration || duration == longest_duration && keysPressed[i] > ans) {
            longest_duration = duration;
            ans = keysPressed[i];
        }
    }
    return ans;
}

// Find The Highest Profit
int find_profit(vector<int>& inventory, int order) {
    unordered_map<int, int> supplies;
    for (int count : inventory) {
        supplies[count]++;
    }
    int max_profit = *max_element(inventory.begin(), inventory.end());
    int ans = 0;
    while (order > 0 && max_profit > 0) {
        ans += max_profit * min(supplies[max_profit], order);
        order -= supplies[max_profit];
        supplies[--max_profit] += supplies[max_profit];
    }
    return ans;
}

// 1710. Maximum Units on a Truck
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& b1, const vector<int>& b2)->bool{
        return b1[1] > b2[1];
    });
    int ans = 0;
    int index = 0;
    while (truckSize > 0 && index < boxTypes.size()) {
        int boxes = boxTypes[index][0];
        int units = boxTypes[index][1];
        ans += units * min(truckSize, boxes);
        truckSize -= boxes;
        index++;
    }
    return ans;
}

// Greatest Common Divisor of n Numbers
int gcd_of_n_nums(vector<int>& A) {
    int ans = A[0];
    for (int i = 1; i < A.size(); i++) {
        ans = gcd(ans, A[i]);
    }
    return ans;
}

int main() {
    vector<vector<int>> connection = {{0,1,1},{1,2,4},{1,3,6},{3,4,5},{2,4,1}};
    vector<vector<int>> ans = minimum_spanning_tree(connection);
    cout << "Test" << endl;
    for (auto a : ans) {
        for (int n : a) {
            cout << n << " ";
        }
        cout << endl;
    }
//    vector<TreeNode*> A(8);
//    vector<int> vals = {20, 12, 18, 11, 2, 3, 15, 8};
//    for (int i = 0; i < 8; i++) {
//        A[i] = new TreeNode(vals[i]);
//    }
//    A[0]->reportees.push_back(A[1]);
//    A[0]->reportees.push_back(A[2]);
//    A[1]->reportees.push_back(A[3]);
//    A[1]->reportees.push_back(A[4]);
//    A[1]->reportees.push_back(A[5]);
//    A[2]->reportees.push_back(A[6]);
//    A[2]->reportees.push_back(A[7]);
//    cout << oldest_team(A[0])->working_time << endl;
    return 0;
}
