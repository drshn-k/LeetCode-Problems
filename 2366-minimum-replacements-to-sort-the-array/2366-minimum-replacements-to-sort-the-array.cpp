class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
          long long ans=0; 
         int n=nums.size();

         for(int i=n-2;i>=0;i--)
         {
                  long long x=ceil(double(nums[i])/nums[i+1]);
                  ans+=x-1;
                  nums[i]=nums[i]/x;
         }
         return ans; 
    }
};