#include <iostream>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void insertAtHead(Node *&head, int val);
void insertAtTail(Node *&tail, int val);
void print(Node *head);

int detectLoop(Node *head)
{
    map<Node *, bool> m;
    Node *temp;

    while (head != nullptr && m[head] == false)
    {
        m[head] = true;
        temp = head;
        head = head->next;
    }
    if (head == nullptr)
        return -1;
    return temp->data;
}

int removeLoop(Node *head)
{
    Node *slow = head->next;
    Node *fast = head->next->next;
    Node *temp = fast;
    while (slow != fast && fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        temp = fast->next;
        fast = fast->next->next;
    }
    if (fast == nullptr || fast->next == nullptr)
    {
        return -1;
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        temp = fast;
        fast = fast->next;
    }
    temp->next = nullptr;
    return temp->data;
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

    insertAtTail(tail, 0);

    print(head);

    // tail->next = head->next;

    cout << endl;
    cout << detectLoop(head) << endl;

    cout << removeLoop(head) << endl;
    print(head);

    // print(head);

    return 0;
}

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