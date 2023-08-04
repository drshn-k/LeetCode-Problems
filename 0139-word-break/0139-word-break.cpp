class Solution {
public:
    int dp[301];
    bool solve(int idx,string& s,map<string,int>& m)
    {
        if(idx>=s.size())
        return true;
        if(dp[idx]!=-1)
        return dp[idx];
        bool ans = false;
        string tmp= "";
        for(int i=0;i+idx<=s.size();i++)
        {
            tmp+=s[idx+i];
            if(m.find(tmp)!=m.end())
            {
                ans|=solve(idx+i+1,s,m);
            }
        }
        return dp[idx] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        map<string,int> m;
        for(auto &i:wordDict)
        m[i]++;
        return solve(0,s,m);
    }
};