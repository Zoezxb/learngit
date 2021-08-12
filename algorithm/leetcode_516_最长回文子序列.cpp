/*
	516. 最长回文子序列
	二维dp 注意遍历顺序
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int res = 1;
        for(int i = 0;i<n;i++) dp[i][i] =1;
        for(int i= s.size()-1;i>=0;i--)
        {
            for(int j = i+1;j<n;j++)
            {
                //if(i==j) dp[i][j] = 1;
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
                //res = max(res, dp[i][j]);
            }
        }
        return dp[0][n-1];
    }
};