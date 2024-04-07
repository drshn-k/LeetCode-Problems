class Solution {
public:
    string makeGood(string s) {
            vector<char> stack; 
        for(auto i = 0; i < s.size(); i++){
            if(!stack.empty() && abs(int(stack.back())-int(s[i])) == 32){
                stack.pop_back();
                continue;
            }else{
                stack.push_back(s[i]);
            }
        }

        string result(stack.begin(), stack.end()); 
        return result;
    }
};