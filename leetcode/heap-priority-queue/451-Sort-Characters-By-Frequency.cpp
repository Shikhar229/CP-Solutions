class Solution {
public:
    string frequencySort(string s) {
        // har character ki frequency nikaalenge 
        // har ek character ki frequency store karenge in space 26*2
        // isme se maximum frequency wala character lenge aur jitni bhi baar hai wo character utni baar push karenge aur mark kar denge ki freq = -2
        // O(n*26*2)
        // 52 - > 0 - 25 -> lowercase 
        // 26 - 51 -> uppercase 
        // 52 - 62 - > digits
        cout << 'c'- 'a' << endl; 
        vector<int>freq(62,0);
        for(char c : s){
            if(isdigit(c)){
                int dig = c-'0';
                freq[dig+52]++;
            }
            else if(islower(c)){
                freq[c-'a']++;
            }
            else{
                freq[(c-'A')+26]++;
            }
        }


        string t = "";
        for(int i = 0; i < 62; i++){
            int mx = -1;
            int idx = -1;
            for(int j = 0; j < 62; j++){
                if(freq[j] > mx){
                    mx = freq[j];
                    idx = j;
                }

            }
            char mc ;
            freq[idx] = -1;
            if(idx <= 25){
                mc = char('a'+idx);
                
            }
            else if(idx <= 51){
                mc = char(('A' + idx)-26);
            }
            else{
                mc = (idx-52)+'0';
                
            }
            for(int i = 0; i < mx; i++){
                t += mc;
            }
            
        }
    

        return t;
        
        
        
    }
};