import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class PrintEvenNodeFirst {
    static ListNode segregateEvenOdd(ListNode head) {
        if (head.next == null) {
            return head;
        }
        // Write your code here
        ListNode temp = head;

        // initializing odd and even lists
        ListNode odd = null;
        ListNode even = null;

        // initializing odd and even lists Tails
        ListNode oddTail = null;
        ListNode evenTail = null;

        while (temp != null) {
            // Odd List
            ListNode newNode = new ListNode(temp.val);

            if (temp.val % 2 == 0) {
                if (even == null) {
                    even = newNode;
                } else {
                    evenTail.next = newNode;
                }
                evenTail = newNode;
            } else {
                if (odd == null) {
                    odd = newNode;
                } else {
                    oddTail.next = newNode;
                }
                oddTail = newNode;
            }

            temp = temp.next;
        }
        evenTail.next = odd;
        return even;
    }

    static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    static ListNode newNode(int data) {
        ListNode temp = new ListNode(data);
        temp.next = null;
        return temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        if (n <= 0) {
            return;
        }

        int val = sc.nextInt();
        ListNode head = newNode(val);
        ListNode current = head;

        for (int i = 1; i < n; ++i) {
            val = sc.nextInt();
            current.next = newNode(val);
            current = current.next;
        }

        head = segregateEvenOdd(head);
        printList(head);
    }
}