#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void reverseLinkedList(Node *&head, Node *&tail)
{
    tail = head;
    Node *curr = head;
    Node *forward = nullptr;
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

void reverseRecursively(Node *&head, Node *prev, Node *curr)
{
    if (head == nullptr)
    {
        head = prev;
        return;
    }
    head = head->next;
    curr->next = prev;
    reverseRecursively(head, curr, head);
}

Node *reverse(Node *head)
{
    if (head == nullptr || head->next == NULL)
        return head;

    Node *newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

Node *kReverse(Node *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }
    int count = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node *curr = head;
    while (count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != nullptr)
        kReverse(next, k);
    return prev;
}

int main()
{
    // head
    Node *head = new Node(1);
    // tail
    Node *tail = head;
    // insertion
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);

    insertAtTail(tail, 0);
    insertAtTail(tail, -1);
    insertAtTail(tail, -2);

    Node *prev = nullptr;
    Node *curr = head;
    print(head);
    // reverseLinkedList(head, tail);
    // reverseRecursively(head, prev, curr);
    head = reverse(head);
    cout << endl;
    print(head);

    return 0;
}