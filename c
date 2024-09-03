#include <stdio.h>

int maximizeTopElement(int N, int stack[], int K) 
{
    if (N < K) 
    {
        return -1; // if number element is greater than number of operator return -1
    }

    // Finding the Maximum value of number
    int max_element = stack[0];
    for (int i = 1; i < N; i++) 
    {
        if (stack[i] > max_element) 
        {
            max_element = stack[i];
        }
    }

    // Checking the operator for first two variable
    stack[0] = -1; // poping out the first value
    stack[N - 1] = max_element; // pushing the first value in the stack
    stack[0] = -1; // poping out second variable

    // Find the new maximum element value
    max_element = stack[1]; // Start with the second element
    for (int i = 2; i < N - 1; i++) 
    {
        if (stack[i] > max_element) 
        {
            max_element = stack[i];
        }
    }
return max_element; // Return the maximum element after the operations.
}

int main() 
{
    int N, K;
    printf("Enter the number of Elements in stack and Number of Operations: ");
    scanf("%d %d", &N, &K);
    int stack[N];
printf("Input the elements of the stack: ");
    // enter  the elements in the  stack
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &stack[i]);
    }

    int result = maximizeTopElement(N, stack, K);
    printf("%d\n", result); // Print the result

    return 0;
}
