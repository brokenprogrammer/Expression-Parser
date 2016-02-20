# Expression-Parser
An Expression parser written in C capable of parsing advanced math expressions.
The Expression Parser supports parsing normal math expressions, parsing math expressions
from the command line arguments and parsing math expressions in the form of Polish Notations.

#Parsing Math Expressions
To parse normal math expressions like 15 + 25 you can simply do it by initializing 
two Stacks and then call the parseExpression function together with the string to parse.
```c
  Stack *operationStack = initWithOperand(0);
  Stack *operandStack = initWithOperand(0);
    
  parseExpression("15 +15-20 + 20", 10, &operationStack, &operandStack);
  
  printf("\n%f\n", calculate(&operationStack, &operandStack));
```

#Parsing Polish Notations
The feature of parsing polish notations exists as well, if you are not familiar with
polish notations you can read more about them here: [Polish Notations](https://en.wikipedia.org/wiki/Polish_notation)
In the applications current state the Stack has to be reversed before it can be correctly calculated,
reason behind it is the Stack data structure which is being used during the parsing phase.
```c
  Stack *operationStack = initWithOperand(0);
  
  parsePolishNotation("+ - + 15 15 20 20", 10, &operationStack);
  
  reverseStack(&operationStack);
  
  printf("\n%f\n", calculatePolishNotation(&operationStack));
```
