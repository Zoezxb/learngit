/*
2021/9/23 每日一题 
哈希表
*/
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int m = points.size();
        map<int,int>hash;
        int ans = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(j == i) continue;
                int n = cal(points[i],points[j]);
                hash[n]++;
            }
            for(auto &x:hash)
            {
                if(x.second >= 2)
                    ans += x.second*(x.second-1);
            }
            hash.clear();
        }
        return ans;
    }
    int cal (vector<int>& a, vector<int>&b)
    {
        int ans = 0;
        ans = (a[0]-b[0])*(a[0]-b[0])+
              (a[1]-b[1])*(a[1]-b[1]);
        return ans;
    }
};