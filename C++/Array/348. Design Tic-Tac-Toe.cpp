class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antiDiagonal;
    int n;

    TicTacToe(int n) {
        this->n = n;
        rows.assign(n, 0);
        cols.assign(n, 0);
        diagonal = 0;
        antiDiagonal = 0;
    }

    int move(int row, int col, int player) {
        int currentPlayer = (player == 1) ? 1 : -1;
        // update currentPlayer in rows and cols arrays
        rows[row] += currentPlayer;
        cols[col] += currentPlayer;
        // update diagonal
        if (row == col) {
            diagonal += currentPlayer;
        }
        // update anti diagonal
        if (col == (n - 1 - row)) {
            antiDiagonal += currentPlayer;
        }
        // check if the current player wins
        if (abs(rows[row]) == n ||
            abs(cols[col]) == n ||
            abs(diagonal) == n ||
            abs(antiDiagonal) == n) {
            return player;
        }
        // No one wins
        return 0;
    }
};
