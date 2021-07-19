// Brute force O(N^2)
// vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
//     auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
//                     { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
//     sort(people.begin(), people.end(), comp);
//     vector<pair<int, int>> res;
//     for (auto& p : people) 
//         res.insert(res.begin() + p.second, p);
//     return res;
// }


// Binary index tree O(nlogn)
class Solution {
public:
    vector<int> BIT;
    int n;
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n = people.size();
        BIT = vector<int>(n+1, 0); //BIT[i+1] recorded the res[i] information because BIT[0] is not used.
        for(int i = 2; i <= n; i++) update(i, 1);  // BIT[1] is the 0th empty position, so we didn't add 1
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(n, vector<int>());
        for(int i = 0; i < n; i++){
            int l=0, r=n;
            while(l<r){
                int mid=l+(r-l)/2;
                if(getsum(mid+1)<people[i][1]) l=mid+1; // we need get the index mid empty information, but actually it's stored in BIT[mid+1]
                else r=mid;
            }
            res[l]=people[i];
            update(l+1, -1);
        }
        return res;
    }
    void update(int x, int v){
        for(int i = x; i <= n; i+=(i&-i)){
            BIT[i]+=v;
        }
    }
    int getsum(int x){
        int sum=0;
        for(int i = x; i > 0; i-=(i&-i)){
            sum += BIT[i];
        }
        return sum;
    }
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
};