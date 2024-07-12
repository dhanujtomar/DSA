
// url: https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

class Node
{
public:
    int data;
    Node *next = nullptr;
    Node *arb = nullptr;

    Node(int data) : data(data), next(nullptr), arb(nullptr) {}
};

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

class Solution
{
public:
    Node *copyList(Node *head)
    {
        Node *mptr = head; // main pointer

        if (mptr->next == nullptr)
        {
            Node *clone = new Node(mptr->data);
            if (mptr->arb == mptr)
            {
                clone->arb = clone;
            }
            return clone;
        }

        Node *cloneHead = nullptr;
        Node *cloneTail = nullptr;

        cloneTail = new Node(mptr->data);
        cloneHead = cloneTail;
        mptr = mptr->next;

        while (mptr != nullptr)
        {
            insertAtTail(cloneTail, mptr->data);
            mptr = mptr->next;
        }

        mptr = head;
        Node *temp1 = head;

        Node *newptr = cloneHead;
        Node *temp2 = cloneHead;

        while (mptr != nullptr)
        {
            if (mptr->arb == nullptr)
            {
                mptr = mptr->next;
                newptr = newptr->next;
                continue;
            }
            while (mptr->arb != temp1)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
                if (temp1 == nullptr)
                {
                    temp1 = head;
                    temp2 = cloneHead;
                }
            }
            newptr->arb = temp2;
            mptr = mptr->next;
            newptr = newptr->next;
        }
        return cloneHead;
    }
};
