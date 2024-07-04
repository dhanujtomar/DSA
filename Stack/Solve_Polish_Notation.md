# Solve Polish Notation
postfix to infix

this is a very simple programming problem as compared to infix to postfix

## Explaination
in this problem expressions are converted from postfix to infix form
ie:
    For the input: 2 1 + 3 *

1. Push 2 onto the stack.
2. Push 1 onto the stack.
3. Encounter +, pop 1 and 2, compute 2 + 1 = 3, push 3 back onto the stack.
4. Push 3 onto the stack.
5. Encounter *, pop 3 and 3, compute 3 * 3 = 9, push 9 back onto the stack.
6. The stack now contains 9, which is the result.

## Approach
1. Initialize an empty stack.
2. Traverse through each token in the input array.
3. If the token is an operand, push it onto the stack.
4. If the token is an operator, pop the top two elements from the stack, apply the operator, and push the result back onto the stack.
5. After processing all tokens, the result will be the only element left in the stack.

## Code

    def evaluate_postfix(expression):
    # Initialize an empty stack
    stack = []

    # Define a set of operators
    operators = set(['+', '-', '*', '/'])

    # Traverse through each token in the expression
    for token in expression:
        if token not in operators:
            # If the token is an operand, push it onto the stack
            stack.append(int(token))
        else:
            # If the token is an operator, pop two elements from the stack
            A = stack.pop()
            B = stack.pop()

            # Perform the operation and push the result back onto the stack
            if token == '+':
                stack.append(B + A)
            elif token == '-':
                stack.append(B - A)
            elif token == '*':
                stack.append(B * A)
            elif token == '/':
                # Use integer division for consistency
                stack.append(int(B / A))

    # The result will be the only element left in the stack
    return stack.pop()

