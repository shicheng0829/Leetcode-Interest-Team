class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.empty())
            return res;
        int m = matrix.size(), n = matrix[0].size();
        int start_i = 0, start_j = 0, end_i = m - 1, end_j = n - 1;
        while (start_i <= end_i && start_j <= end_j)
        {
            for (int j = start_j; j <= end_j; ++j)
            {
                res.push_back(matrix[start_i][j]);
            }

            for (int i = start_i + 1; i <= end_i; ++i)
            {
                res.push_back(matrix[i][end_j]);
            }
            if (start_i < end_i && start_j < end_j)
            {
                for (int j = end_j - 1; j >= start_j + 1; --j)
                {
                    res.push_back(matrix[end_i][j]);
                }
                for (int i = end_i; i >= start_i + 1; --i)
                {
                    res.push_back(matrix[i][start_j]);
                }
            }
            ++start_i;
            ++start_j;
            --end_i;
            --end_j;
        }
        return res;
    }
};