/*
	738.单调递增的数字
*/
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);//10->01;
        int flag = -1;
        reverse(s.begin(),s.end());
        //cout<<s[0]<<endl;
        for(int i = 0;i<s.size()-1;i++)
        {
            if(s[i] < s[i+1])
            {
                s[i+1]--;
                flag = i;
            }
        }
        cout<<flag <<endl;
        if(flag!=-1)
        {
            for(int i = flag ;i>=0;i--)
            {
                s[i] = '9';
            }
            //s[flag+1]--;
        }
        reverse(s.begin(),s.end());
        return stoi(s);
    }
};