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
    void solve(TreeNode* root, string  temp, vector<string>& vec){
        if(root == NULL){
            return;
        }
        string value = to_string(root->val);
        temp += value;
        if(root->left == NULL && root->right == NULL){
            vec.push_back(temp);
            return;
            
            
        }
        string another = temp + "->";
        solve(root->left, another, vec);
       
        solve(root->right,another,vec);

        
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>vec;
        string temp = "";
        solve(root,temp,vec);
        return vec;

        
    }
};