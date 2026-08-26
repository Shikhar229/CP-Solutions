class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {   
        int size = INT_MAX;
        int i = 0;
        int count = 0;
        string small = "";
        for(int j = 0;j < s.size(); j++){
            if(s[j] == '1'){
                count++;
            }

            while(count > k && j >= i){
                if(s[i] == '1') count--;
                i++;
            }
            while(count == k && s[i] == '0'){
                i++;
            }

            if(count == k) {
                if(small == ""){
                    small = s.substr(i,j-i+1);
                    size = j-i+1;
                }
                string temp = s.substr(i,j-i+1);
                if(j-i+1 <size){
                    
                    small= temp;
                    size = j-i+1;

                }
                if(j-i+1 == size && temp < small){
                    small= temp;
                }
            }
        }
        return  small;


        
        
    }
};