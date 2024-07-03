package Queue;

import java.util.*;
import java.lang.*;
import java.io.*;

class Rotate_String_Necklace {
    public static void main(String[] args) throws java.lang.Exception {
        // your code goes here
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();

        while (tc > 0) {

            int n = sc.nextInt(); // Number of perls
            int k = sc.nextInt(); // Number of rotations

            Queue<Long> perls = new LinkedList<>();

            for (int i = 0; i < n; i++) {
                perls.offer(sc.nextLong());
            }

            while (k > 0) {
                perls.offer(perls.poll());
                k--;
            }

            for (Long x : perls)
                System.out.print(x + " ");
            System.out.println();

            tc--;
        }
    }
}
