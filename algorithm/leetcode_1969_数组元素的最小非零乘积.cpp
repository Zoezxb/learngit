/*
	2021/8/15 第254场周赛
	快速幂
	
*/
class Solution {
public:
    typedef long long LL;
    static const int MOD = 1e9+7;
    LL qpow(LL a, LL x)
    {
        LL ret = 1;
        while(x)
        {
            if(x & 1) ret = (LL) ret * a % MOD;
            x >>= 1;
            a = (LL)a*a %MOD;
        }
        return ret;
    }
    int minNonZeroProduct(int p) {
        LL res = ((1LL<<p)-1)%MOD;
        LL pairs = (1LL<<(p-1))-1;
        LL ans = qpow((res-1),pairs);
        ans = ans * res %MOD;
        return ans;
    }
};