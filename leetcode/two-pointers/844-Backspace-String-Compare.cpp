class Solution {
public:
    string formation(string a){
        string temp;
        stack<char>st;
        for(char c : a){
            if(c == '#'){
                if(st.empty()){
                    continue;
                }
                st.pop();
            }
            else{
                st.push(c);
            }

        }
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        return temp;
    }
    bool backspaceCompare(string s, string t) {
        return formation(s) == formation(t);

        
    }
};