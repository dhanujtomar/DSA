package Queue;

import java.util.*;
import java.lang.*;
import java.io.*;

class Stone_Pile {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();

        while (tc > 0) {

            int n = sc.nextInt();

            int who = -1;
            Queue<Long> stones = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                stones.offer(sc.nextLong());
            }

            while (n > 1) {
                // op1
                stones.offer(stones.poll());
                // op2
                stones.poll();
                n--;
                if (n == 1) {
                    who = 1;
                    break;
                }

                // op1
                stones.offer(stones.poll());
                // op1
                stones.offer(stones.poll());
                // op2
                stones.poll();
                who = 0;
                n--;
            }
            System.out.println(who + " " + stones.poll());
            tc--;
        }
    }
}
