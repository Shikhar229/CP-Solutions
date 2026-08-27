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
    int maxi = 0;
    int check(TreeNode* root){
        if(root == NULL) return 0;
        int left = check(root->left);
        int right = check(root->right);

        // left and right subtree ki height nikaal li
        // ab dono ko jod diya
        int sum = left + right;
        maxi = max(maxi,sum);
        return 1+max(left,right);
        
        

    }

    int diameterOfBinaryTree(TreeNode* root) {
        // diameter of bianary tree is the length of the longest path between any two nodes in a tree . This path may or may not pass through the root.
        // kisi node ke left and right subtree ki height nikalo fir unko join karo 
        // maxi se check karo and update and jiski height badi hai usko return kar do

        check(root);
        return maxi;
        

        

        
        
    }
};