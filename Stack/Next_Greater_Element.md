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

push -1 to the stack
Traverse through the array from the end
Use a while loop to iterate throught the stack and pop elements from the stack until the top of the stack is greater than the array element or stack top == -1. ie:

    while(stack.peek()!=-1 & stack.peek()<arr[i])

Assign value to NGE = value at top of stack as it contains the next greatest number for the given index

    NGE[i] = stack.peek()

Append array element to the stack

    stack.push(arr[i])

Code:

    // initialize stack and the necessary elements
    // initialize NGE
    for(int i=n-1; i>=0; i--){
        while(stack.peek()!=-1 & stack.peek()>arr[i]){
            stack.pop();
        }

            NGE[i] = stack.peek()

            stack.push(arr[i])
    }

> [!Note]
> To implement the program for NEXT SMALLEST ELEMENT just change the < operator to > in the while loop
> ie: you now find smallest element in the stack instead of the greatest compared to the array element
