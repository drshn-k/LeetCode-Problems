class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         int n=nums.size();
        // int j=0,ans=0;
       

      

        // while(j<n){
        //   if(goal==0){

        //      int count=0;
        //      for(int i=j;i<n;i++){
        //       if(nums[i]==0)count++;
        //       else break;
        //      }
        //      cout<<count<<" "<<j<<" ";
        //      ans+= (count * (count+1))/2;
        //      if(count==n)return ans;
        //      if(count==0)j++;
        //      else j+=count;
        //    }
        //    else{ 
        //     int sum=0;
        //     for(int i=j;i<n;i++){
        //         sum+=nums[i];
        //         if(sum==goal){
        //             ans++;
        //         }
        //     } j++;
        //    }
           
        // }
        // return ans;

         int ans=0;
         unordered_map<int,int>mp;
         mp[0]=1;
         int sum=0;
         for(int i=0;i<n;i++){
            sum+=nums[i];
            int temp=sum-goal;
            if(mp.find(temp) == mp.end()){
                 mp[sum]++;
            }
            else{
                ans+=mp[temp];
                mp[sum]++;
            }
         }
     return ans; 
    }
};