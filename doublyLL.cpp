#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node *insertNode(Node *head, int n, int pos)
{
    Node *newNode = new Node(n);
    Node *temp = head;
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else if (temp != NULL)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;
    print(temp);
}

int main()
{
    Node *head = new Node(10);
    Node *head1 = new Node(20);
    Node *head2 = new Node(5);

    head->next = head1;
    head->prev = head2;
    head1->prev = head;
    head2->next = head;

    head2 = insertNode(head2, 100, 0);
    print(head2);
}
