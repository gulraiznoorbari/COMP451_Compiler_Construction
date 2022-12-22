#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(long int num);

#define MAX_LINE_LENGTH 100
#define NUM_OF_REGS 26

// Structure to hold register names and corresponding machine code values
struct registers
{
    char *reg;
    int value;
};

// Initialize lookup table
struct registers regs[NUM_OF_REGS] = {
    {"$zero", 0},
    {"$at", 1},
    {"$v0", 2},
    {"$v1", 3},
    {"$a0", 4},
    {"$a1", 5},
    {"$a2", 6},
    {"$a3", 7},
    {"$t0", 8},
    {"$t1", 9},
    {"$t2", 10},
    {"$t3", 11},
    {"$t4", 12},
    {"$t5", 13},
    {"$t6", 14},
    {"$t7", 15},
    {"$s0", 16},
    {"$s1", 17},
    {"$s2", 18},
    {"$s3", 19},
    {"$s4", 20},
    {"$s5", 21},
    {"$s6", 22},
    {"$s7", 23},
    {"$t8", 24},
    {"$t9", 25},
};

void main(int argc, char *argv[])
{
    FILE *input_file = fopen(argv[1], "r");
    char line[MAX_LINE_LENGTH];

    if (argc != 2)
    {
        printf("Invalid Arguments!\n");
        exit(0);
    }
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL)
    {
        // Split the line into fields
        char *mnemonic = strtok(line, ", ");
        char *operand1 = strtok(NULL, ", ");
        char *operand2 = strtok(NULL, ", ");
        char *operand3 = strtok(NULL, ", ");

        if (strcmp(mnemonic, "add") == 0)
        {
            int rd;
            int rs;
            int rt;
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand1, regs[j].reg) == 0)
                {
                    rd = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand2, regs[j].reg) == 0)
                {
                    rs = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand3, regs[j].reg) == 0)
                {
                    rt = regs[j].value;
                }
            }
            int machine_code = (0 << 26) | (rs << 21) | (rt << 16) | (rd << 11) | (0b100000);
            decimalToBinary(machine_code);
            printf("\n");
        }
        if (strcmp(mnemonic, "and") == 0)
        {
            int rd;
            int rs;
            int rt;
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand1, regs[j].reg) == 0)
                {
                    rd = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand2, regs[j].reg) == 0)
                {
                    rs = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand3, regs[j].reg) == 0)
                {
                    rt = regs[j].value;
                }
            }
            int machine_code = (0 << 26) | (rs << 21) | (rt << 16) | (rd << 11) | (0b100100);
            decimalToBinary(machine_code);
            printf("\n");
        }
        if (strcmp(mnemonic, "or") == 0)
        {
            int rd;
            int rs;
            int rt;
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand1, regs[j].reg) == 0)
                {
                    rd = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand2, regs[j].reg) == 0)
                {
                    rs = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand3, regs[j].reg) == 0)
                {
                    rt = regs[j].value;
                }
            }
            int machine_code = (0 << 26) | (rs << 21) | (rt << 16) | (rd << 11) | (0b100101);
            decimalToBinary(machine_code);
            printf("\n");
        }
        if (strcmp(mnemonic, "addi") == 0)
        {
            int rt;
            int rs;
            int immediate = atoi(operand3);
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand1, regs[j].reg) == 0)
                {
                    rt = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand2, regs[j].reg) == 0)
                {
                    rs = regs[j].value;
                }
            }
            int machine_code = (0b001000 << 26) | (rs << 21) | (rt << 16) | (immediate & 0xffff);
            decimalToBinary(machine_code);
            printf("\n");
        }
        if (strcmp(mnemonic, "andi") == 0)
        {
            int rt;
            int rs;
            int immediate = atoi(operand3);
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand1, regs[j].reg) == 0)
                {
                    rt = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand2, regs[j].reg) == 0)
                {
                    rs = regs[j].value;
                }
            }
            int machine_code = (0b001100 << 26) | (rs << 21) | (rt << 16) | (immediate & 0xffff);
            decimalToBinary(machine_code);
            printf("\n");
        }
        if (strcmp(mnemonic, "ori") == 0)
        {
            int rt;
            int rs;
            int immediate = atoi(operand3);
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand1, regs[j].reg) == 0)
                {
                    rt = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand2, regs[j].reg) == 0)
                {
                    rs = regs[j].value;
                }
            }
            int machine_code = (0b001101 << 26) | (rs << 21) | (rt << 16) | (immediate & 0xffff);
            decimalToBinary(machine_code);
            printf("\n");
        }
        if (strcmp(mnemonic, "sw") == 0)
        {
            int rt;
            int rs;
            int immediate = atoi(operand3);
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand1, regs[j].reg) == 0)
                {
                    rt = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand2, regs[j].reg) == 0)
                {
                    rs = regs[j].value;
                }
            }
            int machine_code = (0b101011 << 26) | (rs << 21) | (rt << 16) | (immediate & 0xffff);
            decimalToBinary(machine_code);
            printf("\n");
        }
        if (strcmp(mnemonic, "lw") == 0)
        {
            int rt;
            int rs;
            int immediate = atoi(operand3);
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand1, regs[j].reg) == 0)
                {
                    rt = regs[j].value;
                }
            }
            for (int j = 0; j < NUM_OF_REGS; j++)
            {
                if (strcmp(operand2, regs[j].reg) == 0)
                {
                    rs = regs[j].value;
                }
            }
            int machine_code = (0b100011 << 26) | (rs << 21) | (rt << 16) | (immediate & 0xffff);
            decimalToBinary(machine_code);
            printf("\n");
        }
    }
    fclose(input_file);
    exit(0);
}

void decimalToBinary(long int num)
{
    long int mask;
    int i;

    for (i = 31; i >= 0; i--)
    {
        mask = 1 << i;
        if (num & mask)
            printf("1");
        else
            printf("0");
    }
}