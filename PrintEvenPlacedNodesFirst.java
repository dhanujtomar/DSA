import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class PrintEvenPlacedNodesFirst {
    // This is the required function
    static ListNode segregateEvenOdd(ListNode head) {
        if (head.next == null) {
            return head;
        }
        // Write your code here
        ListNode temp = head;

        ListNode odd = new ListNode(temp.val);

        temp = temp.next;
        ListNode even = new ListNode(temp.val);

        ListNode oddTail = odd;
        ListNode evenTail = even;

        temp = temp.next;
        if (temp.next == null) {
            return head;
        }
        while (temp != null) {
            // Odd List
            ListNode newOdd = new ListNode(temp.val);
            oddTail.next = newOdd;
            oddTail = newOdd;

            // Even List
            if (temp.next != null) {
                temp = temp.next;
                ListNode newEven = new ListNode(temp.val);
                evenTail.next = newEven;
                evenTail = newEven;
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