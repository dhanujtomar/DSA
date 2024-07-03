package Queue;

import java.util.*;
import java.lang.*;
import java.io.*;

class Palindome_by_Splitting {
    public static void main(String[] args) throws java.lang.Exception {
        // your code goes here
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Deque<Integer> input = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            input.addLast(sc.nextInt());
        }

        Deque<Integer> frontQue = new ArrayDeque<>();
        Deque<Integer> endQue = new ArrayDeque<>();

        int count = 0;

        while (!input.isEmpty()) {
            int first = input.removeFirst();
            if (input.isEmpty()) {
                break;
            }
            int last = input.removeLast();
            int newNum = Math.max(first, last) - Math.min(first, last);

            if (first > last) {
                input.addFirst(newNum);
                count++;
            } else if (first < last) {
                input.addLast(newNum);
                count++;
            }

            frontQue.addLast(first);
            endQue.addFirst(last);
        }

        System.out.println(count);
    }
}
