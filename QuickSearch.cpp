#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int PartitionAroundPivot(int left, int right, vector<int>& v)
{
    int pivot = v[(left + right) / 2];
    int new_pivot_idx = left;
    swap(v[right], v[(left + right)/2]);
    for(int i = left; i < right; i++)
    {
        if (v[i] > pivot)
            swap(v[i], v[new_pivot_idx++]);
    }
    swap(v[right], v[new_pivot_idx]);

    return new_pivot_idx;
}

int FindkthLargest(int k, vector<int>& v)
{
    if (k > v.size())
        return -1;

    int left = 0, right = v.size() - 1;
    while(left <= right)
    {
        int new_pivot_idx = PartitionAroundPivot(left, right, v);
        if (new_pivot_idx == k - 1)
            return v[new_pivot_idx];
        else if (new_pivot_idx < k - 1)
            left = new_pivot_idx + 1;
        else
            right = new_pivot_idx - 1;
            
    }
}

int FindkthSmallest(const int k, const vector<int>& v)
{
    if (k > v.size())
        return -1;

    priority_queue<int> pq;
    for(int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
        if (pq.size() > k)
            pq.pop();
    }

    return pq.top();
}
