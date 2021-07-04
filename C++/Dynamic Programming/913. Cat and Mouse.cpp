class Solution {
public:
    
    int n;
    int dp[105][55][55];
    vector<vector<int>> graph;
    
    // search(step,cat,mouse) 表示步数=step，猫到达位置cat，鼠到达位置mouse的情况下最终的胜负情况
    int search(int step, int mouse, int cat) {
        if (dp[step][mouse][cat] != -1) {
            return dp[step][mouse][cat];
        }
        int ans;
        if (step == 2 * (n + 1)) { // mouse到达洞最多需要n步(初始step=1) 说明mouse走n步还没达洞口 且cat也没抓住mouse
            ans = 0;
        }
        else if (cat == mouse) { // cat抓住mouse
            ans = 2;
        }
        else if (mouse == 0) { // mouse入洞
            ans = 1;
        }
        else if (step % 2 == 1) { // 奇数步：mouse走
            bool mouseCanWin = false;
            bool mouseCanDraw = false;
            // 对mouse最优的策略: 先看是否能mouse赢 再看是否能平 如果都不行则cat赢
            for (int mouseNext : graph[mouse]) {
                if (search(step+1, mouseNext, cat) == 1) {
                    mouseCanWin = true;
                    break;
                }
                else if (search(step+1, mouseNext, cat) == 0) {
                    mouseCanDraw = true;
                }
            }
            if (mouseCanWin) { // 先看是否能mouse赢
                ans = 1;
            }
            else if (mouseCanDraw) { // 再看是否能平
                ans = 0;
            }
            else { // 如果都不行则cat赢
                ans = 2;
            }
        }
        else if (step % 2 == 0) { // 偶数步: cat走
            bool catCanWin = false;
            bool catCanDraw = false;
            // 对cat最优的策略: 先看是否能cat赢 再看是否能平 如果都不行则mouse赢
            for (int catNext : graph[cat]) {
                if (catNext != 0) {
                    if (search(step+1, mouse, catNext) == 2) {
                        catCanWin = true;
                        break;
                    }
                    else if (search(step+1, mouse, catNext) == 0) {
                        catCanDraw = true;
                    }
                }
            }
            if (catCanWin) { // 先看是否能cat赢
                ans = 2;
            }
            else if (catCanDraw) { // 再看是否能平
                ans = 0;
            }
            else { // 如果都不行则mouse赢
                ans = 1;
            }
        }
        dp[step][mouse][cat] = ans;
        return ans;
    }
    
    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();
        memset(dp, -1, sizeof(dp));
        this->graph = graph;
        return search(1, 1, 2);
    }
};