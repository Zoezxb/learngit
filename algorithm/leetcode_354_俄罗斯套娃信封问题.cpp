/*
	354. 俄罗斯套娃信封问题
	最长单调上升子序列的变形
*/class Solution {
public:
static bool cmp(vector<int> &a ,vector<int> &b)
{
    if(a[0]!=b[0]) return a[0]<b[0];
    else 
        return a[1]>b[1];
}
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n = envelopes.size();
        vector<int>dp(n,1);
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};