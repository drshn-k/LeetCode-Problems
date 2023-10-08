class Solution {
public:
int solve(vector<int>&nums1,vector<int>&nums2,int i,int j,int t,vector<vector<vector<int>>>&dp){
    if(i==nums1.size()  && j==nums2.size()){
        if(t==1){
            return 0;
        }
        return INT_MIN;
    }
    if(dp[i][j][t]!=-1){
        return dp[i][j][t];
    }
    long long int ans=INT_MIN;
    if(i<nums1.size()  && j<nums2.size()){
    ans=1LL*nums1[i]*nums2[j]+solve(nums1,nums2,i+1,j+1,1,dp);
    }
    long long int ans2=INT_MIN;
    if(j<nums2.size()){
    // ans2=arr[i]*arr[j]+solve(nums1,nums2,i+1,j+1);
    ans2=solve(nums1,nums2,i,j+1,t,dp);
    }
    long long int ans3=INT_MIN;
    if(i<nums1.size()){
     ans3=solve(nums1,nums2,i+1,j,t,dp);
    }
return dp[i][j][t]=max(ans,max(ans2,ans3));
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(2,-1)));
        return solve(nums1,nums2,0,0,0,dp);
    }
};