package Stack;

import java.util.Scanner;
import java.util.Stack;

class Next_Greater_Element {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        Stack<Integer> stack = new Stack<>();
        int[] nge = new int[n];

        // Iterating the array from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Pop till the top element is smaller than current
            while (!stack.isEmpty() && stack.peek() > arr[i]) {
                stack.pop();
            }

            nge[i] = stack.isEmpty() ? -1 : stack.peek();

            // Push the current element to stack
            stack.push(arr[i]);
        }

        for (int i = 0; i < n; i++) {
            System.out.print(nge[i] + " ");
        }

        scanner.close();
    }
}
