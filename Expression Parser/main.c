//
//  main.c
//  Expression Parser
//
//  Created by Oskar Mendel on 2/2/16.
//  Copyright © 2016 Oskar Mendel. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "Stack.h"

int main(int argc, const char * argv[]) {
    // insert code here....
    printf("Hello, World!\n");
    
    Stack *root = Init(5);
    
    push(&root, 10);
    push(&root, 15);
    push(&root, 20);
    
    Display(root);
    
    printf("Popping top of the stack: %i\n", pop(&root));
    printf("Popping top of the stack: %i\n", pop(&root));
    
    Display(root);
    
    return 0;
}
