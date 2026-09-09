/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* temp = head->next;
        Node* head2 = new Node(head->val);
        
        Node* prev = head2;
        
        
        
        Node * temp2 = head2;
        unordered_map<Node* , Node* > mp;
        mp[head] = head2;
        
        while(temp){
            Node* curr = new Node(temp->val);
            mp[temp] = curr;
            prev->next =curr;
            prev = curr;

            temp = temp->next;
        }
        
        temp = head;
        while(temp){
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return head2;

        
    }
};