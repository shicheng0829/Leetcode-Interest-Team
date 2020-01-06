class Solution
{
public:
    int mySqrt(int x)
    {
        long long lo = 1, hi = x;
        while (lo <= hi)
        {
            long long mid = (lo + hi) / 2;
            if (mid * mid == x || (mid * mid < x && (mid + 1) * (mid + 1) > x))
                return mid;
            else if (mid * mid < x)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return 0;
    }
};