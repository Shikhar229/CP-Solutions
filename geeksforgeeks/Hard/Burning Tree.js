/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    unordered_map<Node*, Node* > mp;
  public:

    void parent(Node* root){
        
        if(!root) return;
        if(root->left){
            mp[root->left] = root;
            
        }
        if(root->right){
            mp[root->right] = root;
        }
        
        parent(root->left);
        parent(root->right);
        
    }
    Node* find(Node* root, int target){
        
        if(root == NULL) return NULL;
        if(root->data == target){
            return root;
        } 
        Node* t = find(root->left, target);
        if(t != NULL){
            return t;
        }
        find(root->right, target);
        
        
    }
    
    int count(Node* target){
        
        
        unordered_set<int>visited;
        queue<Node*>q;
        q.push(target);
        visited.insert(target->data);
        int sec= 0;
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* temp = q.front();
                q.pop();
                
                if(temp->left && visited.count(temp->left->data) == 0){
                    q.push(temp->left);
                    visited.insert(temp->left->data);
                    
                }
                if(temp->right && visited.count(temp->right->data) == 0){
                    q.push(temp->right);
                    visited.insert(temp->right->data);
                    
                }
                
                if(mp.count(temp) && visited.count(mp[temp]->data)== 0){
                    q.push(mp[temp]);
                    visited.insert(mp[temp]->data);
                }
                
            }
            sec++;
            
        }
        
        return sec-1;
        
        
        
        
    }
    
    
    
  
  
    
    int minTime(Node* root, int target) {
        // code here
        // jab tak stack empty na ho jaye
        
        
        parent(root);
        
        Node* n = find(root, target);
        return count(n);
        
        
        
        
        
    }
};