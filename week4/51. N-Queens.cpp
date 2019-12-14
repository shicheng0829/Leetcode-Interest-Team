class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        helper(0, board, res);
        return res;
    }
    void helper(int row, vector<string> &board, vector<vector<string>> &res)
    {
        if (row == board.size())
        {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < board.size(); ++i)
        {
            if (!isValid(row, i, board))
                continue;
            board[row][i] = 'Q';
            helper(row + 1, board, res);
            board[row][i] = '.';
        }
    }
    bool isValid(int row, int col, vector<string> &board)
    {
        //up
        for (int i = 0; i < row; ++i)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        //left up
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        //right up
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};