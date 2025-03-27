#include <stdio.h>

// Function to calculate the threshold for different gates
int calculate_threshold(char gate, int size)
{
    if (gate == 'A')         // AND gate
        return size;         // All inputs must be 1
    else if (gate == 'O')    // OR gate
        return 1;            // At least one input must be 
    else if (gate == 'N')    // NAND gate
        return -(size - 1);  // Threshold for NAND is negative
    else if (gate == 'R')    // NOR gate
        return 0;            // For NOR, all inputs must be 0
    return 0;
}

// AND gate function
int and_o(int *input, int size, int *weights, int threshold)
{
    int yin = 0;
    for (int i = 0; i < size; i++)
    {
        yin += input[i] * weights[i];
    }

    return (yin >= threshold) ? 1 : 0;
}

// OR gate function
int or_o(int *input, int size, int *weights, int threshold)
{
    int yin = 0;
    for (int i = 0; i < size; i++)
    {
        yin += input[i] * weights[i];
    }

    return (yin >= threshold) ? 1 : 0;
}

// NAND gate function
int nand_o(int *input, int size, int *weights, int threshold)
{
    int yin = 0;
    for (int i = 0; i < size; i++)
    {
        yin += input[i] * weights[i];
    }
    return (yin >= threshold) ? 1 : 0;
}

// NOR gate function
int nor_o(int *input, int size, int *weights, int threshold)
{
    int yin = 0;
    for (int i = 0; i < size; i++)
    {
        yin += input[i] * weights[i];
    }

    return (yin >= threshold) ? 1 : 0;
}

// XOR gate function
int xor_o(int *input, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += input[i];
    }

    // XOR outputs 1 if the sum of 1s in the input is odd
    return (sum % 2 == 1) ? 1 : 0;
}

int main()
{
    int size;
    printf("Enter the size of the vector - ");
    scanf("%d", &size);

    int input[size];
    int weights1[size];
    int weights2[size];

    for (int i = 0; i < size; i++)
    {
        weights1[i] = 1;    // For AND/OR logic
        weights2[i] = -1;   // For NAND/NOR logic
    }

    printf("Enter the input vector - ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &input[i]);
    }

    // Calculate thresholds for each gate
    int threshold_and = calculate_threshold('A', size);
    int threshold_or = calculate_threshold('O', size);
    int threshold_nand = calculate_threshold('N', size);
    int threshold_nor = calculate_threshold('R', size);

    // Results of logic gate simulations
    printf("\nThe AND neural network : %d\n", and_o(input, size, weights1, threshold_and));
    printf("The OR neural network : %d\n", or_o(input, size, weights1, threshold_or));
    printf("The NAND neural network : %d\n", nand_o(input, size, weights2, threshold_nand));
    printf("The NOR neural network : %d\n", nor_o(input, size, weights2, threshold_nor));
    printf("The XOR neural network : %d\n", xor_o(input, size));

    return 0;
}
