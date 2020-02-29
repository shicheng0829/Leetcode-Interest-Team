class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int start = 0;
        int end = n - 1;
        int num = 1;
        while (num <= n * n)
        {
            if (start == end)
                res[start][end] = num++;
            // left to right
            for (int i = start; i < end; ++i)
                res[start][i] = num++;
            // top to bottom
            for (int i = start; i < end; ++i)
                res[i][end] = num++;
            // right to left
            for (int i = end; i >= start + 1; --i)
                res[end][i] = num++;
            // bottom to top
            for (int i = end; i >= start + 1; --i)
                res[i][start] = num++;
            start++;
            end--;
        }
        return res;
    }
};