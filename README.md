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

#Parse From Command Line
To parse an expression from the command line you can have this code in main.c
```c
  Stack *operationStack = initWithOperand(0);
  Stack *operandStack = initWithOperand(0);
  
  //If on XCode: 
  //Change command line args from Product -> Scheme -> Edit Scheme then Arguments
  parseCommandlineArgs(argc, argv, &operationStack, &operandStack);
  
  printf("\n%f\n", calculate(&operationStack, &operandStack));
```

#Parsing Polish Notations
The feature of parsing polish notations exists as well, if you are not familiar with
polish notations you can read more about them here: [Polish Notations](https://en.wikipedia.org/wiki/Polish_notation)
In the applications current state the Stack has to be reversed before it can be correctly calculated,
reason behind it is the Stack data structure which is being used during the parsing phase.
```c
  Stack *operationStack = initWithOperand(0);
  
  parsePolishNotation("+ 3 4", 10, &operationStack);
  
  reverseStack(&operationStack);
  
  printf("\n%f\n", calculatePolishNotation(&operationStack));
```

#Todo:
Right now there is no added unary operations to the parser. The functionality to calculate using Unary
Operations and Constants is there, there is just no known Constants and unary operations added to the
application.
I have sometimes experienced bugs with the reverseStack function for the Stack data structure. Where 
after using it the display function results in an endless loop.
Recently when i have tried compiling there has been no bugs so i have not found anything more about it.
If you find any bugs please report them as issues for this repo.
