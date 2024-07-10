#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void push_back(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void push_front(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void print(Node *temp)
{
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *chotiProblem = reverse(head->next);

    Node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    return chotiProblem;
}

int main()
{
    Node *head = new Node(3);
    Node *tail = head;

    push_back(tail, 4);
    push_front(head, 2);
    push_back(tail, 5);
    push_front(head, 1);

    print(head);
    print(head);
    print(tail);

    head = reverse(head);

    print(head);

    return 0;
}