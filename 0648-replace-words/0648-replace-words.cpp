class Solution {
public:
    struct node{
      node* child[26]={NULL};  
      int isend;
    };
    void insert(string s,node* root)
    {
        int n=s.size();
        node* temp=root;
        for(int i=0;i<n;i++)
        {
            if((temp->child)[s[i]-'a']==NULL)
            {
                temp->isend=0;
                (temp->child)[s[i]-'a']=new node();
                temp=(temp->child)[s[i]-'a'];
                temp->isend=1;
            }
            else
            {
                if((((temp->child)[s[i]-'a'])->isend)==1)
                {
                    temp->isend=0;
                    return;
                }
                else
                {
                    temp->isend=0;
                    temp=(temp->child)[s[i]-'a'];
                    temp->isend=1;
                }
            }
        }
        return;
    }
    
    string cheakroot(string s,node* root)
    {
        int n=s.size();
        node* temp=root;
        
        string ans="";
        for(int i=0;i<n;i++)
        {
            if((temp->child)[s[i]-'a']!=NULL)
            {
                temp=(temp->child)[s[i]-'a'];
                ans+=s[i];
                if((temp->isend)==1)
                    return ans;
                
                
            }
            else
                break;
        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string str) {
        int len=dictionary.size();
        struct node* trie=new node();
        trie->isend=0;
        for(int i=0;i<len;i++)
        {
            insert(dictionary[i],trie);
        }
        int n=str.size();
        string curr="";
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(str[i]==' ')
            {
                // cout<<curr<<"\n";
                ans+=cheakroot(curr,trie);
                ans+=" ";
                curr="";
            }
            else
            {
                curr+=str[i];
            }
            
            if(i==n-1)
            {
                ans+=cheakroot(curr,trie);
            }
        }
        return ans;
    }
};