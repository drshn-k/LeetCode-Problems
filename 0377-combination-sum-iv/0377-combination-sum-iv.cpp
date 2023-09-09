
class Solution {
public:
    int cnt =0;
    int t[201][1001];
    int solve(vector<int>nums,int target,int ind){
        if(target == 0){
            return 1;
        }
        
        if(target<0)return 0;

        if(t[ind][target] != -1)return t[ind][target];
        
        int res =0;
        for(int i=0;i<nums.size();i++){
            int take = solve(nums,target-nums[i],i);
            res+=take;
        }
        return t[ind][target] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
       return solve(nums,target,0);
    }
};