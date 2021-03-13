#include <iostream>
#include <string>

using namespace std;

template <class type>
class Deque {
private:
    int f_idx, b_idx;
    type* deque;
    int max_size;
    int cur_size;

public:
    Deque(int maxSize = 10000)
        : max_size(maxSize)
    {
        deque = new type[maxSize];
        f_idx = 0;
        b_idx = 0;
        //f_idx는 처음 원소를 b_idx는 마지막 원소 다음 인덱스
        cur_size = 0;
    }

    void push_front(const int& x)
    {
        f_idx = (f_idx - 1 + max_size) % max_size;
        deque[f_idx] = x;
        ++cur_size;
    }

    void push_back(const int& x)
    {
        deque[b_idx] = x;
        b_idx = (b_idx + 1) % max_size;
        ++cur_size;
    }

    type pop_front()
    {
        if (isEmpty() == true)
            return -1;
        type ret = deque[f_idx];
        f_idx = (f_idx + 1) % max_size;
        --cur_size;
        return ret;
    }

    type pop_back()
    {
        if (isEmpty() == true)
            return -1;
        b_idx = (b_idx - 1 + max_size) % max_size;
        type ret = deque[b_idx];
        --cur_size;
        return ret;
    }

    int size()
    {
        return cur_size;
    }

    bool isEmpty()
    {
        if (cur_size == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (cur_size == max_size)
            return true;
        return false;
    }

    type front()
    {
        if (isEmpty() == true)
            return -1;
        return deque[f_idx];
    }

    type back()
    {
        if (isEmpty() == true)
            return -1;
        int temp_idx = (b_idx - 1 + max_size) % max_size;
        return deque[temp_idx];
    }

    ~Deque()
    {
        delete[] deque;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    Deque<int> d;

    for (unsigned int i = 0; i < n; ++i) {
        string order;
        cin >> order;
        if (order == "push_back" || order == "push_front") {
            int num;
            cin >> num;
            if (order == "push_front") {
                d.push_front(num);
            } else {
                d.push_back(num);
            }
        }
        if (order == "pop_front") {
            if (d.isEmpty() == true)
                cout << -1 << '\n';
            else
                cout << d.pop_front() << '\n';
        }
        if (order == "pop_back") {
            if (d.isEmpty() == true)
                cout << -1 << '\n';
            else
                cout << d.pop_back() << '\n';       //FIXME: else 제발 쓰기....
        }
        if (order == "size")
            cout << d.size() << '\n';
        if (order == "empty") {
            if (d.isEmpty() == true)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        if (order == "front") {
            if (d.isEmpty() == true)
                cout << -1 << '\n';
            else
                cout << d.front() << '\n';
        }
        if (order == "back") {
            if (d.isEmpty() == true)
                cout << -1 << '\n';
            else
                cout << d.back() << '\n';
        }
    }

    return 0;
}