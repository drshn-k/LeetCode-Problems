class Solution {
public:
    int solve(string &s1, string &s2,int idx1,int idx2,vector<vector<int>> &dp)
    {
        if(idx1==s1.length() || idx2==s2.length())
        return 0;

        if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];
        
        if(s1[idx1]==s2[idx2])
        {
            return dp[idx1][idx2]=int(s1[idx1]+solve(s1,s2,idx1+1,idx2+1,dp));
        }
        else
        return dp[idx1][idx2]=max(solve(s1,s2,idx1+1,idx2,dp),solve(s1,s2,idx1,idx2+1,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int total=0;
        int n1=s1.length(),n2=s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        for(int i=0;i<s1.length();i++)
        {
            total=total+int(s1[i]);
        }

        for(int i=0;i<s2.length();i++)
        {
            total=total+int(s2[i]);
        }

        return total-2*solve(s1,s2,0,0,dp);
    }
};