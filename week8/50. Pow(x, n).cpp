class Solution
{
public:
    double myPow(double x, int n)
    {
        return helper(x, n);
    }
    double helper(double x, long long n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        double temp = myPow(x, n / 2);
        if (n % 2 == 1)
        {
            return temp * temp * x;
        }
        else
        {
            return temp * temp;
        }
    }
};