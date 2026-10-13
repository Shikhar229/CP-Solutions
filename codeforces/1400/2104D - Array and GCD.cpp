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
const int MAXA =6000001;
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



bool check(vector<int>& a, int m) {

	//here I would check that after deleting m elements then it is possible to make all the elements prime or not
	// for making prime decrease the largest one -> smallest prime

	// TestCase 1 :
	// 5 5 5
	// 5 5 5(5->4->3->2) // 3 coin
	// 5 5 2
	// 5 5(5->4->3) 2// 2 coin
	// 5 3 2 // fine I gained coin lmao not lost

	// T2:
	// 4 delete par all 4
	// 3 delete par 2 2 3
	// 2 delete then delete 2 2 {3 4} remaining can be made prime
	// 1 delete : ->
	// 2 2 3 4
	// 2 2 3 4 (not work)
	// we go to O((nlogn))
	// but traversing and checking would cost me alot which prime is prime is present which not
	// sieve()
    int n= a.size();
    // m-> no. of elements I'm removing
    // total size of a is -> n
    // k = > no. of elements I'm keeping

    // then iterate over the prime vector we would assingn it
    int k = n-m;

    ll count = 0;

	ll sum = 0;
	for(int i = 0; i<  k; i++){
		sum += prime[i];
	}
	ll s2 = 0;
	// last se k elements last index n-1
	// n-1 - n-1-1
	// n-1 -> n-1-2
	for(int i = n-k; i < n; i++){
		s2 += a[i];
	}
	if(s2 >= sum){
		return true;
	}
	else{
		return false;
	}
	

    
    


}

// -----solve-----
void solve() {

	// given an array ->

	// apply any no. of times

	// pay one -> increase 1
	// gain one -> decrease 1

	// ideal ->
	// a[i] >= 2;
	// gcd(a[i],a[j]) == 1

	// we have to remove minimum no. of element to make array beautiful

	// try to make all elements to Prime

	// I have larger a[i] -> smaller prime
	// if it is possible to make the array all prime using the coin i got from the higher
	// you have to delete 1 coin which coin I would delete
	// then possibility is smaller ones delete
	// delete 2 all possible larger go to smaller prime
	// and the no. who could not go makes the difference
	// kya 4 element delete karke kaam chal jayega ok
	// go to 3 element chal jayega then go to 1
	// go to 2 element nahi chalega


	// agar 2 element delete karke kaam nahi chal raha hai to usse kam delete karenge to usse bhi kaam nahi chalega
	// 1 2 3 4 5
	// let's say array is size is 5 then
	// check for 1 2 3 4 5
	// let's say 2 element par nahi chalta uske aage wale par chalta hai
	// then it is monotonus
	// F F T T T
	// the first T is the answer umm... here definitely binary search on answer would use it

	// on number of deletion ok I would calll another function for checking kaam chalega nahi

	// Binary search on answer
	// lower -> 0 higher arr.size()
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());


	int l = 0;
	int r = a.size();

	int ans = n;
	

	while(l <= r) {
		int mid = (l+r)/2;
		if(check(a,mid)) {
			ans = mid;
			r = mid-1;

		}
		else {
			l = mid+1;
		}
	}
	cout << ans << "\n";





}

// ------Main----
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve();

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	

	// solve();

	return 0;
}