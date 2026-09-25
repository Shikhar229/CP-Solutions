/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  code here
        
        vector<int>ans;
        if(root == NULL){
            return {};
        }
    
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int n= q.size();
            for(int i = 0;i < n; i++){
                Node* temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
                if(i == n-1){
                    ans.push_back(temp->data);
                }
              
            }
        }
        return ans;
        
    }
};