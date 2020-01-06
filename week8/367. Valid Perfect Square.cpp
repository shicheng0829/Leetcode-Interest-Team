class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int lo = 1, hi = sqrt(INT_MAX);
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (mid * mid == num)
                return true;
            else if (mid * mid < num)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
    }
};