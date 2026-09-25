/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>>ans;
    void traverse(Node* root, vector<int> & temp){
        if(root == NULL) return;
        
        temp.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(temp);
        }
        else{
            traverse(root->left, temp);
            traverse(root->right,temp);
        }
        
        temp.pop_back();
        
    }
    vector<vector<int>> paths(Node* root) {
        // code here
        
        vector<int>temp;
        traverse(root, temp);
        return ans;
        
    }
};