class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        // find ithe index character exist in s or not
        // if it exist place that at the ith position and don't take that char
        // if not exist if there is any character which is just greater than is
        // exist if yes then place that if not exist break and return null
        // stirng

        // if we take vector for present if it present dec that count
        // and if not present what is the next greater character than that that
        // exist

        // sabhi character ki frequency aa gayi hai

        vector<int> freq(26) ;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            freq[idx]++;
        }
        // for finding next greater element
        // iterate over the array

        int st = -1;

        string a = "";
        for (int i = 0; i < target.size(); i++) {
            int idx = target[i] - 'a';
            if (freq[idx] >= 1) {
                a += target[i];
                freq[idx]--;

            } else {
                // I want next greater element
                // but there is dynamically changing
                st = i;
                break;
            }
        }
        // check from failure index to starting we found any ki usse greater mil
        // jaye if mil gaya to we take it and uske aage sorted lexico me laga
        // denge

        // sab arrange ho gaye
        if (st == -1) {
            st =  target.size()-1;
            char c = a.back();
            freq[c-'a']++;
            a.pop_back();
            
           
        }

        // kahi na kahi to jarurat pad rahi hai dhundne ki kya usse greater
        // element exist karta hai if exist karta hai then fine we put that char
        // and remaining character in lexico and if it not exist then backtrack
        // till we found that index ith character se koi bada hai if hai to
        // theek hai usko le lo and remaining ko lexico me agar i jo tak pahuch
        // ke aur peeche jaana pad raha to obviously nahi hai koi return empty
        // string

        // here wo go for st index
        // check isse bada koi hai

       

       

        

        while(st >= 0){
            int idx = target[st]-'a';
            cout << st << endl;

            int nge = -1;
            for(int i = idx + 1; i< 26; i++){
                cout << i << " " << freq[i] <<endl;
                if(freq[i]){
                    nge = i;
                    cout << "nge: "<< i << endl;
                
                    break;
                }




            }

            if(nge == -1 ){
                // is index ke liye greater nahi mila 

                if(st > 0){
                    cout << "ye chala \n";
                    char c = a.back();
                    freq[c-'a']++;
                    a.pop_back();

                }
                
            }
            else if(nge != -1){
                // mil gaya 
                
                // index of greater element to wo character me badal gaya

                // found at index index nge
                // ab nge wale char ko push kar dunga
                char ch = 'a'+ nge;
                a += ch;
                freq[nge]--;

                for(int i = 0;i < 26; i++){
                    a += string(freq[i],'a'+i);
                }
                return a;




            }
            st--;



        }
        return "";





    }
};