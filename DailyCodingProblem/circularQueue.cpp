#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    deque<int> q;
    int maxsize;
    MyCircularQueue(int k) {
        maxsize=k;
    }
    
    bool enQueue(int value) {
        if(q.size()<maxsize)
        {
            q.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!q.empty())
        {
            q.pop_front();
            return true;
        }
        return false;
    }
    
    int Front() {
        if(!q.empty())
            return q.front();
        return -1;
    }
    
    int Rear() {
         if(!q.empty())
            return q.back();
        return -1;
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return q.size()==maxsize;
    }
};

class MyCircularQueue2 {
public:
    vector<int> q;
    int head, tail;
    int size;
    
    MyCircularQueue2(int k) {
        q.assign(k, -1);
        head = tail = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        tail = (tail + 1) % size;
        if (tail == 0 && head == -1) tail = head = 0;
        q[tail] = value;
        return true;
    }
    
    bool deQueue() {
       if (isEmpty()) return false;
        if (head == tail) head = tail = -1;
        else head = (head + 1) % size;
        return true;
    }
    
    int Front() {
        if (head != -1) return q[head];
        return -1;
    }
    
    int Rear() {
        if (tail != -1) return q[tail];
        return -1;
    }
    
    bool isEmpty() {
        return head == -1;
    }
    
    bool isFull() {
        return (tail + 1) % size == head;
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

int main(void)
{
	MyCircularQueue* obj = new MyCircularQueue(3);
	cout << obj->enQueue(1);
	cout <<  obj->enQueue(2);
	cout <<  obj->enQueue(3);
	cout << obj->deQueue();
	cout <<  obj->enQueue(4);
	cout << obj->Front();
	cout << obj->Rear();
	cout << obj->isEmpty();
	cout << obj->isFull();
	
	return 0;
}