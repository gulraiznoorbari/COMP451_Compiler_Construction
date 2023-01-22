#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack1[25];
char stack2[25];

// these pointers will always point to the top of stack
int stop1 = -1;
int stop2 = -1;

void push1(char data)
{
    stop1++;
    stack1[stop1] = data;
}

void push2(char data)
{
    stop2++;
    stack2[stop2] = data;
}

char pop1()
{
    char data = stack1[stop1];
    stack1[stop1] = '\0';
    stop1--;
    return data;
}

char pop2()
{
    char data = stack2[stop2];
    stack2[stop2] = '\0';
    stop2--;
    return data;
}

// return top of stacks:
char peek1()
{
    return stack1[stop1];
}

char peek2()
{
    return stack2[stop2];
}

char parse_table[4][4][5] = {
    {"Aa", "Aa", "Aa", ""},
    {"BD", "BD", "BD", ""},
    {"", "b", "^", "^"},
    {"^", "", "d", ""}};

int get_non_terminal_index(char non_terminal)
{
    switch (non_terminal)
    {
    case 'S':
        return 0;
    case 'A':
        return 1;
    case 'B':
        return 2;
    case 'D':
        return 3;
    default:
        return -1;
    }
}

int get_terminal_index(char terminal)
{
    switch (terminal)
    {
    case 'a':
        return 0;
    case 'b':
        return 1;
    case 'd':
        return 2;
    case '$':
        return 3;
    default:
        return -1;
    }
}

void main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid Number of Arguments");
        exit(0);
    }
    char *input = argv[1];

    printf("\nLL(1) Parser for the following grammar: \n");
    printf("S -> A a\nA -> B D\nB -> b | ^\nD -> d | ^\n");
    printf("'^' stands for epsilon\n");

    push1('$');
    push1('S');

    int length = strlen(input);
    if (input[length - 1] != '$')
    {
        printf("\nInvalid Input: Sentinel Symbol($) is missing!\n");
        exit(0);
    }
    for (int i = length - 1; i >= 0; i--)
    {
        push2(input[i]);
    }
    for (int i = 0; i < length - 1; i++)
    {
        if (!isalpha(input[i]))
        {
            printf("\nInvalid Input: Input must be a string of alphabets (with last character $)\n");
            exit(0);
        }
    }

    printf("\n***STACK IMPLEMENTATION TABLE***\n");
    printf("\nStack-1\t\tStack-2\t\tAction\n");
    printf("---------------------------------------\n");

    while (peek1() != '$' && peek2() != '$')
    {
        if (isupper(peek1()))
        {
            char non_terminal = peek1();
            int non_terminal_index = get_non_terminal_index(non_terminal);
            if (non_terminal_index == -1)
            {
                printf("Invalid Stack Symbol: %c", non_terminal);
                exit(0);
            }

            char terminal = peek2();
            int terminal_index = get_terminal_index(terminal);
            if (terminal_index == -1)
            {
                printf("Invalid Stack Symbol: %c", terminal);
                exit(0);
            }

            char *production = parse_table[non_terminal_index][terminal_index];
            if (strcmp(production, "") == 0)
            {
                printf("\nInvalid Input: No production rule found for %c -> %c\n", peek1(), peek2());
                exit(0);
            }
            else
            {
                printf("%s\t\t%s\t\t%c -> %s\n", stack1, stack2, non_terminal, production);
                pop1();
                if (strcmp(production, "^") != 0)
                {
                    for (int i = strlen(production) - 1; i >= 0; i--)
                    {
                        push1(production[i]);
                    }
                }
            }
        }
        else if (peek1() == peek2())
        {
            pop1();
            pop2();
            printf("%s\t\t%s\t\t\n", stack1, stack2);
        }
        else
        {
            printf("\nInvalid Input: %c != %c\n", peek1(), peek2());
            break;
        }
    }
    if (peek1() == '$' && peek2() == '$')
    {
        printf("String Accepted!\n");
    }
    else
    {
        printf("String Rejected!\n");
    }
}
