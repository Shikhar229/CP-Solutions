class myQueue {

  public:
    int* arr;
    int front;
    int rear;
    int size;
    int m;
    myQueue(int n) {
        // Define Data Structures
        m  = n;
        arr = new int[n];
        front = 0;
        rear = -1;
        size = 0;
        
    }

    bool isEmpty() {
        // check if the queue is empty
        return size == 0;
    }

    bool isFull() {
        // check if the queue is full
        return size == m;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()) return ;
        rear = (rear+ 1)% m;
        arr[rear] = x;
        size++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()) return;
        front = (front+1)% m;
        size--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()) return -1;
        return arr[front];
        
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()) return -1;
        return arr[rear];
    }
};