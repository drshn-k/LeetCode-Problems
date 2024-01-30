class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        for(auto& i: tokens){
            // cout << i << << 
            // cout << typeid(i).name() <<endl;
        if(i == "+" or i == "-" or i == "*" or i == "/"){
               int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
         //        char ch = i[0];
         // switch(ch) {
         //        case "+": x1=x2 + x1; break;
         //        case "-": x1 =x2 - x1; break;
         //        case "*": x1 =x2 * x1; break;
         //        case "/": x1 = x2/x1; break;
         //    }
            // if(i == "=\")
            if(i == "+") op1 = op2 + op1;
			if(i == "-") op1 = op2 - op1;
			if(i == "/") op1 = op2 / op1;
			if(i == "*") op1 = op2 * op1; 
                st.push(op1);

        }
            
            else{
            st.push(stoi(i));
                             
            }
            
            cout << i << " " << st.top() << endl;
        }
        
        return st.top();
        
    }
    
//     int evalRPN(vector<string>& tokens) {
// 	stack<int> s;
// 	for(auto& t : tokens) 
// 		if(t == "+" || t == "-" || t == "*" || t == "/") {
// 			int op1 = s.top(); s.pop();
// 			int op2 = s.top(); s.pop();
// 			if(t == "+") op1 = op2 + op1;
// 			if(t == "-") op1 = op2 - op1;
// 			if(t == "/") op1 = op2 / op1;
// 			if(t == "*") op1 = op2 * op1;   
// 			s.push(op1);
// 		}
// 		else s.push(stoi(t));    // stoi - converts from string to int     
// 	return s.top(); 
// }
};