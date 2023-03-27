#include <stdio.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n-1);
}

int main()
{
    int m, n;
    printf("Enter the order of the grid (mxn): ");
    scanf("%d %d", &m, &n);
    m--;
    n--;

    int num_paths = factorial(m+n)/(factorial(m)*factorial(n));
    printf("The total number of paths from top left to bottom right: %d\n", num_paths);
}