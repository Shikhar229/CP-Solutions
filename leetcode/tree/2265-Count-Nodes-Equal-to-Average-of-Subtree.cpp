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
    int count = 0;
    pair<int,int>traverse(TreeNode* root){
        if(root == NULL) return {0,0};
        auto left = traverse(root->left);
        auto right = traverse(root->right);

        int sum = root->val + left.first + right.first;
        int c = left.second + right.second + 1;

        if(sum/c == root->val){
            count++;

        }

        return {sum,c};

        
    }
    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return count;


        
    }
};