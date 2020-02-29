class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return;
        // 对角线翻转
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = i; j < matrix[0].size(); ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 水平翻转
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size() / 2; ++j)
            {
                swap(matrix[i][j], matrix[i][matrix[0].size() - 1 - j]);
            }
        }
    }
};