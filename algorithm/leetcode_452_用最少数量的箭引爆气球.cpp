/*
	leetcode 452 用最少数量的箭引爆气球
	贪心
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });
       int res = 1 , r = points[0][1];
       for(int i = 1;i<points.size();i++)
       {
           if(r<points[i][0])
           {
               res++;
               r = points[i][1];
           }
       } 
       return res;
    }
};