#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin >> s;
	
	string temp ="";
	map<char,int>mp;
	for(char c : s){
	    mp[c]++;
	}
	int odd = 0;
	char t;
	int f = 0;
	for(auto it = mp.begin(); it != mp.end(); ){
    if(it->second % 2 == 1){
        odd++;
        f = it->second;
        t = it->first;
        it = mp.erase(it);
    }
    else{
        string s(it->second / 2, it->first);
        temp += s;
        it->second /= 2;
        it++;
    }
}
	
	if(odd >= 2){
	    cout << "NO SOLUTION\n";
	}
	else if (odd <= 1){
	    string m(f,t);
	    temp += m;
	    for(auto it = mp.rbegin(); it != mp.rend(); it++){
	        string s(it->second ,it->first);
	        temp += s;
	    }
	    cout << temp << endl;
	   
	        
	}
	
	    
	    
	    
	    
	
	
	
	
	

}