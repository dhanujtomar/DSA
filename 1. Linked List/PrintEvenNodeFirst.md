# Print Even Node First

## segregateEvenOdd(ListNode head) method:

Initialize two heads one for even and another for odd linkedlists with null value

    ListNode odd = null;
    ListNode even = null;

Similarly initialize two tails even and odd linkedlists with null value
-- this makes insertion at the end easy

    ListNode oddTail = null;
    ListNode evenTail = null;

Now traverse the main linkedlist using a while loop

    while(temp != null){

        create a new node value and assign it temp value (ie: temp.val)

        if(temp.val % 2 == 0){

            if value of even is null, assign it newNode (even = newNode)

            else assign next value of the evenTail (ie: evenTail.next = newNode)

            assign evenTail the newNode (ie: evenTail = newNode);
        }else{
            Similarly implement the "if condition - even" steps for the odd number
        }
        increment temp (ie: temp = temp.next)
    }

    now combine the two nodes
    as we know that even numbers are placed before the odd numbers we can point the evenTail to the odd head
    Thus,
    evenTail.next = odd;

    return even;    // this will return a linkedlist with even numbers in the begining and odd numbers at the end

// ctrl+shift+v to preview markdown
