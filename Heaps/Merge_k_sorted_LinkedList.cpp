// https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&count=25&page=1&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=SUBMISSION

// Following is the class structure of the Node class:

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

#include <queue>

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return (a->data > b->data);
    }
};

Node *mergeKLists(vector<Node *> &listArray)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    int k = listArray.size();
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != nullptr)
            minHeap.push(listArray[i]);
    }

    Node *head = nullptr;
    Node *tail = nullptr;

    while (!minHeap.empty())
    {
        Node *top = minHeap.top();
        minHeap.pop();

        if (top->next != nullptr)
            minHeap.push(top->next);

        if (head == nullptr)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}
