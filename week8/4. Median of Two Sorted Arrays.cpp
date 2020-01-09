class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        // 找nums1 + nums2 的 第left个 和 right个 的平均值
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    // 找到nums1 + nums2的第k个元素(k >= 1)
    int findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        // nums1 is empty
        if (i >= nums1.size())
            return nums2[j + k - 1];
        // nums2 is empty
        if (j >= nums2.size())
            return nums1[i + k - 1];
        if (k == 1)
            return min(nums1[i], nums2[j]);
        int mid_val1 = (i + k / 2 - 1 >= nums1.size()) ? INT_MAX : nums1[i + k / 2 - 1];
        int mid_val2 = (j + k / 2 - 1 >= nums2.size()) ? INT_MAX : nums2[j + k / 2 - 1];
        if (mid_val1 < mid_val2)
        {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        }
        else
        {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};