// Question: https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655

#include <bits/stdc++.h>
using namespace std;
/****************************************************************
    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};
*****************************************************************/

int len(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while(temp) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void display (Node* ans) {
    Node* temp = ans;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* merge(Node* down, Node* right) {
    if(down == NULL)
        return right;
    if(right == NULL)
        return down;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    //merge 2 sorted Linked List
    while(down != NULL && right != NULL) {
        if(down -> data < right -> data ) {
            temp -> next = down;
            temp = down;
            down = down -> child;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while(down != NULL) {
        temp -> next =  down;
        temp = down;
        down = down -> child;
    }
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans = ans -> next;
    return ans;
}

Node* flattenLinkedList(Node* head) {
    if(head == NULL || head->next == NULL) {
        cout << "Test returned at " << head->data << endl;
        return head;
    }
    Node* down = head;
    Node* right = flattenLinkedList(head->next);
    down->next = NULL;
    Node* ans = merge(down, right);
    cout << "Test: ";
    display(ans);
    return ans;
}
