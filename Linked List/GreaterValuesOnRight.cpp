#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node *compute(Node *head)
    {
        static int largestRight = -1;
        if(head->next == nullptr){
            largestRight = head->data;
            return head;
        }
        head->next = compute(head->next);
        
        if(largestRight > head->data){
            return head->next;
        }
        
        largestRight = head->data;
        return head;
    }
    
};