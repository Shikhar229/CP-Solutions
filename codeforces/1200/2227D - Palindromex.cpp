#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll INF = 1000000000000000000LL;



// ----Binary exponentiation---
ll binpow(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1)
            ans = (ans * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return ans;
}

// ------Sieve & Primes Computation-----
const int MAXA =2000005;
vector<bool>isPrime;
vector<int>prime;

void sieve() {
	isPrime.assign(MAXA, true);
	if(MAXA >= 0) {
		isPrime[0] = false;

	}
	if(MAXA >=1 ) {
		isPrime[1] = false;
	}
	for(int i = 2 ; i*i< MAXA ; i++) {
		if(isPrime[i]) {
			for(int j  = i*i ; j <MAXA ; j+= i) {
				isPrime[j] = false;
			}
		}
	}

    for(int i = 0; i< MAXA ; i++){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }

}

// -------GCD -------
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

// --------- ncr ------
ll ncr(ll n, ll r) {
    if (r > n - r)
        r = n - r;

    ll ans = 1;

    for (ll i = 1; i <= r; i++) {
        ans = ans * (n - i + 1) / i;
    }

    return ans;
}

// -------- Prime Check ----
bool checkPrime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (ll i = 3; i <= n / i; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

// Expected Complexity : -




// O(n) or O(nlogn) ->     think of-> sorting
                                // ->monotonocity(binary search)
                                // ->priority queue
// --------------------------/



// Observation : 
// that should be palindrome if two palindrome I got mex should be maximum
// can I get two palindrome 
// includes all the number of first substring no way 
// chalo mid se hi suru karo

// 0 1 0 1
//  pehle mid and mid+1 me jao if did not match
// then find the position of 0 where it is 
// see the position of 0
// 0 1 0 1
// pos of zero 0 and 2 
// go to the position of zero 

// case 1 : take both zero
// case 2 : take one zero {make it middle}
// case 3 : take another zero {make it middle}
// if I am making middle then left and right element should be equal
// maxZ(mex1, mex2 ,mex3)


// Hypothesis


// Conclusion





// -----solve-----
void solve() {
    int n;
    cin >> n;
    vector<vector<int>>pos(n);
    int m = 2*n;
    vector<int>a(m);
    int c1 = 1;
    int c2 = 1;
    int c3 = 1;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    int first = min(pos[0][0], pos[0][1]);
    int second = max(pos[0][0], pos[0][1]);

    vector<bool>v1(n+1, false);
    v1[0] = true;

    // int m = 2*n;
    // cout << first << " "<< second << endl;
    

    if(first > 0 && first < m-1){
        int l = first-1;
        int r = first+1;
        while((l >= 0 && r <= m-1) && a[l] == a[r]){
            // cout << a[l] << " "<< a[r] << endl;
            //  cout << "l = " << l << ", r = " << r << endl;
            // cout << a[l] << " " << a[r] << endl;
            v1[a[l]] = true;
            v1[a[r]] = true;
            l--;
            r++;

        }

    }
    // cout << "v1:" << endl;
    // for(int i = 0; i <= n; i++){
    //     if(v1[i] == true){
    //         cout << "present" << ' ';
    //     }
    //     else{
    //         cout << "absent" << ' ';
    //     }
    // }
    // cout << endl;

    vector<bool>v2(n+1, false);
    v2[0] = true;
    

    if(second > 0 && second < m-1){
        int l = second-1;
        int r = second+1;
        while((l >= 0 && r <= m-1) && a[l] == a[r]){
            v2[a[l]] = true;
            v2[a[r]] = true;
            l--;
            r++;

        }

    }
    vector<bool>v3(n+1,false);
    v3[0] = true;
    bool mid =  false;
    int l = first + 1;
    int r = second-1;
    while(l <= r){
        if((l >= 0 && r <= m-1) && a[l] == a[r]){
            
            v3[a[l]] = true;
            v3[a[r]] = true;
            l++;
            r--;
        }
        else{
            mid = true;
            break;
        }

    }
    if(!mid){
        int f = min(first,second)-1;
        int s = max(first,second)+1;
        while(f >= 0 && s <= m-1){
            // cout << "l = " << f << ", r = " << s << endl;
            // cout << a[f] << " " << a[s] << endl;
            if(a[f] == a[s]){
                v3[a[f]] = true;
                v3[a[s]] = true;
                
                
            }
            else{
                break;
            }
            f--;
            s++;
        }
        for(int i = 0; i <= n; i++){
            if(!v3[i]){
                c3 = i;
                break;
            }
        }

    }
    for(int i = 0; i <=n; i++){
        if(v1[i] == false){
            c1 = i;
            break;
           
        }
    }
    for(int i = 0; i <=n; i++){
        if(v2[i] == false){
            c2 = i;
            break;
           
        }
    }
    // cout << c1 << " " << c2 << " " << c3 << endl;

    
   
    cout << max({c1,c2,c3}) << endl;
    
    
    



}

// ------Main----
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    // solve();

    return 0;
}