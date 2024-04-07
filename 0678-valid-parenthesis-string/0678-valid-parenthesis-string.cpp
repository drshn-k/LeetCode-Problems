class Solution {
public:
 bool ex(int ind, int op, string &s, vector<vector<int>>&dp){

        if(ind == s.size()) return (op == 0);

        if(dp[ind][op] != -1) return dp[ind][op];
        bool ans = false;
        if(s[ind] == '*'){
            ans |= ex(ind+1, op+1, s, dp);
            if(op) ans |= ex(ind+1, op-1, s, dp);
            ans |= ex(ind+1, op, s, dp);
        }else{
            if(s[ind]=='('){
                ans = ex(ind+1, op+1, s, dp);
            }else{
                if(op) ans = ex(ind+1, op-1,s ,dp);
            }
        }
        return dp[ind][op] = ans;
    }

    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));
        return ex(0,0,s,dp);   
    }
};