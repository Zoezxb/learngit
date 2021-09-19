class MyCircularQueue {
public:
    int rear, front , n;
    vector<int>buffer;
    MyCircularQueue(int k) {
        buffer.resize(k+1);
        n = k+1;
        front = rear = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        buffer[rear] = value;
        rear = (rear +1) %n;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front +1 ) % n;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return buffer[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return buffer[(rear + n-1) %n];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear+1) % n == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */