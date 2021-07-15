struct Node {
    Node* n11, * n12, * n21, * n22;
    int sum = 0;
    int row1, col1, row2, col2;
    Node(int r1, int c1, int r2, int c2) {
        row1 = r1;
        col1 = c1;
        row2 = r2;
        col2 = c2;
    }
};

class NumMatrix {
public:
    
    int m;
    int n;
    vector<vector<int>> A;
    Node* tree;
    
    Node* buildTree(int row1, int col1, int row2, int col2) {
        if (row1 > row2 || col1 > col2) return nullptr;
        Node* node = new Node(row1, col1, row2, col2);
        if (row1 == row2 && col1 == col2) {
            node->sum = A[row1][col1];
            return node;
        }
        int midRow = row1 + (row2 - row1) / 2;
        int midCol = col1 + (col2 - col1) / 2;
        node->n11 = buildTree(row1, col1, midRow, midCol);
        node->n12 = buildTree(row1, midCol+1, midRow, col2);
        node->n21 = buildTree(midRow+1, col1, row2, midCol);
        node->n22 = buildTree(midRow+1, midCol+1, row2, col2);
        node->sum += node->n11 == nullptr ? 0 : node->n11->sum;
        node->sum += node->n12 == nullptr ? 0 : node->n12->sum;
        node->sum += node->n21 == nullptr ? 0 : node->n21->sum;
        node->sum += node->n22 == nullptr ? 0 : node->n22->sum;
        return node;
    }
    
    NumMatrix(vector<vector<int>>& matrix) {
        A = matrix;
        m = matrix.size();
        n = matrix[0].size();
        tree = buildTree(0, 0, m-1, n-1);
    }
    
    void updateTree(Node* tree, int row, int col, int delta) {
        if (tree->row1 == tree->row2 && tree->col1 == tree->col2) {
            tree->sum += delta;
            return ;
        }
        int midRow = tree->row1 + (tree->row2 - tree->row1) / 2;
        int midCol = tree->col1 + (tree->col2 - tree->col1) / 2;
        if (row <= midRow) {
            if (col <= midCol) updateTree(tree->n11, row, col, delta);
            else updateTree(tree->n12, row, col, delta);
        }
        else {
            if (col <= midCol) updateTree(tree->n21, row, col, delta);
            else updateTree(tree->n22, row, col, delta);
        }
        tree->sum += delta;
    }
    
    void update(int row, int col, int val) {
        updateTree(tree, row, col, val-A[row][col]) ;
        A[row][col] = val;
    }
    
    int queryTree(Node* tree, int row1, int col1, int row2, int col2) {
        if (tree == nullptr) return 0;
        if (tree->row1 >= row1 && tree->row2 <= row2 && tree->col1 >= col1 && tree->col2 <= col2) return tree->sum;
        int ans = 0;
        if (tree->n11 && row1 <= tree->n11->row2 && col1 <= tree->n11->col2) {
            ans += queryTree(tree->n11, row1, col1, row2, col2);
        }
        if (tree->n12 && row1 <= tree->n12->row2 && col2 >= tree->n12->col1) {
            ans += queryTree(tree->n12, row1, col1, row2, col2);
        }
        if (tree->n21 && row2 >= tree->n21->row1 && col1 <= tree->n21->col2) {
            ans += queryTree(tree->n21, row1, col1, row2, col2);
        }
        if (tree->n22 && row2 >= tree->n22->row1 && col2 >= tree->n22->col1) {
            ans += queryTree(tree->n22, row1, col1, row2, col2);
        }
        return ans;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return queryTree(tree, row1, col1, row2, col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */