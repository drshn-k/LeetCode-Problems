class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int prod=1,ans=0, n = nums.size();
        
        for(int i=0,j=0;j<n;j++)
        {
            prod*=nums[j];
            
            while(i<=j && prod>=k)
                prod /=nums[i++];
            
            ans+= j-i+1;
                
        }
        return ans; 
    }
};