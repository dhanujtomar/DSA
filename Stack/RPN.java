package Stack;
import java.util.*;
import java.lang.*;
import java.io.*;

class RPN {
    public static int prec(char c){
        if(c == '+' || c=='-'){
            return 1;
        }
        return 2;
    }

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
                if(c >= 'a' && c <= 'z')
                    ans+= stack.pop();
                if(c == '('){
                    stack.push(c);
                }else if(c == ')'){
                    while(!stack.isEmpty() && stack.peek()!='('){
                        ans += stack.pop();
                    }
                    if (!stack.isEmpty())
                        stack.pop();
                }else{
                    while(!stack.isEmpty() && prec(stack.peek()) > prec(c)){
                        ans += stack.pop();
                    }
                    stack.push(c);
                }
            }
            while(!stack.isEmpty()){
                if(stack.peek() == '('){
                    stack.pop();
                    continue;
                }
                ans+=stack.pop();
            }

            System.out.println(ans);
            tc--;
        }
    }
}
