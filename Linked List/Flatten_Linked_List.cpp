#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    // Function which returns the  root of the flattened linked list.
    Node *merge2Sorted(Node *head1, Node *head2)
    {
        Node *curr1 = head1;
        Node *curr2 = head2;

        Node *head = nullptr;
        Node *tail = nullptr;

        while (curr1 != nullptr && curr2 != nullptr)
        {
            if (curr1->data < curr2->data)
            {
                if (head == nullptr)
                {
                    head = curr1;
                    curr1 = curr1->bottom;
                    tail = head;
                    tail->bottom = nullptr;
                }
                else
                {
                    tail->bottom = curr1;
                    curr1 = curr1->bottom;
                    tail = tail->bottom;
                    tail->bottom = nullptr;
                }
            }
            else
            {
                if (head == nullptr)
                {
                    head = curr2;
                    curr2 = curr2->bottom;
                    tail = head;
                    tail->bottom = nullptr;
                }
                else
                {
                    tail->bottom = curr2;
                    curr2 = curr2->bottom;
                    tail = tail->bottom;
                    tail->bottom = nullptr;
                }
            }
            if (curr1 != nullptr)
                tail->bottom = curr1;

            if (curr2 != nullptr)
                tail->bottom = curr2;
        }
        return head;
    }

    Node *flatten(Node *root)
    {
        Node *head = root;

        Node *curr = head->next;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            head = merge2Sorted(head, curr);
            curr = next;
        }

        return head;
    }
};