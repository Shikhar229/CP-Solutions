/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    bool check(ListNode* curr , ListNode * prev){
        ListNode* front;
        if(curr->next){
            front = curr->next;
            if(curr->val > front->val && curr->val > prev->val) return true;
            if(curr->val < front->val && curr->val < prev->val) return true;
        }
        return false;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        
        vector<int>ans(2,-1);
        if(head->next->next == NULL) return ans;
        ListNode* curr = head->next;
        ListNode* prev = head;

        bool found_first = false;
        int cnt = 0;


        int mini = INT_MAX;
        int maxi = INT_MIN;
        int first = -1;
        
        int gap = 0;



        int largest_gap = 0;
        while(curr!= NULL){

            if(found_first == true){
                gap++;
                largest_gap++;
                
            }

            if(check(curr,prev)){

                if(found_first == false){
                    // not any assigned first yet;
                    found_first = true;
                }
                else{
                    mini = min(mini,gap);
                    maxi = max(maxi,largest_gap);
                    
                }

                gap = 0;

            }
            
            
        
            prev = curr;
            curr = curr->next;
        }

        if(maxi != INT_MIN) ans[1] = maxi;
        if(mini != INT_MAX) ans[0] = mini; 
        return ans;
        

        
    }
};