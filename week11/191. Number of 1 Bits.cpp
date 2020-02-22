class Solution
{
public:
    // 朴素做法
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n)
        {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
    // 利用n & (n-1) 每次将最后一位1置为0
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n)
        {
            res += 1;
            n = n & (n - 1);
        }
        return res;
    }
};