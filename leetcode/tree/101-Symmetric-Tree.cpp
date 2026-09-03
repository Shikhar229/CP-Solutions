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
        if(root -> left == NULL && root-> right == NULL) return true;
        queue<pair<TreeNode*, TreeNode*>>q;
        q.push({root->left,root->right});

        while(!q.empty()){
            TreeNode* root1 = q.front().first;
            TreeNode* root2 = q.front().second;
            q.pop();

            if(root1 == NULL && root2 == NULL) continue;
            if(root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL) return false;

            if(root1->val != root2->val)return false;


            q.push({root1->right,root2->left});
            q.push({root1->left,root2->right});

        }
        return true;
        
        
    }
};