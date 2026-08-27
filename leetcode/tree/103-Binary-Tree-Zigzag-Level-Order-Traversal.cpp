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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {


        
        vector<vector<int>>ans;
        if(root == NULL) return ans;

        queue<TreeNode*>q;
        q.push(root);
        bool f = 0;

        while(!q.empty()){
            vector<int>vec;
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);

                if(node->left){
                    q.push(node->left);

                }
                if(node->right){
                    q.push(node->right);
                }  
            }
            if(f == 0){
                ans.push_back(vec);
                f = 1;
            }
            else{
                reverse(vec.begin(),vec.end());
                ans.push_back(vec);
                f = 0;
            }
            

        }
        return ans;
        
    }
};