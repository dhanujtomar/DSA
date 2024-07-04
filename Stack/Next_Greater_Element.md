# Next Greater Element

# Explaination

    NGE = Next Greatest Element
    For a given array    {4,2,14,7,1,9}
    for 4 NGE is 14
    for 2 NGE is 14
    for 14 NGE is -1 as there is no larger number than 14
    for 7 NGE is 9
    for 1 NGE is 9
    for 9 NGE is -1 as there is no larger number than 9

# Approach

1. Initialize:

   - Push -1 onto the stack to serve as a sentinel value.
   - Create an array NGE (Next Greater Element) to store the result.

2. Traverse the Array:

   - Iterate through the array from the end to the beginning.

3. Process Elements Using a Stack:

   - For each element in the array, use a while loop to check the stack.
   - Pop elements from the stack until the top of the stack is greater than the current array element or the top of the stack is -1.

4. Assign the Next Greater Element:

   - After the loop, the top of the stack will contain the next greater element for the current index. Assign this value to NGE.

5. Push Current Element to Stack:
   - Push the current array element onto the stack.

Code:

    // Initialize the stack and necessary elements
    // in java use deque to implement stack as Stack class is a legacy class
    Deque<Integer> stack = new ArrayDeque<>();
    stack.push(-1);
    int[] NGE = new int[n];

    // Traverse the array from the end to the beginning
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack until the top is greater than the current element or the top is -1
        while (stack.peek() != -1 && stack.peek() <= arr[i]) {
            stack.pop();
        }

        // Assign the next greater element
        NGE[i] = stack.peek();

        // Push the current array element onto the stack
        stack.push(arr[i]);
    }

> [!Note]
> To modify the algorithm for finding the Next Smallest Element, adjust the comparison operator in the while loop from < to >. This change ensures that the algorithm now finds the smallest element in the stack compared to the current array element.
