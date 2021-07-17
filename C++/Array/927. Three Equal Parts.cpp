class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        if (arr.size() < 3) {
            return {-1, -1};
        }
        vector<int> ones;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                ones.push_back(i);
            }
        }
        int len = ones.size();
        if (len == 0) {
            return {0, 2};
        }
        if (len % 3 != 0) {
            return {-1, -1};
        }
        vector<int> part1(begin(ones), begin(ones)+len/3);
        vector<int> part2(begin(ones)+len/3, begin(ones)+2*len/3);
        vector<int> part3(begin(ones)+2*len/3, end(ones));
        for (int i = 0; i < part1.size() - 1; i++) {
            int d1 = part1[i + 1] - part1[i];
            int d2 = part2[i + 1] - part2[i];
            int d3 = part3[i + 1] - part3[i];
            if (d1 != d2 || d1 != d3) {
                return {-1, -1};
            }
        }
        int tailZeros = arr.size() - 1 - part3.back();
        if (part2[0] - part1.back() - 1 < tailZeros || part3[0] - part2.back() - 1 < tailZeros) {
            return {-1, -1};
        }
        return {part1.back() + tailZeros, part2.back() + tailZeros + 1};
    }
};