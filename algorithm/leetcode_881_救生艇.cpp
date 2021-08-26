/*
	leetcode 881.救生艇
	贪心 双指针
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size()-1;
        int res = 0;
        for(int i = 0, j = n;i<=j;)
        {
            int ans = people[j];
            if(i!=j && ans < limit)
            {
                ans += people[i++];
            }
            if(ans > limit) i--;
            j--;
            res++;
        }
        return res;
    }
};