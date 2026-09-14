class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c : s){
            if(c == '{' || c == '[' || c == '('){
                st.push(c);

            }
            else{
                if(st.empty())return false; 
                bool f = false;
                if(c == ')' && st.top() == '('){
                    st.pop();
                    f = true;
                }
                if(c == ']' && st.top() == '['){
                    st.pop();
                    f = true;
                }
                if(c == '}' && st.top() == '{'){
                    st.pop();
                    f = true;
                }
                if(!f)st.push(c);


            }
        }
        return st.empty();
        
    }
};