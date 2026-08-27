/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // level wise dekhenge ki match ho rahe ya nahi
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;

        if(p == NULL && q == NULL){
            return true;
        }
        else if((p == NULL && q != NULL) || (q == NULL && p != NULL)){
            return false;
        }

        q1.push(p);
        q2.push(q);

        bool found = false;
        while(!q1.empty() && !q2.empty()){
            TreeNode* t1 = q1.front();
            TreeNode* t2 = q2.front();
            q1.pop();
            q2.pop();

            if( (t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL) ){
                return false;
            }
            if(t1 == NULL && t2 == NULL) continue;
            else if(t1->val != t2->val) return false;


            q1.push(t1->left);
            q2.push(t2->left);
            q1.push(t1->right);
            q2.push(t2->right);

            


        }

        if(q1.size() != q2.size() || found == true) return false;
        return true;
        
    }
};