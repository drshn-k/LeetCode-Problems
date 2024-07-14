class Solution {
public:
    string countOfAtoms(string formula) {
         int n = formula.length();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i=0;
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string, int>());
                i++;
            }
            else if(formula[i]==')'){
                unordered_map<string, int> mp = st.top();
                st.pop();
                i++;
                string multiplier;
                while(i<n && isdigit(formula[i])){
                    multiplier.push_back(formula[i]);
                    i++;
                }
                if(!multiplier.empty()){
                    int multiint = stoi(multiplier);
                    for(auto ele:mp){
                        string str = ele.first;
                        int count = ele.second;
                        mp[str] = count*multiint;
                    }
                }
                //merging into the stack's top map as the () is resolved
                for(auto ele:mp){
                    string element = ele.first;
                    int count = ele.second;
                    st.top()[element]+=count;
                }
            }
            else{
                string currele;
                currele.push_back(formula[i]);
                i++;
                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    currele.push_back(formula[i]);
                    i++;
                }
                string currcount;
                while(i<n && isdigit(formula[i])){
                    currcount.push_back(formula[i]);
                    i++;
                }
                int currint = (currcount.empty())?1:stoi(currcount);
                st.top()[currele] += currint;
            }
        }
        //now st will have only 1 ele as all other are merged by removing ()
        map<string, int> sortedmap(begin(st.top()), end(st.top()));
        string result;
        for(auto ele:sortedmap){
            string str = ele.first;
            result += str;
            int count = ele.second;
            if(count>1) result += to_string(count);
        }
        return result; 
    }
};