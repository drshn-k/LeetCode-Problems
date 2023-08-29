class Solution {
public:

    int bestClosingTime(string s) {
        int i,n=s.length(),ans=0,mn;
        int no[n+1],yes[n+1];
        
        if(s[0]=='N')
        no[0]=1;
        else no[0]=0;
        
        for(i=1;i<n;i++)
        {
            no[i]=no[i-1];
            if(s[i]=='N')
            no[i]++;
        }
        no[n]=no[n-1];

        yes[n]=0;
        for(i=n-1;i>=0;i--)
        {
            yes[i]=yes[i+1];
            if(s[i]=='Y')
            yes[i]++;
        }

        mn=yes[0];
        for(i=1;i<=n;i++)
        {
            if(yes[i]+no[i-1]<mn)
            {
                mn=yes[i]+no[i-1];
                ans=i;
            }
        }

        return ans;
    }
};