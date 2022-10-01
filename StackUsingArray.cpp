#include <bits/stdc++.h>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        data = new int(4);
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

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    void push(int element)
    {
        if (capacity == nextIndex)
        {
            int *newData = new int(capacity * 2);
            for (int i = 0; i < capacity; i++)
                newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    StackUsingArray s;
    s.push(10);
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
