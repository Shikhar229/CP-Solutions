class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(char c : s){
            if(st.empty()) st.push(c);
            else{
                if(st.top() != c){
                    st.push(c);

                }
                else{
                    st.pop();
                }
            }
        }
        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        
        reverse(temp.begin(),temp.end());
        return temp;

        
    }
};