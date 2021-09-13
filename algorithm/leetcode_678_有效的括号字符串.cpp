/*
	678.有效的括号字符串
	栈
	
*/
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(')
                left.push(i);
            else if(s[i]=='*')
                star.push(i);
            else
            {
                if(left.size())
                    left.pop();
                else if (star.size())
                    star.pop();
                else
                    return false;
            }
        }
        while(left.size() && star.size())
        {
            if(left.top()>star.top())
                return false;
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};