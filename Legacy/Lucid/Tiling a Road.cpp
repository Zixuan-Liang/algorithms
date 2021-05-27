
int tilingRoad(int l, vector<int> tiles, unordered_map<int, int> memo) {
    if (memo.find(l) == memo.end()) {
        int res;
        if (l < 0) {
            res = 0;
        }
        else if(l == 0) {
            res = 1;
        }
        else {
            res = 0;
            for (int t : tiles) {
                res += tilingRoad(l - t);
            }
        }
        memo[l] = res;
    }
    return memo[l];
}