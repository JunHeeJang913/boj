#include <iostream>
#include <string>

using namespace std;

template <class KeyType>
class Stack{
private:
    int top;
    KeyType * stack;
    int MaxSize;
public:
    Stack(int MaxStackSize=10001);
    bool isFull();
    void Push(const KeyType& item);
    bool isEmpty();
    KeyType Pop();
    KeyType Top();
    int Size();
};

template<class KeyType>
Stack<KeyType>::Stack(int MaxStackSize): MaxSize(MaxStackSize){
    stack = new KeyType[MaxSize];
    top = -1;
}

template<class KeyType>
inline bool Stack<KeyType>::isFull(){
    if(top == MaxSize - 1) return true;
    return false;
}

template<class KeyType>
inline bool Stack<KeyType>::isEmpty(){
    if(top == -1) return true;
    return false;
}

template<class KeyType>
void Stack<KeyType>::Push(const KeyType& x){
    if(isFull()) return;
    else stack[++top] = x;
}

template<class KeyType>
KeyType Stack<KeyType>::Pop(){
    if(isEmpty()==true) return -1;
    return stack[top--];
}

template <class KeyType>
KeyType Stack<KeyType>::Top(){
    if(isEmpty()==true) return -1;
    return stack[top];
}

template <class KeyType>
int Stack<KeyType>::Size(){
    return top + 1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n_orders; cin >> n_orders;
    Stack<int> s;
    for(int i = 0; i < n_orders; ++i){
        string order; cin >> order;
        if(order == "push"){
            int num; cin >> num;
            s.Push(num);
        }
        else if(order == "pop"){
            cout << s.Pop() << '\n';
        }
        else if(order == "size"){
            cout << s.Size() << '\n';
        }
        else if(order == "empty"){
            if(s.isEmpty() == true) 
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(order == "top"){
            cout << s.Top() << '\n';
        }
    }

    return 0;
}