class Solution
{
public:
    int findMinStep(string board, string hand)
    {
        vector<int> vec(26, 0);
        for (int i = 0; i < hand.size(); ++i)
        {
            vec[hand[i] - 'A']++;
        }
        int res = helper(board, vec);
        return res == 6 ? -1 : res;
    }
    int helper(string board, vector<int> &hand)
    {
        board = shrink(board);
        if (board == "")
            return 0;
        int res = 6;
        for (int i = 0, j = 0; j <= board.size(); ++j)
        {
            if (j < board.size() && board[i] == board[j])
                continue;
            int need = 3 - (j - i);
            if (need <= hand[board[i] - 'A'])
            {
                hand[board[i] - 'A'] -= need;
                res = min(res, need + helper(board.substr(0, i) + board.substr(j), hand));
                hand[board[i] - 'A'] += need;
            }
            i = j;
        }
        return res;
    }
    string shrink(string board)
    {
        for (int i = 0, j = 0; j <= board.size(); ++j)
        {
            if (j < board.size() && board[i] == board[j])
                continue;
            if (j - i >= 3)
            {
                return shrink(board.substr(0, i) + board.substr(j));
            }
            else
                i = j;
        }
        return board;
    }
};