class SnakeGame {
    
    int width;
    int height;
    vector<vector<int>> food;
    vector<vector<char>> grid;
    int foodIdx;
    deque<vector<int>> snake;
    int score;
    unordered_map<string, vector<int>> dirs = {{"U", {-1,0}},{"L", {0,-1}},{"R", {0,1}},{"D", {1,0}}};
    int m = 0;
    
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food = food;
        snake.push_back({0, 0});
        score = 0;
        grid = vector<vector<char>>(height, vector<char>(width, 'E')); // Empty
        grid[0][0] = 'S'; // Snake
        grid[food[0][0]][food[0][1]] = 'F'; // Food
        foodIdx = 1;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        m++;
        auto next = dirs[direction];
        vector<int> head = snake.front();
        int r = head[0] + next[0], c = head[1] + next[1];
        if (m == 19) {
            cout << "hehe" << endl;
        }
        if (r < 0 || r >= height || c < 0 || c >= width || grid[r][c] == 'S' && snake.back() != vector<int>{r, c}) { // Stupid corner case
            return -1;
        }
        else if (grid[r][c] == 'F') {
            grid[r][c] = 'S';
            snake.push_front({r, c});
            if (foodIdx < food.size()) {
                auto f = food[foodIdx];
                grid[f[0]][f[1]] = 'F'; foodIdx++;
            }
            return ++score;
        }
        else {
            grid[r][c] = 'S';
            snake.push_front({r, c});
            auto tail = snake.back();
            grid[tail[0]][tail[1]] = 'E';
            snake.pop_back();
            if (tail == vector<int>{r, c}) grid[r][c] = 'S'; // Stupid corner case
            return score;
        }
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */