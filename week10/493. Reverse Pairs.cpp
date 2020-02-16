class Solution
{
public:
    // 归并排序
    void merge(vector<int> &nums, int begin, int mid, int end)
    {
        for (int k = begin; k <= end; ++k)
            temp[k] = nums[k];
        int i = begin, j = mid + 1;
        // merge[begin, mid], [mid+1,end]
        for (int k = begin; k <= end; ++k)
        {
            if (i > mid)
                nums[k] = temp[j++];
            else if (j > end)
                nums[k] = temp[i++];
            else if (temp[i] < temp[j])
                nums[k] = temp[i++];
            else
                nums[k] = temp[j++];
        }
    }
    int merge_sort(vector<int> &nums, int begin, int end)
    {
        if (begin < end)
        {
            int mid = (begin + end) / 2;
            int count = merge_sort(nums, begin, mid) + merge_sort(nums, mid + 1, end);
            int j = mid + 1;
            for (int i = begin; i <= mid; ++i)
            {
                while (j <= end && nums[i] > nums[j] * 2LL)
                    ++j;
                count += j - (mid + 1);
            }
            merge(nums, begin, mid, end);
            return count;
        }
        else
        {
            return 0;
        }
    }
    vector<int> temp;
    int reversePairs(vector<int> &nums)
    {
        temp = vector<int>(nums.size(), 0);
        return merge_sort(nums, 0, nums.size() - 1);
    }
};