class Solution {
public:
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
};