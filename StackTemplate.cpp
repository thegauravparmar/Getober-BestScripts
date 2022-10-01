#include <bits/stdc++.h>
using namespace std;

template <typename T>

class StackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        data = new T(4);
        nextIndex = 0;
        capacity = 4;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    void push(T element)
    {
        if (capacity == nextIndex)
        {
            T *newData = new T(capacity * 2);
            for (int i = 0; i < capacity; i++)
                newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    StackUsingArray<char> s;
    s.push(100);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    cout << s.size() << endl;

    cout << s.pop() << endl;

    cout << s.isEmpty() << endl;
    cout << s.pop() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
}
