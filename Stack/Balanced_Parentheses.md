# Balanced Parentheses

    Check for every start if there is a end

## Approach
    if there is a '(' There should also be a ')'

## Points to note
    1. A inner bracket should end before other bracket
    ie: {[()]} is correct where as {[(])} is wrong

## Implementation
    This problem can be solved using a stack by:
        1. Store(push) every starting bracket in the stack. ie: '('
        2. On encounter with an ending bracket. ie: ')' Pop stack and check if for '(' bracket the ending bracket is ')'
                ie: if(stack.pop() == '(')
            a. If true then continue the loop
            b. If false then return false
        3. On end of the loop return true