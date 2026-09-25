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
    bool isSymmetric(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return true;
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root->left,root->right});
        while(!q.empty()){
            TreeNode* n1 = q.front().first;
            TreeNode*n2 = q.front().second;
            q.pop();

            if(n1 == NULL && n2 == NULL)  continue;
            if((n1 == NULL && n2 != NULL) || ( n1 != NULL && n2 == NULL)) return false;
            
            if(n1->val != n2->val) return false;

            q.push({n1->right,n2->left});
            q.push({n1->left,n2->right});



        
        }
        return true;

        
        
        
    }
};