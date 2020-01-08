class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        int row = matrix.size(), col = matrix[0].size();
        int lo = 0, hi = row * col - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int val = matrix[mid / col][mid % col];
            if (val == target)
            {
                return true;
            }
            else if (val > target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return false;
    }
};