/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode* , TreeNode*> parent;


    void dfs(TreeNode* root){
        if(root == NULL) return;

        if(root->left){
            parent[root->left] = root;
        }
        if(root->right){
            parent[root->right] = root;
        }

        dfs(root->left);
        dfs(root->right);
    }
    vector<int>ans;

    void atk(TreeNode* target, int k){

        queue<TreeNode*>q;
        unordered_set<TreeNode*>st;
        q.push(target);
        st.insert(target);
        while(!q.empty() && k >0 ){

            int n = q.size();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && (st.count(temp->left) == 0) ){
                    q.push(temp->left);
                    st.insert(temp->left);

                }
                if(temp->right && (st.count(temp->right) == 0) ){
                    q.push(temp->right);
                    st.insert(temp->right);
                    
                }

                if(parent.count(temp) && (st.count(parent[temp]) == 0)  ){
                    q.push(parent[temp]);
                    st.insert(parent[temp]);
                }

            }
            k--;
        }

        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        dfs(root);
        atk(target,k);
        return ans;
        
    }
};