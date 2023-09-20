class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<long long> pre(n+1) , suff(n+1);
        pre[0]=0;
        for(long long i=1;i<n+1;i++)
        {
            pre[i]=nums[i-1]+pre[i-1];
        }
        long long sum = 0 ; 
        for(long long i= n-1 ; i>=0;i--){
            sum+=nums[i];
            suff[i]=sum;
        }

        reverse(suff.begin(),suff.end());

        int ans=INT_MAX;

        if(suff[n]<x)return -1;
        
        int  ind = lower_bound(suff.begin(),suff.end(),x)-suff.begin();

        int i =0;
        while( i<n+1 && ind>=0){
            if(ind<0)break;
            sum = pre[i]+suff[ind];
            if(sum == x ) {
                ans=min(ans,i+ind);
                i++;
            }
            else if(sum>x){
                ind--;
            }
            else if(sum<x){
                i++;
            }
        }

    return ans==INT_MAX ? -1  : ans;

    }

};