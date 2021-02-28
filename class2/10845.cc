#include <iostream>
#include <string>

using namespace std;

template<class type> 
class Queue{
private:
    int front, rear;
    type *queue;
    int max_size;
public:
    Queue(int max_q_size=10001):max_size(max_q_size){
        queue = new type[max_q_size];
        front = rear = -1; // if front == rear, the queue is empty;
    }
    bool isFull(){
        if(rear == max_size - 1) return true;
        else return false;
    }
    bool isEmpty(){
        if(rear == front) return true;
        return false;
    }
    void push(const type & x){
        if(isFull()) return;
        else queue[++rear] = x;
    }
    type pop(){
        if(isEmpty()) return -1;
        return queue[++front];
    }
    int size(){
        return rear - front;
    }
    type Front(){
        if(isEmpty()) return -1;
        return queue[front+1];
    }
    type back(){
        if(isEmpty()) return -1;
        return queue[rear];
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n_orders; cin >> n_orders;
    Queue<int> q;
    for(int i = 0; i < n_orders; ++i){
        string order; cin >> order;
        if(order == "push"){
            int num; cin >> num;
            q.push(num);
        }
        else if(order == "pop"){
            cout << q.pop() << '\n';
        }
        else if(order == "size"){
            cout << q.size() << '\n';
        }
        else if(order == "empty"){
            if(q.isEmpty() == true) 
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(order == "front"){
            cout << q.Front() << '\n';
        }
        else if(order == "back"){
            cout << q.back() << '\n';
        }
    }
}