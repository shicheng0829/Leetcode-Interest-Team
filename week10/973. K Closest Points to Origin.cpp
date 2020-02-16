class Solution
{
public:
    // 排序，时间复杂度O(nlogn)
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    //     auto cmp = [](vector<int> a, vector<int> b){
    //         return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
    //     };
    //     sort(points.begin(), points.end(), cmp);
    //     return vector<vector<int>>(points.begin(), points.begin() + K);
    // }

    int dist(vector<int> &a)
    {
        return a[0] * a[0] + a[1] * a[1];
    }
    int partition(vector<vector<int>> &points, int begin, int end)
    {
        int pivot = dist(points[begin]), i = begin, j = end + 1;
        while (1)
        {
            while (dist(points[++i]) < pivot)
                if (i == end)
                    break;
            while (dist(points[--j]) > pivot)
                if (j == begin)
                    break;
            if (i >= j)
                break;
            swap(points[i], points[j]);
        }
        swap(points[begin], points[j]);

        return j;
    }
    void sort(vector<vector<int>> &points, int begin, int end, int K)
    {
        int mid = partition(points, begin, end);
        if (mid == K - 1)
            return;
        else if (mid > K - 1)
            sort(points, begin, mid - 1, K);
        else if (mid < K - 1)
            sort(points, mid + 1, end, K);
    }
    // 基于partition的分治算法，时间复杂度O(n)
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        sort(points, 0, points.size() - 1, K);
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};