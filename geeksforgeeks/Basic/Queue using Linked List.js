class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {
    

  public:
    int sz;
    Node* head;
    Node* tail;
    myQueue() {
        // Initialize your data members
        sz = 0;
        head = tail = NULL;
        
        
        
    }

    bool isEmpty() {
        // check if the queue is empty
        return sz == 0;
       
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* newNode = new Node(x);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
        
    }

    void dequeue() {
        // Removes the front element of the queue
        if(head == NULL) return;
        if(head->next == NULL){
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
        }
        sz--;
        
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(head == NULL) return -1;
        return head->data;
    }

    int size() {
        // Returns the current size of the queue
        return sz;
        
    }
};
