class Solution {
public:
    int countOrders(int n) {
         vector<long long int>dp(501, 0);
    dp[1]=1;
    dp[2]=6;
    for(int i=3;i<=n;i++){
        int gaps = 2*i-1;
        int sum = (gaps*(gaps+1))/2;
        dp[i]=(dp[i-1]*sum)%1000000007;
    }
    return (int)dp[n]; 
    }
};