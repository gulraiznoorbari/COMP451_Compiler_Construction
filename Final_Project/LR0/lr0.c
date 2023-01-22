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

char parse_table[7][7][7] = {
    {"s3", "s3", ""},
    {"", "", "Accept"},
    {"s3", "s4", ""},
    {"s3", "s4", ""},
    {"r3", "r3", "r3"},
    {"r1", "r1", "r1"},
    {"r2", "r2", "r2"},
};

int goto_table[7][2] = {
    {1, 2},
    {0, 0},
    {0, 5},
    {0, 6},
    {0, 0},
    {0, 0},
    {0, 0},
};

int get_non_terminal_index(char non_terminal)
{
    switch (non_terminal)
    {
    case 'E':
        return 0;
    case 'B':
        return 1;
    default:
        return -1;
    }
}

int get_terminal_index(char terminal)
{
    switch (terminal)
    {
    case 'c':
        return 0;
    case 'd':
        return 1;
    case '$':
        return 1;
    default:
        return -1;
    }
}

int get_goto_index(char goto_state)
{
    switch (goto_state)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
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
    printf("\nLR(0) Parser for the following grammar: \n");
    printf("E -> B B\nB -> c B\nB -> d\n");

    push1('$');
    push1('0');

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
    printf("\nStack\t\tInput\t\tAction\n");
    printf("---------------------------------------\n");
    printf("%s\t\t%s\t\t%s\n", stack1, stack2, parse_table[get_goto_index(peek1())][get_terminal_index(peek2())]);

    while (peek1() != '1' && peek2() != '$')
    {

        char state = parse_table[get_goto_index(peek1())][get_terminal_index(peek2())][1];
        push1(pop2());
        push1(state);
        printf("%s\t\t%s\t\t%s\n", stack1, stack2, parse_table[get_goto_index(peek1())][get_terminal_index(peek2())]);

        state = parse_table[get_goto_index(peek1())][get_terminal_index(peek2())][1];
        push1(pop2());
        push1(state);
        printf("%s\t\t%s\t\t%s\n", stack1, stack2, parse_table[get_goto_index(peek1())][get_terminal_index(peek2())]);

        state = parse_table[get_goto_index(peek1())][get_terminal_index(peek2())][1];
        push1(pop2());
        push1(state);
        printf("%s\t%s\t\t%s\n", stack1, stack2, parse_table[get_goto_index(peek1())][get_terminal_index(peek2())]);

        pop1();
        pop1();
        char temp = peek1();
        state = goto_table[get_goto_index(temp)][get_terminal_index(peek2())];
        push1('B');
        push1(state + '0');
        printf("%s\t%s\t\t%s\n", stack1, stack2, parse_table[state][get_terminal_index(peek2())]);

        pop1();
        pop1();
        pop1();
        pop1();
        temp = peek1();
        state = goto_table[get_goto_index(temp)][get_terminal_index(peek2())];
        push1('B');
        push1(state + '0');
        printf("%s\t\t%s\t\t%s\n", stack1, stack2, parse_table[state][get_terminal_index(peek2())]);

        pop1();
        pop1();
        pop1();
        pop1();
        temp = peek1();
        state = goto_table[get_goto_index(temp)][get_terminal_index(peek2())];
        push1('B');
        push1(state + '0');
        printf("%s\t\t%s\t\t%s\n", stack1, stack2, parse_table[state][get_terminal_index(peek2())]);

        state = parse_table[get_goto_index(peek1())][get_terminal_index(peek2())][1];
        push1(pop2());
        push1(state);
        printf("%s\t\t%s\t\t%s\n", stack1, stack2, parse_table[get_goto_index(peek1())][get_terminal_index(peek2())]);

        pop1();
        pop1();
        temp = peek1();
        state = goto_table[get_goto_index(temp)][get_terminal_index(peek2())];
        push1('B');
        push1(state + '0');
        printf("%s\t\t%s\t\t%s\n", stack1, stack2, parse_table[state][get_terminal_index(peek2())]);

        state = parse_table[get_goto_index(peek1())][get_terminal_index(peek2())][1];
        pop1();
        pop1();
        pop1();
        pop1();
        push1('E');
        push1(state);
        printf("%s\t\t%s\t\t%s\n", stack1, stack2, parse_table[get_goto_index(state)][get_terminal_index(peek2())]);

        break;
    }
    if (peek1() == '1' && peek2() == '$')
    {
        printf("\nString Accepted!\n");
    }
    else
    {
        printf("\nString Rejected!\n");
    }
}
