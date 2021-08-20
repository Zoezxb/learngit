/*
	leetcode 435 无重叠区间
*/
class Solution {
public:
    static bool cmp (vector<int> &a ,vector<int> &b)
    {
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int r = intervals[0][1];
        int res = 1;
        for(int i = 1;i<n;i++)
        {
            if(intervals[i][0]<r)
            {
                if(intervals[i][1]<=r)
                {
                    r = intervals[i][1];
                    continue;
                }
            }   
            if(intervals[i][0]>=r)
            {
                r = intervals[i][1];
                res++;
            }
        }
        return n - res;
    }
};