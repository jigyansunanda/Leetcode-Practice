class Solution {
    char[][] board;
    final int BOARD_SIZE = 9;

    private boolean isValidRowPlacement(int row, char c) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == c) {
                return false;
            }
        }
        return true;
    }

    private boolean isValidColPlacement(int col, char c) {
        for (int row = 0; row < BOARD_SIZE; row++) {
            if (board[row][col] == c) {
                return false;
            }
        }
        return true;
    }

    private boolean isValidSquareBlockPlacement(int row, int col, char c) {
        int rowBlock = (row / 3) * 3;
        int colBlock = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[rowBlock + i][colBlock + j] == c) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean solveSudoku(int row, int col) {
        if (row == 9) return true;
        if (col == 9) return solveSudoku(row + 1, 0);
        if (board[row][col] != '.') return solveSudoku(row, col + 1);
        for (char c = '1'; c <= '9'; ++c) {
            if (!isValidColPlacement(col, c) || !isValidRowPlacement(row, c)) continue;
            if (!isValidSquareBlockPlacement(row, col, c)) continue;
            board[row][col] = c;
            if (solveSudoku(row, col + 1))
                return true;
            else
                board[row][col] = '.';
        }
        return false;
    }

    public void solveSudoku(char[][] board) {
        this.board = board;
        solveSudoku(0, 0);
    }
}