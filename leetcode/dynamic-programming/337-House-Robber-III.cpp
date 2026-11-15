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
    pair<int,int>dfs(TreeNode* root){
        if(root == NULL) return {0,0};

        pair<int,int>left = dfs(root->left);
        pair<int,int>right =dfs(root->right);

        int x = root->val + left.second + right.second;
        int y = max(left.first , left.second) + max(right.first , right.second);

        return {x,y};
    }
    int rob(TreeNode* root) {
        // on each node -> have two information 
        // => if i take it then maximum ans from subtree If I don't take it then maximum sum

        pair<int,int>ans = dfs(root);
        return max(ans.first, ans.second);
        
    }
};