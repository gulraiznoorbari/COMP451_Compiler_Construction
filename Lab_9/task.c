#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack1[25];
char stack2[25];
char stack3[25];

// these pointers will always point to the top of stack:
int spointer1 = -1;
int spointer2 = -1;
int spointer3 = -1;

int getPrecedence(char c)
{
    switch (c)
    {
    case 'i': // identifier
        return 4;
    case '*':
        return 3;
    case '+':
        return 2;
    case '$':
        return 1;
    }
}

void push1(char data)
{
    spointer1 = spointer1 + 1;
    stack1[spointer1] = data;
}

void push2(char data)
{
    spointer2 = spointer2 + 1;
    stack2[spointer2] = data;
}

void push3(char data)
{
    spointer3 = spointer3 + 1;
    stack3[spointer3] = data;
}

char pop1()
{
    char data = stack1[spointer1];
    stack1[spointer1] = '\0';
    spointer1 = spointer1 - 1;
    return data;
}

char pop2()
{
    char data = stack2[spointer2];
    stack2[spointer2] = '\0';
    spointer2 = spointer2 - 1;
    return data;
}

// returns top of stack1
char peek1()
{
    return stack1[spointer1];
}

// returns top of stack2
char peek2()
{
    return stack2[spointer2];
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid number of arguments\n");
        exit(0);
    }
    char *input = argv[1];
    char x;
    char y;
    printf("Operator Precedence Parser for the following grammar: \n");
    printf("\nE -> E + E\nE -> E * E\nE -> id\n");

    push1('$');
    for (int i = strlen(input) - 1; i >= 0; i--)
    {
        push2(input[i]);
    }

    printf("\n***OPERATOR PRECEDENCE PARSER***\n");
    printf("\nStack1\t\tStack2\t\tAction\t\tStack3\n");
    printf("------------------------------------------------------------\n");
    printf("%s\t\t%s\t\t%s\t\t%s\n", stack1, stack2, "None", "Empty");

    while (1)
    {
        if (isalnum(stack2[spointer2]))
        {
            x = pop2();
            push1(x);
            printf("%s\t\t%s\t\t%s\t\t%s\n", stack1, stack2, "Push", stack3);
        }
        if (!isalnum(stack2[spointer2]))
        {
            while (getPrecedence(peek1()) > getPrecedence(peek2()))
            {
                push3(pop1());
                printf("%s\t\t%s\t\t%s\t\t%s\n", stack1, stack2, "Pop", stack3);
                while (getPrecedence(peek1()) > getPrecedence(peek2()))
                {
                    push3(pop1());
                    printf("%s\t\t%s\t\t%s\t\t%s\n", stack1, stack2, "Pop", stack3);
                }
            }
            while (getPrecedence(peek1()) < getPrecedence(peek2()))
            {
                push1(pop2());
                printf("%s\t\t%s\t\t%s\t\t%s\n", stack1, stack2, "Push", stack3);
                while (getPrecedence(peek1()) > getPrecedence(peek2()))
                {
                    push3(pop1());
                    printf("%s\t\t%s\t\t%s\t\t%s\n", stack1, stack2, "Pop", stack3);
                }
            }
            while (getPrecedence(peek1()) == getPrecedence(peek2()) && peek1() != '$' && peek2() != '$')
            {
                push3(pop1());
                printf("%s\t\t%s\t\t%s\t\t%s\n", stack1, stack2, "Pop", stack3);
                push1(pop2());
                printf("%s\t\t%s\t\t%s\t\t%s\n", stack1, stack2, "Push", stack3);
                while (getPrecedence(peek1()) < getPrecedence(peek2()))
                {
                    push1(pop2());
                    printf("%s\t\t%s\t\t%s\t\t%s\n", stack1, stack2, "Push", stack3);
                    while (getPrecedence(peek1()) > getPrecedence(peek2()))
                    {
                        push3(pop1());
                        printf("%s\t\t%s\t\t%s\t\t%s\n", stack1, stack2, "Pop", stack3);
                    }
                }
            }
        }
        if (stack1[spointer1] == '$' && stack2[spointer2] == '$')
        {
            printf("String accepted\n");
            break;
        }
        else
        {
            printf("String rejected\n");
            break;
        }
    }
}