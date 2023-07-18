class Solution {
    bool isValid(string& t, string& s, int k){
        int j = 0; 
        int cycle = 0 ;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[j]){
                j++ ;
                if(j == t.size()){
                    j = 0;
                    cycle++ ;
                    if(cycle == k)
                        return true ;
                }
            }
        }
        return false ;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int>alpha(26) ;
        vector<char>data ;
        for(auto ch : s)
            alpha[ch-'a']++ ;
        for(int i = 0; i < 26; i++)
        {
            if(alpha[i] >= k)
                data.push_back(i+'a') ;
        }
        
        string ans ;
        queue<string>q{{""}} ;
        while(!q.empty()){
            string cur = q.front() ;
            q.pop() ;
            for(auto ch : data){
                string nxt = cur + ch ;
                if(isValid(nxt, s, k)){
                    ans = nxt ;
                    q.push(nxt) ;
                }
            }
        }
        return ans ;
    }
};