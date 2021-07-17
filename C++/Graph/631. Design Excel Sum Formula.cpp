class Excel {
public:
    Excel(int H, char W) {
        // initialization. Because r starts from 1, I used H+1 instead of H.
        Exl = vector<vector<int>> (H+1, vector<int>(W-'A'+1, 0));
        fward.clear();
        bward.clear();
    }
    
    void set(int r, char c, int v) {
        int col = c-'A', key = r*26+col;
        // update its value and all the sum related
        update(r, col, v);
        // This is a reset, so break all the forward links if existing
        if (bward.count(key)) {
            for (int k:bward[key]) {
                fward[k].erase(key);
            }
            bward[key].clear();
        }
    }
    // update a cell and all the sum related, using BFS
    // weights are used to improve efficiency for overlapping ranges
    void update(int r, int col, int v) {
        int prev = Exl[r][col];
        Exl[r][col] = v;
        // myq is keys for cells in next level, and update is the increment for each cell
        queue<int> myq, update;
        myq.push(r*26+col);
        update.push(v-prev);
        while (!myq.empty()) {
            int key = myq.front(), dif = update.front();
            myq.pop();
            update.pop();
            if (fward.count(key)) {
                for (auto it = fward[key].begin(); it != fward[key].end(); it++) {
                    int k = it->first;
                    myq.push(k);
                    update.push(dif*(it->second));
                    Exl[k/26][k%26] += dif*(it->second);
                }
            }
        }
    }
    
    int get(int r, char c) {
        return Exl[r][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        // this is another reset, so break all the forward links
        int col = c-'A', key = r*26+col, ans = 0;
        if (bward.count(key)) {
            for (int k:bward[key]) {
                fward[k].erase(key);
            }
            bward[key].clear();
        }
        // get the sum over multiple ranges
        for (string str:strs) {
            int p = str.find(':'), left, right, top, bot;
            left = str[0]-'A';
            right = str[p+1]-'A';
            if (p == -1) 
                top = stoi(str.substr(1));
            else
                top = stoi(str.substr(1, p-1));
            bot = stoi(str.substr(p+2));
            for (int i = top; i <= bot; ++i) {
                for (int j = left; j <= right; ++j) {
                    ans += Exl[i][j];
                    fward[i*26+j][key]++;
                    bward[key].insert(i*26+j);
                }
            }
        }
        // update this cell and all the sum related
        update(r, col, ans);
        return ans;
    }
private:
    // The key of a cell is defined as 26*row+col, which is int;
    // fward links a cell to all the cells which use it for sum, and it may be used for 
    // multiple times due to overlap ranges, so another map is used for its weight
    // bward links a cell to all the cells that contribute to its sum. When reset its value,
    // or reassign a new sum range to it, we need disconnect the forward link of those cells to it. 
    unordered_map<int, unordered_map<int, int>> fward;
    unordered_map<int, unordered_set<int>> bward;
    vector<vector<int>> Exl;
};