#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>

class Stack
{
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    void push(T element)
    {
        size++;
        Node<int> *newNode = new Node<int>(element);
        newNode->next = head;
        head = newNode;
    }

    T top()
    {
        if (isEmpty())
            return 0;
        return head->data;
    }

    T pop()
    {
        if (isEmpty())
            return 0;
        T poppedData = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return poppedData;
    }
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
    Stack<int> s;
    s.push(100);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    cout << s.getSize() << endl;

    cout << s.pop() << endl;

    cout << s.isEmpty() << endl;
    cout << s.pop() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
}
