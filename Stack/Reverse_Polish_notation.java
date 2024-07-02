package Stack;
import java.util.*;
import java.lang.*;
import java.io.*;

class Reverse_Polish_notation {
    public static void main(String[] args) throws java.lang.Exception {
        // your code goes here
        Deque<Character> stack = new ArrayDeque<>();
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();
        sc.nextLine();

        while (tc > 0) {
            String input;
            String ans = "";
            input = sc.nextLine();

            for (int i = 0; i < input.length(); i++) {
                char c = input.charAt(i);

                if (Character.isLetter(c)) {
                    ans += c;
                } else if (c == ')') {
                    ans += stack.pop();
                } else if (c == '(') {
                    continue;
                } else {
                    stack.push(c);
                }
            }
            System.out.println(ans);
            tc--;
        }
    }
}
