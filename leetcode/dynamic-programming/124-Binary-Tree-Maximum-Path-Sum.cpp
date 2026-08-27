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

    int maxi = INT_MIN;
    int tree(TreeNode* root){
        if(root == NULL) return 0;

        int left = tree(root->left);
        int right = tree(root->right);
        left = max(0,left);
        right = max(0,right);
        int sum = root->val + left + right;
        maxi = max(maxi,sum);


        return root->val + max(left,right);

        
        
        
        
        

    }

    int maxPathSum(TreeNode* root) {
        // right sum nikaalo and left sum nikaalo 
        // agar koi node negative hai uska left and right sum nikaalenge 
        // agar join karne par sum badh raha to join karenge agar ghat raha to join nahi karenge

        tree(root);
        return maxi;
    }
};