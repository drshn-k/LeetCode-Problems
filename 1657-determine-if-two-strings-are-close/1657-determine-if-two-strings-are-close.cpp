class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        unordered_map <char , int> m , n ;
        
        set <char> a(word1.begin() , word1.end()); 
        set <char> b(word2.begin() , word2.end());
        
        string A , B;
        
       
        
        for(auto i : word1){
            m[i]++;
        }
        
        
        for(auto i : word2){
            n[i]++;
        }
        vector<int> v , c;
        
        for(auto i : m){
        v.push_back(i.second);    
        }
        
        for(auto i : n){
        c.push_back(i.second);    
        }
        
        sort(v.begin() , v.end());
        sort(c.begin() , c.end());
        
        for(int i = 0 ; i < v.size() ; i++){
            
            if(v[i] != c[i]) return false;
        }
        
       if(a == b) return true;
        else return false;
    }
};