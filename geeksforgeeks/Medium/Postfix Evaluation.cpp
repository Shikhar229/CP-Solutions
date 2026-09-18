class Solution {
  public:
    int flow(int a, int b){
        if(a*b < 0 && a% b != 0){
            return (a/b) -1;
        }
        return a /b;
    }
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int>st;
        int n = arr.size();
        for(int i = 0; i< n; i++){
            if(isdigit(arr[i][0]) || (arr[i][0] == '-' && arr[i].size() > 1)){
                st.push(stoi(arr[i]));
            }
            else{
                
                if(st.size() < 2) return -1;
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if(arr[i] == "+"){
                    st.push(a + b);
                    
                }
                else if(arr[i] == "-"){
                    st.push(b-a);
                }
                else if(arr[i] == "*"){
                    st.push(a*b);
                }
                else if(arr[i] == "/"){
                    st.push(flow(b,a));
                    
                }
                else if(arr[i] == "^"){
                    st.push(round(pow(b,a)));
                }
            
                
            }
            
        }
        if(st.size() == 1) return st.top();
        return -1;
        
        
    }
};