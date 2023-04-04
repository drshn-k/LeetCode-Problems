class Solution {
public:
    int partitionString(string s) {
        
        unordered_set<char> st;
        int cnt = 1;
        for(auto i: s){
            
            if(st.find(i) != st.end()){
                cnt++;
                st.clear();
            }
            
            st.insert(i);
        }
        
        return cnt;
    }
};