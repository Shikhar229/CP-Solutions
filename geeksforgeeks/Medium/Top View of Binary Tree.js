/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        
        queue<pair<Node* , int>>q;
        map<int,int>mp;
        q.push({root,0});
        
        while(!q.empty()){
            Node* node = q.front().first;
            int dist = q.front().second;
            
            q.pop();
            if(mp.find(dist) == mp.end()){
                mp[dist] = node->data;
            }
            
            if(node->left){
                q.push({node->left,dist-1});
                
            }
            if(node->right){
                q.push({node->right,dist+1});
            }
            
            
        }
        vector<int>ans;
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
        
    }
};