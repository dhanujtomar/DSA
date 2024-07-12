#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void print(Node *head);
void insertAtHead(Node *&head, int val);
void insertAtTail(Node *&tail, int val);

bool checkPalindome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }
    else if (head->next->next == nullptr && head->data != head->next->data)
    {
        return false;
    }

    Node *s = head->next;
    Node *fast = head->next->next;
    Node *tail;

    while (fast != nullptr && fast->next != nullptr)
    {
        tail = s;
        s = s->next;
        fast = fast->next->next;
    }
    tail->next = nullptr;

    Node *prev = nullptr;
    Node *curr = s;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node *temp1 = head;
    Node *temp2 = prev;

    while (temp1 != nullptr)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
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
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    print(head);

    cout << checkPalindome(head);

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
    cout << endl;
}