class Solution {
    
    int count = 0;
    unordered_map<int, string> umap;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        umap[count] = longUrl;
        return to_string(count++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return umap[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));