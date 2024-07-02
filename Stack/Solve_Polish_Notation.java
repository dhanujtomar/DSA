package Stack;

import java.util.*;
import java.lang.*;
import java.io.*;

class Solve_Polish_Notation {
    public static void main(String[] args) throws java.lang.Exception {
        // your code goes here
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();
        sc.nextLine();

        while (tc > 0) {
            String input;
            int ans = 0;
            int lenght = sc.nextInt();
            sc.nextLine(); // consume newline character
            input = sc.nextLine();

            Deque<Integer> stack = new ArrayDeque<>();

            for (int i = 0; i < input.length(); i++) {
                char c = input.charAt(i);
                int result = 0;
                if (Character.isDigit(c)) {
                    int a = Integer.parseInt(c + "");
                    stack.push(a);
                } else {
                    if (c == '+') {
                        int A = stack.pop();
                        int B = stack.pop();
                        result = B + A;
                    } else if (c == '-') {
                        int A = stack.pop();
                        int B = stack.pop();
                        result = B - A;
                    } else {
                        int A = stack.pop();
                        int B = stack.pop();
                        result = B * A;
                    }

                    stack.push(result);
                }
                ans = result;
            }
            System.out.println(ans);
            tc--;
        }
    }
}