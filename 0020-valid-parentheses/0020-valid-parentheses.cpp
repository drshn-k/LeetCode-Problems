class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        
        if(s.size() == 1) return false;
        
        if(s[0] == '}' or s[0] == ']' or s[0] == ')') return false;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == '{' or s[i] == '[' or s[i] == '(') st.push(s[i]);
            
            else{
                if(!st.empty() && s[i] == '}' && st.top() == '{' ) st.pop(); 
                    
                else if(!st.empty() && s[i] == ']'&& st.top() == '[' ) st.pop(); 
                        
                        
                else if(!st.empty() && s[i] == ')'&& st.top() == '(' ) st.pop(); 
                
                else if (0) return false;

                else return false ;
                
            }
        }
        
        if(st.empty()) return true;
        
        else return false;
    }
};