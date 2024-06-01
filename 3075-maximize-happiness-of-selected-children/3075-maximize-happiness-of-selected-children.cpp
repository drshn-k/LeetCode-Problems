class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
          sort(hap.begin(),hap.end(),greater<int> ());
        long long int summ=0;
        int j=0;
        for(int i=0;i<k;i++)
        {
            
            summ+=max(hap[j]-(j),0);
            j++;
        }
        return summ;
    }
};