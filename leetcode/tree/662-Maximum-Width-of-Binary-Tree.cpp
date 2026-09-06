/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:


    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        int i = 0;
        q.push({root, i});
        unsigned long long maxi = 0;
        while (!q.empty()) {
            unsigned long long l = q.front().second;
            unsigned long long r = q.back().second;
            maxi = max(maxi, r - l + 1);

            int n = q.size();
            for (int j = 0; j < n; j++) {
                TreeNode* node = q.front().first;
                
                unsigned long long pos = q.front().second;
                q.pop();

                if (node->left) {
                    q.push({node->left, 2 * pos + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * pos+ 2});
                }
            }
        }
        return (int)maxi;
    }
};