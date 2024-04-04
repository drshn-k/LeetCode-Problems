class Solution {
public:
    int maxDepth(string s) {
       if(s=="")return 0;
        stack<char>stk;
        int ans=0;
        for(char& c:s){
            if(stk.empty()&&c==')')return false;
            else if(c=='('){
                stk.push('(');
                ans = max(ans,(int)stk.size());
            }
            if(c==')')stk.pop();
        }
        return (stk.size())?0:ans;   
    }
};