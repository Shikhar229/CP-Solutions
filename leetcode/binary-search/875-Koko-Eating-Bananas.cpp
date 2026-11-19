class Solution {
public:
    #define ll long long
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        ll low = 1;
        ll high = 1e9 + 1;
        ll ans;
        while(low <= high){

            ll mid = low + (high-low)/2; //mid -> speed 


            ll hour_taken = 0;  //how many hours taken
            for(int i = 0; i< n; i++){
                
                hour_taken += (piles[i] + mid-1)/mid;
            }
            // cout <<mid << " " << hour_taken << endl;
            

            if(hour_taken <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return ans;
        

        
    }
};