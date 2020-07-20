// Design your implementation of the circular queue. The circular queue is a
// linear data structure in which the operations are performed based on FIFO
// (First In First Out) principle and the last position is connected back to
// the first position to make a circle. It is also called "Ring Buffer".
//
// Your implementation should support following operations:
//
// MyCircularQueue(k): Constructor, set the size of the queue to be k.
// Front: Get the front item from the queue. If the queue is empty, return -1.
// Rear: Get the last item from the queue. If the queue is empty, return -1.
// enQueue(value): Insert an element into the circular queue. Return true if
// the operation is successful.
// deQueue(): Delete an element from the circular queue. Return true
// if the operation is successful.
// isEmpty(): Checks whether the circular queue is empty or not.
// isFull(): Checks whether the circular queue is full or not.

vector<int> v;
int size,head,tail;
bool flag;

MyCircularQueue(int k) {
    vector<int> temp(k);
    v = temp;
    head = tail = 0;
    flag = false;
    size = k;
}

/** Insert an element into the circular queue. Return true
if the operation is successful. */
bool enQueue(int value) {
    if(isFull())
        return false;
    if(head == tail && !flag)
        flag = true;
    v[tail] = value;
    tail = (tail+1)%size;
    return true;
}

/** Delete an element from the circular queue. Return true if the
operation is successful. */
bool deQueue() {
    if(isEmpty())
        return false;
    head = (head+1)%size;
    if(head == tail && flag)
        flag = false;
    return true;
}

/** Get the front item from the queue. */
int Front() {
    if(isEmpty()) return -1;
    return v[head];
}

/** Get the last item from the queue. */
int Rear() {
    if(isEmpty()) return -1;
    return v[(tail+size-1)%size];
}

/** Checks whether the circular queue is empty or not. */
bool isEmpty() {
    if(tail == head && !flag)
        return true;
    return false;
}

/** Checks whether the circular queue is full or not. */
bool isFull() {
    if(tail == head && flag)
        return true;
    return false;
}
