class Solution {
public:
    vector<int> countBits(int n) {
         vector<int> ans(n+1,-1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
            int mod = i%2;
            int div = i/2;
            ans[i]=ans[div]+mod;  
        }
        return ans;
        
    }
};