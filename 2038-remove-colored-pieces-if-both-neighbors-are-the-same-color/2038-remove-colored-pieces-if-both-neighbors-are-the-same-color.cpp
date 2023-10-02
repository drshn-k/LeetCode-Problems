class Solution {
public:
     bool winnerOfGame(string s) {
        int c=0,d=0;
        for(int i=0; i<s.size();  i++)
        {
            if(s[i]=='A')
            {
                int l=0;
                while(i<s.size() && s[i]=='A')
                {
                    i++,l++;
                }
                if(l>=3)
                c+=l-2;
                i--;
            }
            else
            {
                 int l=0;
                while(i<s.size() && s[i]=='B')
                {
                    i++,l++;
                }
                if(l>=3)
                d+=l-2;
                i--;
            }
        }
        cout<<c<< " "<<d<<endl;
        return c>d;
        
    }
};