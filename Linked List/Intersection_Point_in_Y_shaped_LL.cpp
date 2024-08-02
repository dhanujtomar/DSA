#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node *head1, Node *head2)
    {
        Node *tail = head2;

        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = head2;

        Node *slow = head1;
        Node *fast = head1;

        do
        {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        fast = head1;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow->data;
    }
};