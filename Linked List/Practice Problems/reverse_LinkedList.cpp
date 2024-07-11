#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void insertAtHead(Node *&head, int val);
void print(Node *head);

Node *reverse(Node *head)
{
    Node *next = nullptr;
    Node *curr = head;
    Node *prev = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *recrusiveReverse(Node *head, Node *prev)
{
    if (head == nullptr)
        return prev;

    Node *curr = head;
    Node *next;

    next = curr->next;
    curr->next = prev;

    Node *newNode = recrusiveReverse(next, curr);
    return newNode;
}

Node *kGroups(Node *head, Node *prev, int k)
{
    if (head == nullptr)
    {
        return prev;
    }
    int count = 1;
    Node *next;
    Node *curr = head;

    while (count < k)
    {
        prev = curr;
        curr = curr->next;
        next = curr->next;
        count++;
    }
    curr->next = head;
    Node *newNode = kGroups(next, curr, k);
    return newNode;
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
    insertAtHead(head, 6);

    print(head);

    cout << endl;
    // head = reverse(head);
    Node *prev = nullptr;
    // head = recrusiveReverse(head, prev);
    head = kGroups(head, prev, 2);
    print(head);

    return 0;
}

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}