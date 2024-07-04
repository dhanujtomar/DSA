# Reverse Polish Notation

> infix to PostFix

## Explaination

postfix expressions are easier for compilers to understand
in postfix expressions the operators are specified after the operands rather than between the operends

eg :
| Infix | Postfix |
| --------------- | -------------- |
| a + b \* c | a b c + \* |
| (a + b)\*(z + x) | a b + z x + \* |

## Approach

1. Initialize variables
   - character array to store variables - ans
   - Stack to store operators
2. Traverse the infix expression

   - traverse expression from beginning to end

3. push/pop operends to/from the stack 
   - if the stack is empty push the first operand
   - when the stack encounters the next opearator check its precedence ie: (+ = -) < (\* = /)
    - if the precedence of the next operator is low pop the element from the stack and push it to ans array
    - if the precedence of high then push the operator in the stack without doing any pop operations
    - Repeat step 3 until all the elements in the variables are traversed
4. No variable left to traverse
    - add the remaining elements to the ans array one by one using the pop operation

    