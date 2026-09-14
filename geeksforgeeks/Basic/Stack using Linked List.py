/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class myStack {

  public:
    Node* mainhead;
    
    Node* head;
    Node * prev;
    int s;
    myStack() {
        // Initialize your data members
        head  = NULL;
        mainhead = NULL;
        prev = NULL;
        s = 0;
        
    }

    bool isEmpty() {
        // check if the stack is empty
        return head == NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        
        
        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            mainhead = newNode;
        }
        else{
            prev = head;
            prev->next = newNode;
            head = head->next;
            
        }
        
        s++;
    }

    void pop() {
        // Removes the top element of the stack
        if(isEmpty()) return;
        if (s == 1) { 
            delete head; 
            head = NULL; 
            mainhead = NULL; 
            prev = NULL; 
            s--; 
            return; 
            
        }
        if(s == 2){
            Node* p = head;
            delete(p);
            head = prev;
            prev = NULL;
            s--;
            return;
            
        }
        
        Node* curr = mainhead;
        while(curr->next != prev){
            curr = curr->next;
        }
        prev->next = NULL;
        Node* p = head;
        delete(p);
        head = prev;
        prev = curr;
        s--;
        
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(head == NULL) return -1;
        return head->data;
    }

    int size() {
        // Returns the current size of the stack
        return s;
    }
};