class Solution {
public:

    bool search(vector<int>& nums, int target) {

        int n= nums.size();
        int l = 0;
        int r = n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[l] == nums[mid] && nums[mid] == nums[r]){
                l++;
                r--;
            }
            else{

                
                if(nums[mid] >= nums[l]){
                    //  i am in left
                    
                    if(nums[l] <= target  && nums[mid]> target){
                        r = mid-1;
                    }
                    else{
                        l  = mid+1;
                    }

                }
                else{
                    // I am in  the right

                    if(nums[r] >= target && nums[mid] < target){
                        l = mid+1;
                    }
                    else{
                        r = mid-1;
                    }
                }
            }
            
        }
        return false;
        
    }
};