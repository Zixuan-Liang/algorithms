class Trie {
public:
    
    map<char, Trie*> next = {};
    bool isword = false;
    string data;
    
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) { node->next[ch] = new Trie(); }
            node = node->next[ch];
        }
        node->isword = true;
        node->data = word;
    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) { return false; }
            node = node->next[ch];
        }
        return node->isword;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (!node->next.count(ch)) { return false; }
            node = node->next[ch];
        }
        return true;
    }
    
};

class Solution {

    Trie* trie = new Trie();
    int m;
    int n;
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

public:

    void backtrack(vector<vector<char>>& board, int row, int col, Trie* trie, unordered_set<string>& res) {
        char letter = board[row][col];
        Trie* currNode = trie->next[letter];
        if (currNode->isword) {
            res.insert(currNode->data);
        }
        board[row][col] = '#';
        for (auto d : dirs) {
            int newRow = row + d[0], newCol = col + d[1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && currNode->next.count(board[newRow][newCol]))
                backtrack(board, newRow, newCol, currNode, res);
        }
        board[row][col] = letter;
        if (currNode->next.empty()) {
            trie->next.erase(letter);
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string w : words) {
            trie->insert(w);
        }
        m = board.size(); n = board[0].size();
        unordered_set<string> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (trie->startsWith(string(1, board[i][j]))) {
                    backtrack(board, i, j, trie, res);
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};